#include <iostream>
#include<stdio.h>
using namespace std;

//The simple idea is to pass data type as a parameter so that we don’t need to write same code for different data types. 
template <typename T>
T func(T x)
{
	x = x *x;
	return x;
}

/// class template

template <class T>
class myclass
{
private:
	T x;
public:
	T getData(T y);
	
};

template <typename T>
T myclass<T>:: getData(T y)
{
	x = y;
	return x;
}

template <typename T,typename U>
T func1(T x, U y)
{
	cout << x << endl;
	cout << y << endl;
	return 0;
}
int main()
{
	cout << func<int>(10) << endl;
	cout << func<double>(1.5) << endl;
	
	myclass<int> a;
	cout << a.getData(10) << endl;
	myclass<double> b;
	cout << b.getData(1.5) << endl;

	// multi Template function

	func1<int, char>(50, 'a');
	getchar();
	return 0;
}