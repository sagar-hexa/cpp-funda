#include <iostream>
using namespace std;
// child class derived from more than one class
class A{
public:
	int x;
	void getDataofA(){
		cin >> x;
	}
};
class B{
public:
	int y;
	void getDataofB()
	{
		cin >> y;
	}

};
class C: public A ,public B{
public:
	int z;
	void getDataofC(){
		cin >> z;
	}
	void sum()
	{
		cout << x + y + z << endl;
	}
};
int main()
{

	cout << "Example of multiple Inheritance" << endl;
	C a1;
	cout << "insert input value of x , y and z" << endl;
	a1.getDataofA();
	a1.getDataofB();
	a1.getDataofC();

	cout << "sumation of three class data" << endl;
	a1.sum();
	getchar();
	getchar();
}