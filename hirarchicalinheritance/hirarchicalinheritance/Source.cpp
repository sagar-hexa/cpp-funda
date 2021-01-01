#include <iostream>
using namespace std;

class A{
public:
	int x;
	void getdata()
	{
		cout << "Enter value of x ";
		cin >> x;
	}
};

class B : public A
{
public:
	int y;
	void getdataofb()
	{
		cout << "Enter value of y ";
		cin >> y;
	}
	void mul()
	{
		cout << "multiplication of x and y is :" << x * y << endl;
	}
};

class C : public A
{
public:
	int z;
	void getdataofc()
	{
		cout << "Enter value of z ";
		cin >> z;
	}
	void sum()
	{
		cout << "summation of x and z is : " << x + z << "\n\n";
	}

};


int main()
{
	C c1;
	B b1;
	c1.getdata();
	c1.getdataofc();
	c1.sum();

	b1.getdataofb();
	b1.getdata();
	b1.mul();

	getchar();
	getchar();
}


//advantage

//1.minimize the amount of duplicate code in an application by sharing common  code amongst several subclasses.
//2.Data hiding -- base class can decide to keep some data private so that it cannot be altered by the derived class
//3.Overriding--With inheritance, we will be able to override the methods of the base class so that meaningful  implementation of the base class method can be designed in the derived class.


// Disadvantage
//1.Also with time, during maintenance adding new features both base as well as derived classes are required to be  changed.If a method signature is changed then we will be affected in both cases 
//2.If a method is deleted in the "super class" or aggregate, then we will have to re-factor in case of using that  method.