#include <iostream>
using namespace std;
class  myClass{
private:
	int x;
public:
	myClass(int a) {
		x = a;
	};
	~myClass(){
		cout << "Distructor called" << endl;
		getchar();	
	};
};

int main()
{
	myClass abc(10);
	return 0;
}