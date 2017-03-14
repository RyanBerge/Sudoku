/*--------------------------------------------------------------------------------------------------
/	File:			Sudoku.cpp
/	Last Updated:	March 13th 2017
/	Created On:		Visual Studio 2015 Community, Windows 7, C++11
/	Created By:		E. Ryan Berge, CSS 343 Section B
/
/	Description:	A multi-threaded implementation of the PuzzleFactory interface for Sudoku objects.
/
/--------------------------------------------------------------------------------------------------*/
#pragma once
#include <random>
#include <chrono>
#include "ThreadedSudokuOffspring.h"
#include "PuzzleFactory.h"

class ThreadedSudokuFactory : public PuzzleFactory
{
public:
	ThreadedSudokuFactory(Reproduction* reproduction);

	// Inherited via PuzzleFactory
	virtual ~ThreadedSudokuFactory();
	virtual Puzzle* createPuzzle(Puzzle* parent, bool mutation, int seedModifier) const override;

private:
	ThreadedSudokuOffspring* reproduction;

};