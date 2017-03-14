#pragma once
#include "Sudoku.h"

class PuzzleFactory
{
public:
	virtual ~PuzzleFactory() { }
	virtual Puzzle* createPuzzle(Puzzle*  parent, bool mutation, int seedModifier) const = 0;

};