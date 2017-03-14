/*--------------------------------------------------------------------------------------------------
/	File:			Sudoku.cpp
/	Last Updated:	March 13th 2017
/	Created On:		Visual Studio 2015 Community, Windows 7, C++11
/	Created By:		E. Ryan Berge, CSS 343 Section B
/
/	Description:	A multi-threaded implementation of the Reproduction interface for Sudoku objects.
/
/--------------------------------------------------------------------------------------------------*/

#pragma once
#include "Reproduction.h"
#include "Sudoku.h"

#define MUTATION_THRESHOLD 1

class ThreadedSudokuOffspring : public Reproduction
{
public:
	// Inherited via Reproduction
	virtual Puzzle* makeOffspring(Puzzle*  parent, int seed) const override;

};