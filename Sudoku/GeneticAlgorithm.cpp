#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(std::string puzzleType, int initialPopulation, const Puzzle& base)
{
	if (puzzleType == "Sudoku")
	{
		population = new SudokuPopulation(new SudokuFactory(new SudokuOffspring()), new SudokuFitness());
		population->createPopulation(initialPopulation, base);
	}
}

void GeneticAlgorithm::Iterate(float cullRatio, int numChildren)
{
	population->cull(cullRatio);
	population->newGeneration(numChildren);
}

void GeneticAlgorithm::PrintBestSolution(std::ostream & sout)
{
	population->bestIndividual()->PrintPuzzle(sout);
	sout << std::endl << "Puzzle has a fitness of: " << population->bestFitness() << std::endl;
}
