#include <iostream>
using namespace std;


class base{
private:
	int x;
public:
	void readData()
	{
		cout << "enter value of x : "; 
		cin >> x;
	}
	void print()
	{
		cout << "base class value is " << x << endl;
	}
	void print(base A)
	{
		cout << "base class function call from derived class B" << endl;
	}
};


class derived : public base
{
private:
	int y;
public:
	derived(int a)
	{
		cout << "vlaue of uy given by constructor with argument value is : " << a << endl;
		y = a;
	}
	void display(){
		cout << "(derived class) value of y is "  << y << endl;
	}
};
int main()
{
	base A;
	derived B(100);
	A.readData();		// value  initialize by object A , not accesible by other object even if derived object
	A.print();

	B.display();
	B.print(A);   // A classs function 
	getchar();
	getchar();
	return 0;
}