#pragma once
#include <random>
#include <chrono>
#include "SudokuOffspring.h"
#include "PuzzleFactory.h"

class SudokuFactory : public PuzzleFactory
{
public:
	SudokuFactory(Reproduction* reproduction);

	// Inherited via PuzzleFactory
	virtual Puzzle* createPuzzle(Puzzle* parent, bool mutation, int seedModifier) const override;

private:
	SudokuOffspring* reproduction;

};