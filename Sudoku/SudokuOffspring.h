#pragma once
#include "Reproduction.h"

class SudokuOffspring : public Reproduction
{
public:
	// Inherited via Reproduction
	virtual Puzzle* makeOffspring(const Puzzle* puzzle) const override;

};