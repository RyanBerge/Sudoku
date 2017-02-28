#pragma once
#include<iostream>

class Puzzle
{
public:
	virtual bool ReadPuzzle(std::istream& sin) = 0;
	virtual void PrintPuzzle(std::ostream& sout) const = 0;
	virtual void setFitness(const int fitness) = 0;
	virtual int getFitness() const = 0;

	virtual bool operator==(const Puzzle& other) const = 0;
	virtual bool operator!=(const Puzzle& other) const = 0;

	virtual bool operator<(const Puzzle& other) const = 0;
	virtual bool operator>(const Puzzle& other) const = 0;
	virtual bool operator<=(const Puzzle& other) const = 0;
	virtual bool operator>=(const Puzzle& other) const = 0;

};

class PuzzleLessComparator
{
public:
	bool operator()(Puzzle* left, Puzzle* right) { return (*left > *right); }
};