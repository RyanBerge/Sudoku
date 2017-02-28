#pragma once
#include "Sudoku.h"

class PuzzleFactory
{
public:
	virtual Puzzle* createPuzzle(const Puzzle& parent, bool mutation) const = 0;
};