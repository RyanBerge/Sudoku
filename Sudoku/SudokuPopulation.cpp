#include "SudokuPopulation.h"

SudokuPopulation::SudokuPopulation(PuzzleFactory* factory, Fitness* fitness)
{
	this->factory = factory;
	this->reproduction = reproduction;
	this->fitness = fitness;
}

SudokuPopulation::~SudokuPopulation()
{
}

bool SudokuPopulation::cull(float ratio)
{
	return false;
}

void SudokuPopulation::newGeneration(int numChildren)
{
	while (!generation.empty())
	{
		survivers.push_back(generation.top());
		generation.pop();
	}

	for (int i = 0; i < survivers.size(); ++i)
	{
		for (int j = 0; j < numChildren; ++j)
		{
			Puzzle* newPuzzle;
			newPuzzle = reproduction->makeOffspring(survivers[i]);
			newPuzzle->setFitness(fitness->howFit(newPuzzle));
			generation.push(newPuzzle);
		}
	}
}

int SudokuPopulation::bestFitness() const
{
	return 0;
}

Puzzle * SudokuPopulation::bestIndividual() const
{
	return nullptr;
}
