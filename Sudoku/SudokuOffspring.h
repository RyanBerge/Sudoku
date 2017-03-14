#pragma once
#include "Reproduction.h"
#include "Sudoku.h"

#define MUTATION_THRESHOLD 1

class SudokuOffspring : public Reproduction
{
public:
	// Inherited via Reproduction
	virtual Puzzle* makeOffspring(Puzzle*  parent, int seed) const override;

};