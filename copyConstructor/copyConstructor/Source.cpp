#include <iostream>
using namespace std;

class myClass{
private:
	int x;
public:
	myClass(int a){

		cout << "initialize value x as obj create is :" << a << endl;
		x = a;
	}
	myClass(myClass &obj)
	{
		cout << "call by copy constructor value initialized by normal constructor is :" << obj.x << endl;
	}
};


int main()
{
	myClass abc(100);
	myClass xyz(abc);
	//getchar();
	return 0;
}


//advantage

/// copy onstructor used to to create new object by duplicating the state of existing object and it done by coping the value of 
/// data member of exsting object in new object data member.

//disadvantage 

/// if clas have  dynamic memory allocated or file pointers than copy constrcuctor copy that pointer address , both object use same location of memory of file
