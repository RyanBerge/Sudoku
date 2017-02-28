#include "SudokuFactory.h"

SudokuFactory::SudokuFactory(Reproduction* reproduction)
{
	this->reproduction = dynamic_cast<SudokuOffspring*>(reproduction);
	if (this->reproduction == nullptr)
		throw std::invalid_argument("SudokuOffspring object required.");
}

Puzzle* SudokuFactory::createPuzzle(const Puzzle& parent, bool mutation) const
{
	if (mutation)
		return reproduction->makeOffspring(parent);

	const Sudoku* puzzle = dynamic_cast<const Sudoku*>(&parent);
	if (puzzle == nullptr)
		throw std::invalid_argument("Sudoku object required.");

	std::vector<std::pair<int, bool>> sudokuData = puzzle->getPuzzleData();

	for (int i = 0; i < sudokuData.size(); ++i)
	{
		if (sudokuData[i].second)
			sudokuData[i].first = rand() % 9 + 1;
	}

	return new Sudoku(sudokuData);
}
