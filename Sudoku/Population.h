#pragma once
#include "Puzzle.h"

class Population
{
public:
	virtual ~Population() = 0;
	virtual bool cull(float ratio) = 0;
	virtual void newGeneration(int numChildren) = 0;
	virtual int bestFitness() const = 0;
	virtual Puzzle* bestIndividual() const = 0;

};