/*--------------------------------------------------------------------------------------------------
/	File:			PuzzleFactory.h
/	Last Updated:	March 13th 2017
/	Created On:		Visual Studio 2015 Community, Windows 7, C++11
/	Created By:		E. Ryan Berge, CSS 343 Section B
/
/	Description:	A generic interface for creating PuzzleFactory objects, which have a single
/					method that is used for creating new Puzzle objects.
/
/--------------------------------------------------------------------------------------------------*/
#pragma once
#include "Puzzle.h"

class PuzzleFactory
{
public:
	virtual ~PuzzleFactory() { }
	virtual Puzzle* createPuzzle(Puzzle*  parent, bool mutation, int seedModifier) const = 0;

};