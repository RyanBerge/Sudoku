#include <iostream>
#include <fstream>
#include <ctime>
#include "GeneticAlgorithm.h"

using std::cout;
using std::endl;


int main()
{
	srand(time(nullptr));

	std::ifstream file("Puzzle Data/simpletest.txt");
	Puzzle* puzzle = new Sudoku();
	puzzle->ReadPuzzle(file);

	GeneticAlgorithm algorithm("Sudoku", 1000, *puzzle);
	algorithm.PrintBestSolution(cout);
	//std::cin.get();

	for (int i = 0; i < 30; ++i)
	{
		algorithm.Iterate(0.8f, 4);
		algorithm.PrintBestSolution(cout);
		//std::cin.get();
	}
}