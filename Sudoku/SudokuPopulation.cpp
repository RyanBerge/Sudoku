#include "SudokuPopulation.h"

SudokuPopulation::SudokuPopulation(PuzzleFactory* factory, Fitness* fitness)
{
	this->factory = factory;
	this->fitness = fitness;
}

SudokuPopulation::~SudokuPopulation()
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

void SudokuPopulation::createPopulation(int initialSize, const Puzzle& base)
{
	int a = 3;
	for (int i = 0; i < initialSize; ++i)
	{
		Puzzle* puzzle = factory->createPuzzle(base, false);
		puzzle->setFitness(fitness->howFit(*puzzle));
		generation.push(puzzle);
	}
	int b = 2;
}

bool SudokuPopulation::cull(float ratio)
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

void SudokuPopulation::newGeneration(int numChildren)
{
	//std::cout << "Population Size: " << generation.size() << std::endl;
	std::vector<Puzzle*> survivors;

	while (!generation.empty())
	{
		survivors.push_back(generation.top());
		generation.pop();
	}

	for (int i = 0; i < survivors.size(); ++i)
	{
		for (int j = 0; j < numChildren; ++j)
		{
			Puzzle* temp = factory->createPuzzle(*survivors[i], true);
			temp->setFitness(fitness->howFit(*temp));
			generation.push(temp);
		}
		generation.push(survivors[i]);
	}

	//std::cout << "Population Size: " << generation.size() << std::endl;
}

int SudokuPopulation::bestFitness() const
{
	return generation.top()->getFitness();
}

Puzzle* SudokuPopulation::bestIndividual() const
{
	return generation.top();
}
