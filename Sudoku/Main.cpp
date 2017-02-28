#include <iostream>
#include <fstream>
#include "Sudoku.h"

using std::cout;
using std::endl;

class A
{
public:
	virtual int Foo() { return 1; }
};

class B : public A
{
public:
	virtual int Foo() override { return 2; }
};

class C : public A
{
public:
	virtual int Foo() override { return 3; }
};

int main()
{
	try
	{
		A* a = new B();
		cout << a->Foo() << endl;
		B* b = dynamic_cast<B*>(a);
		cout << b->Foo() << endl; // successful
		C* c = dynamic_cast<C*>(a); //returns nullptr
		cout << c->Foo() << endl; //crashes
	}
	catch (std::exception e)
	{
		cout << e.what() << endl;
	}



	std::ifstream file("Puzzle Data/simpletest.txt");
	Sudoku sudoku;
	file >> sudoku;
	cout << sudoku << endl;
}