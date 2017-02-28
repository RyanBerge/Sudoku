#pragma once
#include "Puzzle.h"

class PuzzleFactory
{
public:
	virtual Puzzle* createPuzzle() = 0;
};