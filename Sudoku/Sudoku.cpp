#include "Sudoku.h"

using std::endl;


//Reads the first 81 integers found in the input stream and fills the puzzleData member.
//When a non-zero integer is found, it treats that cell as immutable. Cells with a zero
//in them are treated as mutable.
//Returns: Whether or not 81 integers were found in and read from the input stream.
bool Sudoku::ReadPuzzle(std::istream& sin)
{
	char character;
	bool complete = false;
	int index = 0;
	while (!sin.eof() && !complete)
	{
		sin >> character;
		if (character >= 49 && character <= 57)
			puzzleData[index++] = std::pair<int, bool>((int)character - 48, false);
		else if (character == 48)
			puzzleData[index++] = std::pair<int, bool>((int)character - 48, true);

		if (index >= PUZZLE_SIZE)
			complete = true;
	}

	if (!complete)
		return false;
	else
		return true;
}

//Prints out the puzzle to the ostream.
void Sudoku::PrintPuzzle(std::ostream& sout) const
{
	int index = 0;
	for (int i = 0; i < 3; ++i)
	{
		sout << "+-------+-------+-------+" << endl;
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				sout << "| ";
				for (int l = 0; l < 3; ++l)
				{
					int cell = puzzleData[index++].first;
					sout << cell << " ";
				}
			}
			sout << endl;
		}
	}
}

void Sudoku::setFitness(const int fitness)
{
	this->fitness = fitness;
}

std::ostream& operator<<(std::ostream& sout, const Sudoku& puzzle)
{
	puzzle.PrintPuzzle(sout);
	return sout;
}

std::istream& operator>>(std::istream& sin, Sudoku& puzzle)
{
	puzzle.ReadPuzzle(sin);
	return sin;
}