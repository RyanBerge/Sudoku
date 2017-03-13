#include "SudokuFitness.h"

int SudokuFitness::howFit(Puzzle*  puzzle) const
{
	Sudoku sudoku = *(dynamic_cast<const Sudoku*>(puzzle));

	int numCollisions = 0;
	int grid[9][9];

	int index = 0;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			grid[i][j] = sudoku.getPuzzleData()[index].first;
			++index;
		}
	}

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			for (int k = j + 1; k < 9; ++k)
			{
				if (grid[i][j] == grid[i][k])
					++numCollisions;
			}
		}
	}

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			for (int k = j + 1; k < 9; ++k)
			{
				if (grid[j][i] == grid[k][i])
					++numCollisions;
			}
		}
	}

	for (int i = 0; i < 9; i += 3)
	{
		for (int j = 0; j < 9; j += 3)
		{
			int boxStartX = i;
			int boxStartY = j;

			int box[9];
			int temp = 0;
			for (int x = boxStartX; x < boxStartX + 3; ++x)
			{
				for (int y = boxStartY; y < boxStartY + 3; ++y)
				{
					box[temp] = grid[x][y];
					++temp;
				}
			}
			for (int k = 0; k < 9; ++k)
			{
				for (int l = k + 1; l < 9; ++l)
				{
					if (box[k] == box[l])
						++numCollisions;
				}

			}
		}
	}
	return numCollisions;
}

int SudokuFitness::getBoxStart(int i) const
{
	int boxNum = 0;
	if (i < 27)
	{
		if (i % 9 < 3)
			boxNum = 1;
		else if (i % 9 < 6)
			boxNum = 2;
		else
			boxNum = 3;
	}
	else if (i < 54)
	{
		if (i % 9 < 3)
			boxNum = 4;
		else if (i % 9 < 6)
			boxNum = 5;
		else
			boxNum = 6;
	}
	else
	{
		if (i % 9 < 3)
			boxNum = 7;
		else if (i % 9 < 6)
			boxNum = 8;
		else
			boxNum = 9;
	}

	int boxStart = -1;

	switch (boxNum)
	{
	case 1: return 0;
	case 2: return 3;
	case 3: return 6;
	case 4: return 27;
	case 5: return 30;
	case 6: return 33;
	case 7: return 54;
	case 8: return 57;
	case 9: return 60;

	default:
		return -1;
		break;
	}

}
