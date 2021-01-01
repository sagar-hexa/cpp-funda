#include<iostream>
using namespace std;


inline int multiplication(int x,int y)    // frequently used by program
{
	return x*y;

}
int main()
{
	int x=0,y=0;
	cout << "Enter Number 1" << endl;
	cin >> x;
	cout << "Enter Number 2" << endl;
	cin >> y;
	
	cout << "multiplication of given number is :" << multiplication(x, y);
	getchar();
	return 0;
}


//instead of jumping to the function definition defined elsewhere, the body of function is executed at the line where it is called.(increase execution time)

//NOTE : 
//advantage
		//1. inline function reduce overhead of function call 
		//2. reduce push / pop of every variabl ein stack
		//3. It also saves overhead of a return call from a function.
////////////
//disadvantage


//1. increase execution time , binarie size(copy of same code multiple time),use more memory.