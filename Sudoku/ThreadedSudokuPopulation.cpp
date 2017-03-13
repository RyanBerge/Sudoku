#include "SudokuPopulation.h"
#include "ThreadedSudokuPopulation.h"

ThreadedSudokuPopulation::ThreadedSudokuPopulation(PuzzleFactory* factory, Fitness* fitness)
{
	this->factory = factory;
	this->fitness = fitness;
}

ThreadedSudokuPopulation::~ThreadedSudokuPopulation()
{
	if (factory != nullptr)
	{
		delete factory;
		factory = nullptr;
	}
	if (fitness != nullptr)
	{
		delete fitness;
		fitness = nullptr;
	}

	while (!generation.empty())
	{
		Puzzle* temp = generation.top();
		generation.pop();
		if (temp != nullptr)
		{
			delete temp;
			temp = nullptr;
		}
	}
}

void ThreadedSudokuPopulation::createPopulation(int initialSize, Puzzle* base)
{
	std::vector<std::thread> threads(initialSize);
	for (int i = 0; i < initialSize; ++i)
	{
		threads[i] = std::thread(&ThreadedSudokuPopulation::threadedAddNewPuzzle, this, base, false, i);
	}

	for (int i = 0; i < initialSize; ++i)
	{
		threads[i].join();
	}
}

bool ThreadedSudokuPopulation::cull(float ratio)
{
	if (ratio < 0 || ratio > 1)
		return false;

	unsigned numToKeep = generation.size() - (int)(generation.size() * ratio);

	std::vector<Puzzle*> survivors;

	for (int i = 0; i < numToKeep; ++i)
	{
		survivors.push_back(generation.top());
		generation.pop();
	}

	while (!generation.empty())
	{
		Puzzle* temp = generation.top();
		generation.pop();
		if (temp != nullptr)
			delete temp;
		temp = nullptr;
	}

	for (int i = 0; i < survivors.size(); ++i)
	{
		generation.push(survivors[i]);
	}

	return true;
}

void ThreadedSudokuPopulation::newGeneration(int numChildren)
{
	std::vector<Puzzle*> survivors;

	while (!generation.empty())
	{
		survivors.push_back(generation.top());
		generation.pop();
	}

	std::vector<std::thread> threads(survivors.size() * numChildren);

	int index = 0;
	for (int i = 0; i < survivors.size(); ++i)
	{
		for (int j = 0; j < numChildren; ++j)
		{
			threads[index++] = std::thread(&ThreadedSudokuPopulation::threadedAddNewPuzzle, this, survivors[i], true, i * j);
		}
	}

	for (int i = 0; i < threads.size(); ++i)
	{
		threads[i].join();
	}
}

int ThreadedSudokuPopulation::bestFitness() const
{
	return generation.top()->getFitness();
}

Puzzle* ThreadedSudokuPopulation::bestIndividual() const
{
	return generation.top();
}

void ThreadedSudokuPopulation::safeGenerationPush(Puzzle* puzzle)
{
	lock.lock();
	generation.push(puzzle);
	lock.unlock();
}

void ThreadedSudokuPopulation::threadedAddNewPuzzle(Puzzle* base, bool mutation, int seedModifier)
{
	std::stringstream ss;
	ss << std::this_thread::get_id();
	uint64_t id = std::stoull(ss.str());

	Puzzle* puzzle = factory->createPuzzle(base, mutation, id);
	puzzle->setFitness(fitness->howFit(puzzle));
	safeGenerationPush(puzzle);
}
