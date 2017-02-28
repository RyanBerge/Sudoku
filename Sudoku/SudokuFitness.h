#pragma once
#include "Fitness.h"

class SudokuFitness : public Fitness
{
public:
	// Inherited via Fitness
	virtual int howFit(const Puzzle* puzzle) const override;

};