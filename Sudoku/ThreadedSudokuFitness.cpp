#include "ThreadedSudokuFitness.h"



ThreadedSudokuFitness::ThreadedSudokuFitness()
{
}


ThreadedSudokuFitness::~ThreadedSudokuFitness()
{
}

int loopRows(int grid[9][9], int i)
{
	int numCollisions = 0;
	for (int j = 0; j < 9; ++j)
	{
		for (int k = j + 1; k < 9; ++k)
		{
			if (grid[i][j] == grid[i][k])
				++numCollisions;
		}
	}
	return numCollisions;
}

int loopColumns(int grid[9][9], int i)
{
	int numCollisions = 0;
	for (int j = 0; j < 9; ++j)
	{
		for (int k = j + 1; k < 9; ++k)
		{
			if (grid[j][i] == grid[k][i])
				++numCollisions;
		}
	}

	return numCollisions;
}

int loopBoxes(int grid[9][9], int i)
{
	int numCollisions = 0;

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

	return numCollisions;
}


int ThreadedSudokuFitness::howFit(Puzzle*  puzzle) const
{
	Sudoku sudoku = *(dynamic_cast<const Sudoku*>(puzzle));

	int numCollisions = 0;
	int grid[9][9];

	int index = 0;

	//std::vector<std::async> threads(9);

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
		numCollisions += std::async(loopRows, grid, i).get();
	}

	for (int i = 0; i < 9; ++i)
	{
		numCollisions += std::async(loopColumns, grid, i).get();
	}

	for (int i = 0; i < 9; i += 3)
	{
		numCollisions += std::async(loopBoxes, grid, i).get();
	}
	return numCollisions;
}
