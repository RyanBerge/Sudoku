/*--------------------------------------------------------------------------------------------------
/	File:			GeneticAlgorithm.h
/	Last Updated:	March 13th 2017
/	Created On:		Visual Studio 2015 Community, Windows 7, C++11
/	Created By:		E. Ryan Berge, CSS 343 Section B
/
/	Description:	An interface for creating Population objects for use with the Genetic Algorithm
/					Has methods for culling the population pool and creating new generations.
/
/--------------------------------------------------------------------------------------------------*/
#pragma once
#include "PuzzleFactory.h"
#include "Reproduction.h"
#include "Fitness.h"

class Population
{
public:
	virtual void createPopulation(int initialSize, Puzzle* base) = 0;
	virtual ~Population() { };
	virtual bool cull(float ratio) = 0;
	virtual void newGeneration(int numChildren) = 0;
	virtual int bestFitness() const = 0;
	virtual Puzzle* bestIndividual() const = 0;

protected:
	PuzzleFactory* factory;
	Fitness* fitness;
};