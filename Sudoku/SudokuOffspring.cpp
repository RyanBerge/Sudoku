/*--------------------------------------------------------------------------------------------------
/	File:			Sudoku.cpp
/	Last Updated:	March 13th 2017
/	Created On:		Visual Studio 2015 Community, Windows 7, C++11
/	Created By:		E. Ryan Berge, CSS 343 Section B
/
/	Description:	An implementation of the Reproduction interface for Sudoku objects.
/
/--------------------------------------------------------------------------------------------------*/

#include <chrono>
#include <random>
#include "SudokuOffspring.h"

// Mutates the given Puzzle object by iterating through each cell and gives
// a chance based on the MUTATION_THRESHOLD constant of changing it to a 
// random new value.
// Returns: The new, mutated Puzzle.
Puzzle* SudokuOffspring::makeOffspring(Puzzle*  parent, int seed) const
{
	static thread_local std::mt19937 generator(seed);
	std::uniform_int_distribution<int> mutation(1, 100);
	std::uniform_int_distribution<int> distribution(1, 9);

	const Sudoku* puzzle = dynamic_cast<const Sudoku*>(parent);
	if (puzzle == nullptr)
		throw std::invalid_argument("Sudoku object required.");

	std::vector<std::pair<int, bool>> sudokuData = puzzle->getPuzzleData();

	for (int i = 0; i < sudokuData.size(); ++i)
	{
		if (sudokuData[i].second)
		{
			if (mutation(generator) <= MUTATION_THRESHOLD)
				sudokuData[i].first = distribution(generator);
		}
	}

	return new Sudoku(sudokuData);
}
