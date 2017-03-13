#pragma once
#include "SudokuPopulation.h"
#include "SudokuFitness.h"
#include "ThreadedSudokuPopulation.h"
#include "SudokuOffspring.h"
#include "SudokuFactory.h"

class GeneticAlgorithm
{
public:
	GeneticAlgorithm(std::string puzzleType, int initialPopulation, Puzzle* base);
	void Iterate(float cullRatio, int numChildren);
	void PrintBestSolution(std::ostream& sout);

private:
	Population* population;
};