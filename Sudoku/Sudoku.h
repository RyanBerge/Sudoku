/*--------------------------------------------------------------------------------------------------
/	File:			Sudoku.cpp
/	Last Updated:	March 13th 2017
/	Created On:		Visual Studio 2015 Community, Windows 7, C++11
/	Created By:		E. Ryan Berge, CSS 343 Section B
/
/	Description:	An implementation of the Puzzle interface for Sudoku objects.
/
/--------------------------------------------------------------------------------------------------*/
#pragma once
#include <vector>
#include "Puzzle.h"

#define PUZZLE_SIZE 81

class Sudoku : public Puzzle
{
public:
	// Inherited via Puzzle
	Sudoku();
	Sudoku(std::vector<std::pair<int, bool>> data) : puzzleData(data), fitness(-1) { }
	virtual ~Sudoku();
	virtual bool ReadPuzzle(std::istream& sin) override;
	virtual void PrintPuzzle(std::ostream& sout) const override;
	virtual void setFitness(const int fitness) override;
	virtual int getFitness() const override;

	std::vector<std::pair<int, bool>> getPuzzleData() const;

	virtual bool operator==(const Puzzle& other) const;
	virtual bool operator!=(const Puzzle& other) const;

	virtual bool operator<(const Puzzle& other) const;
	virtual bool operator>(const Puzzle& other) const;
	virtual bool operator<=(const Puzzle& other) const;
	virtual bool operator>=(const Puzzle& other) const;


private:
	//Where each integer represents a value in a cell and the corresponding bool
	//	indicates whether or not that cell is mutable
	std::vector<std::pair<int, bool>> puzzleData;

	int fitness;
};

std::ostream& operator<<(std::ostream& sout, const Sudoku& puzzle);
std::istream& operator>>(std::istream& sin, Sudoku& puzzle);