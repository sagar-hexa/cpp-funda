#include <iostream>

using namespace std;

// single topne working with static variable and function(return pointer of class used for entire application) and distroy at time of distructor call and in case of allication end.
//Singleton design pattern is a software design principle that is used to restrict the instantiation of a class to one object.



// first need to clear static variable declairation and inintialization 

//==========================================================================
/*
//Ex. 
class A{
private:
	static int x;
public:
	int getdata(){
		return x;
	}
};
// need to initializa static variable somewhere outside of class as bellow

int A::x = 10;

int main()
{
	A a;
	cout << "static data x is : " << a.getdata() << endl;
	getchar();
	return 0;
}
*/
//==========================================================================
//===============================Single Tone implementation==============================

class myClassSingleTone{
private:
	static bool instanceFlag;
	static myClassSingleTone *singleTonePtr;

	// multiple defination(module like library initialization and file path return for logger etc.) we can initilize 

	myClassSingleTone(){};  // can not be creat object of class
public:
	static myClassSingleTone *getinstance();
	void getInfo()
	{
		cout << "SingleTone Instance Innitialize" << endl;
	}
	~myClassSingleTone()
	{
		instanceFlag = false;
	}
};


// innitialize static variable
bool myClassSingleTone::instanceFlag = false;
myClassSingleTone* myClassSingleTone:: singleTonePtr = NULL;

myClassSingleTone* myClassSingleTone::getinstance(){
	if (!instanceFlag){
		singleTonePtr = new myClassSingleTone();
		instanceFlag = true;						// first time intialization
		return singleTonePtr;
	}
	else{
		return singleTonePtr;
	}
}

int main()
{
	myClassSingleTone *s1 , *s2; 
	s1 = s1->getinstance();
	s1->getInfo();
	s2 = s2->getinstance();
	s2->getInfo();
	getchar();
	return 0;
}
//function retturn pointer will be implement in singletone pattern





//Best exmple https://www.codeproject.com/Articles/1921/Singleton-Pattern-its-implementation-with-C
//LINKS : https://www.tutorialspoint.com/Explain-Cplusplus-Singleton-design-pattern
