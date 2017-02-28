#pragma once
#include "Reproduction.h"
#include "Sudoku.h"

#define MUTATION_THRESHOLD 5

class SudokuOffspring : public Reproduction
{
public:
	// Inherited via Reproduction
	virtual Puzzle* makeOffspring(const Puzzle& parent) const override;

};