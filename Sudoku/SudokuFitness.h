#pragma once
#include "Fitness.h"
#include "Sudoku.h"

class SudokuFitness : public Fitness
{
public:
	// Inherited via Fitness
	virtual int howFit(const Puzzle& puzzle) const override;

};