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