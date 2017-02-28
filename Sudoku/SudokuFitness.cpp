#include "SudokuFitness.h"

int SudokuFitness::howFit(const Puzzle& puzzle) const
{
	Sudoku sudoku = *(dynamic_cast<const Sudoku*>(&puzzle));

	int numCollisions = 0;
	
	for (int i = 0; i < 9; ++i)
	{
		int rowStart = i * 9;
		int index = 0;
		for (int j = 0; j < 9; j++)
		{
			for (int k = j + 1; k < 9; ++k)
			{
				if (sudoku.getPuzzleData()[rowStart + j].first == sudoku.getPuzzleData()[rowStart + k].first)
					++numCollisions;
			}
		}
	}
}
