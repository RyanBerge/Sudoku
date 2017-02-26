#pragma once
#include "Population.h"

class SudokuPopulation : public Population
{
public:
	virtual ~SudokuPopulation();
	virtual bool cull(float ratio);
	virtual void newGeneration(int numChildren);
	virtual int bestFitness() const;
	virtual Puzzle* bestIndividual() const;

};