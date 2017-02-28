#include <iostream>
#include <fstream>
#include "GeneticAlgorithm.h"

using std::cout;
using std::endl;


int main()
{
	std::ifstream file("Puzzle Data/simpletest.txt");
	Puzzle* puzzle = new Sudoku();
	puzzle->ReadPuzzle(file);

	GeneticAlgorithm algorithm("Sudoku", 100, *puzzle);
	for (int i = 0; i < 5; ++i)
	{
		algorithm.PrintBestSolution(cout);
		algorithm.Iterate(0.8f, 25);
		std::cin.get();
	}
}