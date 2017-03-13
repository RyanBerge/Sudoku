#pragma once
#include "Fitness.h"
#include "Sudoku.h"

class SudokuFitness : public Fitness
{
public:
	// Inherited via Fitness
	virtual int howFit(Puzzle*  puzzle) const override;

private:
	int getBoxStart(int i) const;
};