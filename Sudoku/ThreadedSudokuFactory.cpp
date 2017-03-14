/*--------------------------------------------------------------------------------------------------
/	File:			Sudoku.cpp
/	Last Updated:	March 13th 2017
/	Created On:		Visual Studio 2015 Community, Windows 7, C++11
/	Created By:		E. Ryan Berge, CSS 343 Section B
/
/	Description:	A multi-threaded implementation of the PuzzleFactory interface for Sudoku objects.
/
/--------------------------------------------------------------------------------------------------*/

#include "ThreadedSudokuFactory.h"

ThreadedSudokuFactory::ThreadedSudokuFactory(Reproduction* reproduction)
{
	this->reproduction = dynamic_cast<ThreadedSudokuOffspring*>(reproduction);
	if (this->reproduction == nullptr)
		throw std::invalid_argument("ThreadedSudokuOffspring object required.");
}

ThreadedSudokuFactory::~ThreadedSudokuFactory()
{
	if (reproduction != nullptr)
		delete reproduction;
	reproduction = nullptr;

	
}

//Uses the system time plus the seed modifier to define a randomization seed, then either
//delegates down to the Reproduction object for a mutated puzzle or creates a 
//non-mutation randomized Sudoku puzzle.
//Returns: The new puzzle.
Puzzle* ThreadedSudokuFactory::createPuzzle(Puzzle*  parent, bool mutation, int seedModifier) const
{
	int seed = clock() + seedModifier;

	if (mutation)
		return reproduction->makeOffspring(parent, seed);

	static thread_local std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distribution(1, 9);

	const Sudoku* puzzle = dynamic_cast<const Sudoku*>(parent);
	if (puzzle == nullptr)
		throw std::invalid_argument("Sudoku object required.");

	std::vector<std::pair<int, bool>> sudokuData = puzzle->getPuzzleData();

	for (int i = 0; i < sudokuData.size(); ++i)
	{
		if (sudokuData[i].second)
			sudokuData[i].first = distribution(generator);
	}

	return new Sudoku(sudokuData);
}
