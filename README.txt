===================================
POlyMOrphisum (poly mean multiple and morph mena form (many form of same sigature))
======================================
- we can use same signature dinstiguge by it data type and and arguments.function overloading is one type of polymorphisum

1. overloading 
	- same name of function but different argumnet(different signature)
2.overriding
	same name of function but implimentation is different.
	
[Link : http://csit.merospark.com/third-semester/polymorphism/]
	
	
	
======================================
Inheruitance
======================================
class use base class variable by inheritance
1. multiple - class derived from more than one class
2. hirarchical -  multiple subclass derived from base class
3. multilevel  - class1 derived from base class and another class2 derived from class1.

advantage
//1.minimize the amount of duplicate code in an application by sharing common  code amongst several subclasses.
//2.Data hiding -- base class can decide to keep some data private so that it cannot be altered by the derived class
//3.Overriding--With inheritance, we will be able to override the methods of the base class so that meaningful  implementation of the base class method can be designed in the derived class.
 
 
 
========================================
NOTE :  class variable if static than we can access that variable to anywhere.Only we need to initialize that varable out side the class first.
========================================
Ex.

Class myClass{
private:
	static int x;
public:
	int getDtata(int x)
	{
		return x;
	}
}

int myClass ::x = 100; // vlaue store in x is 100 , now we can use that value anywhere.(concept inrodce in singleTone also)
int main()
{
	myClass a;
	cout << "static data x is : << "a.getDtata() << endl;
	return 0;
}

========================================
========================================