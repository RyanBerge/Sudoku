#include <iostream>
#include <fstream>
#include <ctime>
#include "GeneticAlgorithm.h"

#define CULL_RATIO 0.8f

using std::cout;
using std::endl;


int main(int argc, char* argv[])
{
	int initialSize = 0;
	int numGenerations = 0;
	std::string filename = "Puzzle.txt";

	if (argc < 3)
	{
		initialSize = 200;
		numGenerations = 400;
	}
	else
	{
		initialSize = std::stoi(argv[1]);
		numGenerations = std::stoi(argv[2]);
		if (argc >= 4)
			filename = argv[3];
	}

	std::ifstream file(filename);
	if (file.is_open())
	{
		Puzzle* puzzle = new Sudoku();
		puzzle->ReadPuzzle(file);

		GeneticAlgorithm algorithm("Sudoku", initialSize, puzzle);
		algorithm.PrintBestSolution(cout);

		for (int i = 0; i < numGenerations; ++i)
		{
			algorithm.Iterate(CULL_RATIO, 1 / (1 - CULL_RATIO));
			algorithm.PrintBestSolution(cout);
			cout << "Generation: " << i + 1 << endl;
			if (algorithm.GetBestFitness() == 0)
				break;
		}
	}
	else
	{
		cout << "File not found." << endl;
	}
}