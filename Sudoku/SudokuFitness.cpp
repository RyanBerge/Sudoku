/*--------------------------------------------------------------------------------------------------
/	File:			Sudoku.cpp
/	Last Updated:	March 13th 2017
/	Created On:		Visual Studio 2015 Community, Windows 7, C++11
/	Created By:		E. Ryan Berge, CSS 343 Section B
/
/	Description:	An implementation of the Fitness interface for Sudoku objects.
/
/--------------------------------------------------------------------------------------------------*/

#include "SudokuFitness.h"

//Counts the number of "collisions" in the given Sudoku object.  A 
//collision is defined as an occurance of two identical numbers
//in the same row, column, or box. If two numbers collide on the same
//row or column and the same box at the same time, it is counted twice.
//Returns: the fitness evaluation of the Puzzle.
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
