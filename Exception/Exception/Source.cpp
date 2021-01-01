#include<iostream>
using namespace std;

inline int division(int a, int b)
{
	if (b == 0)
	{
		throw "cant be deivide by ZERO value!!!";
	}
	return (a / b);
}

int main()
{
	int x = 0, y = 0;
	int ret = 0;
	cout << " insert a value of x :" ;
	cin >> x;
	cout << "insert value of y: " ;
	cin >> y;
	try{
		 ret = division(x, y);
		 cout << "return value of devision is : " << ret << endl;
	}
	catch (const char* msg){
		cout << msg << endl;
	}


	
	getchar();
	getchar();

	return 0;
}