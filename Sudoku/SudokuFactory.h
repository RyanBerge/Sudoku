#pragma once
#include "SudokuOffspring.h"
#include "PuzzleFactory.h"

class SudokuFactory : public PuzzleFactory
{
public:
	SudokuFactory(Reproduction* reproduction);

	// Inherited via PuzzleFactory
	virtual Puzzle* createPuzzle(const Puzzle* parent, bool mutation) const override;

private:
	SudokuOffspring* reproduction;

};