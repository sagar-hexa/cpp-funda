#include<iostream>
using namespace std;
class myClass;

// friend function os function to access class variable without  it object creation.
class myClass1
{
private:
	int z;
public:
	myClass1(int a){
		z = a;
	}

	friend void print1(myClass, myClass1);
};


class myClass
{
private:
	int x;
	int y;
public:
	myClass(int a, int b)
	{
		x = a;
		y = b;
	}
	friend void print1(myClass, myClass1);
	friend void print(myClass abc)
	{
		cout << "variable of myClass is : " << abc.x;
	}

};

void print1(myClass A, myClass1 B)
{

	cout << A.x << " and " << B.z;
}


class A{
private:
	int a;
	friend class B;
public:
	A(int p){
		a = p;
	}
};

class B{
private:
	int b;
public:
	
	void display(A &pqr)
	{
		cout << "freiend class variable : " << pqr.a;
	}

};
int main()
{
	A a(555);
	B b;
	myClass abc(10,20);
	myClass1 xyz(5);
	//print(abc);
	print1(abc, xyz);
	b.display(a);
	getchar();
	return 0;
}


// Advantage
// 1.when required to use private member of class without its object than we camn use friend function.
// 2.any whare we cal call function to access class private member also.
// 3.Able to access members without need of inheriting the class.
// 4. Can be declared either in the public or the private part of a class.

// same function in two class than , thoes classis are friends of each other.

//here b canacces class A member but class A can not acces class B member

///Disaadvantage 

//1. it have globla scop.so Friend function have access to private members of a class from outside the class which violates the law of data hiding.
