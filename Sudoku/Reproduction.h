#pragma once
#include "Puzzle.h"

class Reproduction
{
public:
	virtual Puzzle* makeOffspring(Puzzle*  puzzle, int seed) const = 0;
};