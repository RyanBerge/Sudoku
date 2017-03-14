/*--------------------------------------------------------------------------------------------------
/	File:			Sudoku.cpp
/	Last Updated:	March 13th 2017
/	Created On:		Visual Studio 2015 Community, Windows 7, C++11
/	Created By:		E. Ryan Berge, CSS 343 Section B
/
/	Description:	A multi-threaded implementation of the Population interface for Sudoku objects.
/
/--------------------------------------------------------------------------------------------------*/

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

// Uses the PuzzleFactory object and the Fitness objects to create an initial
// random population of Sudoku Puzzles.  Spawns a new thread for the creation of
// each Puzzle.
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

// Eliminates the X% worst puzzles in the current population, where X is equal
// to the culling ratio.
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

// Creates a new generation of Puzzles by mutating each puzzle in the 
// current generation a number of times equal to numChildren.  Spawns
// a new thread for each Puzzle to be created.
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

	for (int i = 0; i < survivors.size(); ++i)
	{
		delete survivors[i];
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

// Safely locks the population container for when Puzzles need to be pushed.
void ThreadedSudokuPopulation::safeGenerationPush(Puzzle* puzzle)
{
	lock.lock();
	generation.push(puzzle);
	lock.unlock();
}

// The function used by the extra threads for creating new puzzles.
void ThreadedSudokuPopulation::threadedAddNewPuzzle(Puzzle* base, bool mutation, int seedModifier)
{
	std::stringstream ss;
	ss << std::this_thread::get_id();
	int id = std::stoull(ss.str());

	Puzzle* puzzle = factory->createPuzzle(base, mutation, id);
	puzzle->setFitness(fitness->howFit(puzzle));
	safeGenerationPush(puzzle);
}
