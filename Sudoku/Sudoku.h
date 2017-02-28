#pragma once
#include <vector>
#include "Puzzle.h"

#define PUZZLE_SIZE 81

class Sudoku : public Puzzle
{
public:
	// Inherited via Puzzle
	Sudoku() { puzzleData = std::vector<std::pair<int, bool>>(PUZZLE_SIZE); fitness = 0; }
	virtual bool ReadPuzzle(std::istream& sin) override;
	virtual void PrintPuzzle(std::ostream& sout) const override;
	virtual void setFitness(const int fitness) override;


private:
	//Where each integer represents a value in a cell and the corresponding bool
	//	indicates whether or not that cell is mutable
	std::vector<std::pair<int, bool>> puzzleData;

	int fitness;
};

std::ostream& operator<<(std::ostream& sout, const Sudoku& puzzle);
std::istream& operator>>(std::istream& sin, Sudoku& puzzle);