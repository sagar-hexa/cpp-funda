#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

union ulf
{
	unsigned long ul;
	float f;
};

int main()
{
	ulf u;
	string str = "00bff409";
	stringstream ss(str);
	ss >> hex >> u.ul;
	float f = u.f;
	cout << f << endl;



	getchar();
}