#include<iostream>
using namespace std;

class myClass{
private:
	int x;
	float y;
public:
	myClass(){
		cout << "default constructor called" << endl;
	}
	myClass(int a){
		cout << "constructor with one argument" << endl;
		x = a;
	}
	myClass(int a, int b){
		cout << "constructor with two argument" << endl;
		x = a;
	}
	myClass(int c,float d){
		cout << "constructor overloading by data type" << endl;
		x = c;
		y = d;
	}
};


int main()
{
	myClass a0;
	myClass a1(10);
	myClass a2(10, 20);
	myClass a3(10, 10.3f); // constructor with float value
	getchar();
	return 0;
}



///Note: Remember that the constructor cannot be declared with keyword virtual and references or pointers cannot be used on constructor as their addresses cannot be taken.