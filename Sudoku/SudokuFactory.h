/*--------------------------------------------------------------------------------------------------
/	File:			Sudoku.cpp
/	Last Updated:	March 13th 2017
/	Created On:		Visual Studio 2015 Community, Windows 7, C++11
/	Created By:		E. Ryan Berge, CSS 343 Section B
/
/	Description:	An implementation of the PuzzleFactory interface for Sudoku objects.
/
/--------------------------------------------------------------------------------------------------*/
#pragma once
#include <chrono>
#include <random>
#include "SudokuOffspring.h"
#include "PuzzleFactory.h"

class SudokuFactory : public PuzzleFactory
{
public:
	SudokuFactory(Reproduction* reproduction);

	// Inherited via PuzzleFactory
	virtual ~SudokuFactory();
	virtual Puzzle* createPuzzle(Puzzle* parent, bool mutation, int seedModifier) const override;

private:
	SudokuOffspring* reproduction;

};