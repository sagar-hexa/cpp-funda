#include <iostream>
using namespace std;

// Uniform initrialization is used for innitialize variable and aggrigate cvalriable in { brace } manner.

class myClass {
	int arr[3];
	int mx;
	double my;
public:

	myClass();
	// uniform initialization of array
	//myClass(int x, int y, int z) : arr{ x, y, z } {};
	myClass(int x, double y) : mx(x), my(y){};

};


int main()
{
	//myClass x{1, 2, 3};
	myClass y{ 10, 10.20 };

	return 0;
}