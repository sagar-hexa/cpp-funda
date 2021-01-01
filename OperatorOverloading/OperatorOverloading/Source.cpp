#include <iostream>
#include <string>
using namespace std;

class myClass
{
private:
	int x;
public:
	myClass(int a){
		x = a;
	}
	int operator +()
	{
		++x;
		return x;
	}

	string operator ++()
	{
		return "sagar";
	}

	void print();
	
};


void myClass::print()
{
		cout << x << endl;
}
int main()
{
	myClass abc(10);
	abc.print();
	myClass xyz(20);
	xyz.print();

	abc = +xyz;
	abc.print();
	xyz.print();
	string name = ++xyz;
	cout << "name is : " << name;
	getchar();
	return 0;
}


//defination returnType and operator symbol
//note :  operator ++ (int) (how the postfix operator initialize)