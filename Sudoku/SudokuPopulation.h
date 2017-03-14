/*--------------------------------------------------------------------------------------------------
/	File:			Sudoku.cpp
/	Last Updated:	March 13th 2017
/	Created On:		Visual Studio 2015 Community, Windows 7, C++11
/	Created By:		E. Ryan Berge, CSS 343 Section B
/
/	Description:	An implementation of the Population interface for Sudoku objects.
/
/--------------------------------------------------------------------------------------------------*/
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