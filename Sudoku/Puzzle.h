/*--------------------------------------------------------------------------------------------------
/	File:			GeneticAlgorithm.h
/	Last Updated:	March 13th 2017
/	Created On:		Visual Studio 2015 Community, Windows 7, C++11
/	Created By:		E. Ryan Berge, CSS 343 Section B
/
/	Description:	A generic interface for creating Puzzles for use with the Genetic Algorithm.
/					Provides methods for reading puzzle info from a stream, printing the puzzle
/					to a stream, and accessors for a fitness data member, as well as comparison
/					operators.
/
/					Also contains a PuzzleComparator class that looks at two Puzzle pointers and
/					compares the values contained at the memory locations (rather than comparing
/					the pointers themselves).
/
/--------------------------------------------------------------------------------------------------*/
#pragma once
#include<iostream>

class Puzzle
{
public:
	virtual ~Puzzle() { }
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

class PuzzleComparator
{
public:
	bool operator()(Puzzle* left, Puzzle* right) { return (*left > *right); }
};