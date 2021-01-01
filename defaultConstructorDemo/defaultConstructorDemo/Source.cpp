#include <iostream>
using namespace std;

//Constructors exist purely to initialise member variables. compiler autometic initialize defult constructor.

class myClass {

private:
	int x; //variable
	int y;
public:
	myClass() {
		cout << "default constructor initialize" << endl;
	}; //default constructor (compiler initiate this constructor without object creation)

	myClass(myClass &b) {
		cout << "copy constructor initialize " << b.y << endl;
	}; 


	myClass(int a, int b)
	{
		x = a;
		y = b;
		cout << "constructor with argument : " << x << " (paramiterized constructor)" << endl;
	};

	void print()
	{
		cout << "value initialize by parameterized constructor is : " << x << endl;
	}


	//............other stuf
};

int main()
{
	myClass abc; // default consructor initialize as on bject create.
	myClass xyz(10,20); // parameterized consructor initialize as onbject create.
	myClass pqr(xyz);
	getchar();
	return 0;
}


// consrucor disadvantage not static , not virtual , not inherited without friend and class ownb function
	//2. does not have return type
	// can not fetch address

// distructor
	//1.Destructors neither take any argument nor do they return any value, not even void.
	//2. Destructors cannot be inherited
	//3. A destructor function must have public access in the class declaration.
