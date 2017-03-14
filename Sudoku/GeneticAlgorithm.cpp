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

#include "GeneticAlgorithm.h"

//Constructs a GeneticAlgorithm object to be used with Sudoku-type puzzles.  Uses the multithreaded
//version of SudokuFactory and SudokuPopulation.
GeneticAlgorithm::GeneticAlgorithm(std::string puzzleType, int initialPopulation, Puzzle* base)
{
	if (puzzleType == "Sudoku")
	{
		//population = new SudokuPopulation(new SudokuFactory(new SudokuOffspring()), new SudokuFitness());
		population = new ThreadedSudokuPopulation(new ThreadedSudokuFactory(new ThreadedSudokuOffspring()), new SudokuFitness());
		population->createPopulation(initialPopulation, base);
	}
}

//Frees Population memory
GeneticAlgorithm::~GeneticAlgorithm()
{
	if (population != nullptr)
		delete population;
	population = nullptr;
}

//Uses the cullratio to cull the current population and then repopulate.
void GeneticAlgorithm::Iterate(float cullRatio, int numChildren)
{
	population->cull(cullRatio);
	population->newGeneration(numChildren);
}

//Prints the current best solution to the designated ostream.
void GeneticAlgorithm::PrintBestSolution(std::ostream& sout) const
{
	population->bestIndividual()->PrintPuzzle(sout);
	sout << std::endl << "Puzzle has a fitness of: " << population->bestFitness() << std::endl;
}

//Returns the fitness value of the best puzzle in the current population.
int GeneticAlgorithm::GetBestFitness() const
{
	return population->bestFitness();
}
