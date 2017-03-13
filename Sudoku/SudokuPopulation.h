#pragma once
#include <queue>
#include "Population.h"

class SudokuPopulation : public Population
{
public:
	SudokuPopulation(PuzzleFactory* factory, Fitness* fitness);
	virtual ~SudokuPopulation();

	virtual void createPopulation(int initialSize, Puzzle* base);
	virtual bool cull(float ratio) override;
	virtual void newGeneration(int numChildren) override;
	virtual int bestFitness() const override;
	virtual Puzzle* bestIndividual() const override;

private:
	std::priority_queue<Puzzle*, std::vector<Puzzle*>, PuzzleComparator> generation;
};