#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(std::string puzzleType, int initialPopulation, Puzzle* base)
{
	if (puzzleType == "Sudoku")
	{
		population = new SudokuPopulation(new SudokuFactory(new SudokuOffspring()), new SudokuFitness());
		//population = new ThreadedSudokuPopulation(new ThreadedSudokuFactory(new ThreadedSudokuOffspring()), new SudokuFitness());
		population->createPopulation(initialPopulation, base);
	}
}

GeneticAlgorithm::~GeneticAlgorithm()
{
	if (population != nullptr)
		delete population;
	population = nullptr;
}

void GeneticAlgorithm::Iterate(float cullRatio, int numChildren)
{
	

	population->cull(cullRatio);
	population->newGeneration(numChildren);


}

void GeneticAlgorithm::PrintBestSolution(std::ostream & sout) const
{
	population->bestIndividual()->PrintPuzzle(sout);
	sout << std::endl << "Puzzle has a fitness of: " << population->bestFitness() << std::endl;
}

int GeneticAlgorithm::GetBestFitness() const
{
	return population->bestFitness();
}
