#pragma once
#include<iostream>

class Puzzle
{
public:
	virtual ~Puzzle() = 0;
	virtual void ReadPuzzle(std::istream& sin) const = 0;
	virtual void PrintPuzzle(std::ostream& sout) const = 0;

};