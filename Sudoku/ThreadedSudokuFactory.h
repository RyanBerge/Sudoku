#pragma once
#include <random>
#include <chrono>
#include "ThreadedSudokuOffspring.h"
#include "PuzzleFactory.h"

class ThreadedSudokuFactory : public PuzzleFactory
{
public:
	ThreadedSudokuFactory(Reproduction* reproduction);

	// Inherited via PuzzleFactory
	virtual ~ThreadedSudokuFactory();
	virtual Puzzle* createPuzzle(Puzzle* parent, bool mutation, int seedModifier) const override;

private:
	ThreadedSudokuOffspring* reproduction;

};