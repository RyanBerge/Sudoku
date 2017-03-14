/*--------------------------------------------------------------------------------------------------
/	File:			Reproduction.h
/	Last Updated:	March 13th 2017
/	Created On:		Visual Studio 2015 Community, Windows 7, C++11
/	Created By:		E. Ryan Berge, CSS 343 Section B
/
/	Description:	An interface for creating Reproduction objects, which contain a single method
/					for mutating a Puzzle to create a new Puzzle.
/
/--------------------------------------------------------------------------------------------------*/
#pragma once
#include "Puzzle.h"

class Reproduction
{
public:
	virtual Puzzle* makeOffspring(Puzzle*  puzzle, int seed) const = 0;
};