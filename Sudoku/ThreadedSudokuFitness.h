#pragma once
#include <thread>
#include <future>
#include "Sudoku.h"
#include "Fitness.h"


class ThreadedSudokuFitness : public Fitness
{
public:
	ThreadedSudokuFitness();
	~ThreadedSudokuFitness();

	// Inherited via Fitness
	virtual int howFit(Puzzle*  puzzle) const override;
};

