#include <iostream>
using namespace std;
//When a class is derived from a class which is also derived from another class, i.e. a class having more than one parent classes, such inheritance is called Multilevel Inheritance. 
class base{
public:
	int x;
	base()
	{
		cout << "(base class constructor)Enter valu of x ";
		cin >> x;
	}
};

class derived1 : public base
{
public:
	int y;
	derived1()
	{
		cout << "(derived1 class constructor)Enter valu of y ";
		cin >> y;
	}
};

class derived2 : public derived1
{
public:
	int z;
	derived2()
	{
		cout << "(derived2 class constructor)Enter valu of z ";
		cin >> z;
	}

	void displaySum()
	{
		cout << "sumation of three class values : " << z + y + x << endl;
	}
};

int main()
{

	derived2 c;
	c.displaySum();
	getchar();
	getchar();
}



//NOTE:  first execute base class constrctor when derived class constructor called(here u can see)

//advantage

//1.minimize the amount of duplicate code in an application by sharing common  code amongst several subclasses.
//2.Data hiding -- base class can decide to keep some data private so that it cannot be altered by the derived class
//3.Overriding--With inheritance, we will be able to override the methods of the base class so that meaningful  implementation of the base class method can be designed in the derived class.


// Disadvantage
//1.Also with time, during maintenance adding new features both base as well as derived classes are required to be  changed.If a method signature is changed then we will be affected in both cases 
//2.If a method is deleted in the "super class" or aggregate, then we will have to re-factor in case of using that  method.




