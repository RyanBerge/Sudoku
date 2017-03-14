#pragma once
#include "SudokuPopulation.h"
#include "SudokuFitness.h"
#include "ThreadedSudokuPopulation.h"
#include "ThreadedSudokuOffspring.h"
#include "ThreadedSudokuFactory.h"

class GeneticAlgorithm
{
public:
	GeneticAlgorithm(std::string puzzleType, int initialPopulation, Puzzle* base);
	void Iterate(float cullRatio, int numChildren);
	void PrintBestSolution(std::ostream& sout) const;
	int GetBestFitness() const;

private:
	Population* population;
};