/*--------------------------------------------------------------------------------------------------
/	File:			Sudoku.cpp
/	Last Updated:	March 13th 2017
/	Created On:		Visual Studio 2015 Community, Windows 7, C++11
/	Created By:		E. Ryan Berge, CSS 343 Section B
/
/	Description:	An implementation of the Population interface for Sudoku objects.
/
/--------------------------------------------------------------------------------------------------*/
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

// Uses the PuzzleFactory object and the Fitness objects to create an initial
// random population of Sudoku Puzzles.
void SudokuPopulation::createPopulation(int initialSize, Puzzle* base)
{
	for (int i = 0; i < initialSize; ++i)
	{
		Puzzle* puzzle = factory->createPuzzle(base, false, i);
		puzzle->setFitness(fitness->howFit(puzzle));
		generation.push(puzzle);
	}
}

// Eliminates the X% worst puzzles in the current population, where X is equal
// to the culling ratio.
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

// Creates a new generation of Puzzles by mutating each puzzle in the 
// current generation a number of times equal to numChildren.
void SudokuPopulation::newGeneration(int numChildren)
{
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
			Puzzle* temp = factory->createPuzzle(survivors[i], true, i * j);
			temp->setFitness(fitness->howFit(temp));
			generation.push(temp);
		}
		delete survivors[i];
		survivors[i] = nullptr;
	}
}

int SudokuPopulation::bestFitness() const
{
	return generation.top()->getFitness();
}

Puzzle* SudokuPopulation::bestIndividual() const
{
	return generation.top();
}
