#pragma once

#include "Puzzle.h"

class Sudoku : public Puzzle
{
public:
	virtual ~Sudoku();
	virtual void ReadPuzzle(std::istream& sin) = 0;
	virtual void PrintPuzzle(std::ostream& sout) const = 0;
};

std::ostream& operator<<(std::ostream& sout, const Sudoku& puzzle);
std::istream& operator>>(std::istream& sin, Sudoku& puzzle);