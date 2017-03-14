/*--------------------------------------------------------------------------------------------------
/	File:			Sudoku.cpp
/	Last Updated:	March 13th 2017
/	Created On:		Visual Studio 2015 Community, Windows 7, C++11
/	Created By:		E. Ryan Berge, CSS 343 Section B
/
/	Description:	A multi-threaded implementation of the Population interface for Sudoku objects.
/
/--------------------------------------------------------------------------------------------------*/

#pragma once
#include <queue>
#include <thread>
#include <mutex>
#include <sstream>
#include "Population.h"

class ThreadedSudokuPopulation : public Population
{
public:
	ThreadedSudokuPopulation(PuzzleFactory* factory, Fitness* fitness);
	virtual ~ThreadedSudokuPopulation();

	virtual void createPopulation(int initialSize, Puzzle* base);
	virtual bool cull(float ratio) override;
	virtual void newGeneration(int numChildren) override;
	virtual int bestFitness() const override;
	virtual Puzzle* bestIndividual() const override;

private:
	void safeGenerationPush(Puzzle* puzzle);
	void threadedAddNewPuzzle(Puzzle* base, bool mutation, int seedModifier);
	std::mutex lock;

	std::priority_queue<Puzzle*, std::vector<Puzzle*>, PuzzleComparator> generation;
};