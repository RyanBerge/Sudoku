#include <chrono>
#include <random>
#include "SudokuOffspring.h"


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
