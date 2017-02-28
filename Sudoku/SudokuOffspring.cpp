#include "SudokuOffspring.h"

Puzzle* SudokuOffspring::makeOffspring(const Puzzle& parent) const
{
	const Sudoku* puzzle = dynamic_cast<const Sudoku*>(&parent);
	if (puzzle == nullptr)
		throw std::invalid_argument("Sudoku object required.");

	std::vector<std::pair<int, bool>> sudokuData = puzzle->getPuzzleData();

	for (int i = 0; i < sudokuData.size(); ++i)
	{
		if (sudokuData[i].second)
		{
			if (rand() % 100 <= MUTATION_THRESHOLD)
				sudokuData[i].first = rand() % 9 + 1;
		}
	}

	return new Sudoku(sudokuData);
}
