/*--------------------------------------------------------------------------------------------------
/	File:			GeneticAlgorithm.h
/	Last Updated:	March 13th 2017
/	Created On:		Visual Studio 2015 Community, Windows 7, C++11
/	Created By:		E. Ryan Berge, CSS 343 Section B
/
/	Description:	Implements generic Genetic algorithm techniques of mutation and population
/					culling and spawning.  Creates implementation for Sudoku objects.
/
/--------------------------------------------------------------------------------------------------*/

#pragma once
#include "SudokuPopulation.h"
#include "SudokuOffspring.h"
#include "SudokuFactory.h"

#include "ThreadedSudokuPopulation.h"
#include "ThreadedSudokuOffspring.h"
#include "ThreadedSudokuFactory.h"

#include "SudokuFitness.h"

class GeneticAlgorithm
{
public:
	GeneticAlgorithm(std::string puzzleType, int initialPopulation, Puzzle* base);
	~GeneticAlgorithm();
	void Iterate(float cullRatio, int numChildren);
	void PrintBestSolution(std::ostream& sout) const;
	int GetBestFitness() const;

private:
	Population* population;
};