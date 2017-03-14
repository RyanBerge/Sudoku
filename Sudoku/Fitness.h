/*--------------------------------------------------------------------------------------------------
/	File:			Sudoku.cpp
/	Last Updated:	March 13th 2017
/	Created On:		Visual Studio 2015 Community, Windows 7, C++11
/	Created By:		E. Ryan Berge, CSS 343 Section B
/
/	Description:	An interface for creating Fitness objects, which contain a single method
/					for evaluating the fitness of a Puzzle object.
/
/--------------------------------------------------------------------------------------------------*/
#pragma once
#include "Puzzle.h"

class Fitness
{
public:
	virtual int howFit(Puzzle*  puzzle) const = 0;
};