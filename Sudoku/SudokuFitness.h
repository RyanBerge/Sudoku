/*--------------------------------------------------------------------------------------------------
/	File:			Sudoku.cpp
/	Last Updated:	March 13th 2017
/	Created On:		Visual Studio 2015 Community, Windows 7, C++11
/	Created By:		E. Ryan Berge, CSS 343 Section B
/
/	Description:	An implementation of the Fitness interface for Sudoku objects.
/
/--------------------------------------------------------------------------------------------------*/
#pragma once
#include "Fitness.h"
#include "Sudoku.h"

class SudokuFitness : public Fitness
{
public:
	// Inherited via Fitness
	virtual int howFit(Puzzle*  puzzle) const override;
};