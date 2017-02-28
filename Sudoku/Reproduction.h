#pragma once
#include "Puzzle.h"

class Reproduction
{
public:
	virtual Puzzle* makeOffspring(const Puzzle* puzzle) const = 0;
};