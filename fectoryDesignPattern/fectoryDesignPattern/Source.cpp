#include <iostream>
using namespace std;


// In Factory pattern, we create object without exposing the creation logic to client and the client use the same common interface to create new type of object.
//Library classes
enum travelType
{
	bus,train,flight
};
class anyTravel
{
public:
	virtual void printTravelType() = 0;
	static anyTravel *create(travelType type);
};

class busTravel : public anyTravel
{
public:
	void printTravelType()
	{
		cout << "Wel come Bus travel booking" << endl;
		getchar();
	}
};

class trainTravel : public anyTravel
{
public:
	void printTravelType()
	{
		cout << "Wel come Train travel booking" << endl;
		getchar();
	}
};

class flightTrvel : public anyTravel
{
public:
	void printTravelType()
	{
		cout << "Wel come Flight travel booking" << endl;
		getchar();
	}
};


anyTravel* anyTravel::create(travelType type)
{
	if (type == flight)
	{
		return new flightTrvel();
	}
	else if (type == train)
	{
		return new trainTravel();
	}
	else if (type == bus){
		return new busTravel();
	}
	else
	{
		return NULL;
	}
}


///NOW implement client side interface (use library common interface by different type of object)

class client{
private:
	anyTravel *anyTravelPtr;
public:
	client(travelType type)
	{
		anyTravelPtr = anyTravel::create(type);   // Here we can call this function vby static method
	}
	~client()
	{
		delete[] anyTravelPtr;
		anyTravelPtr = NULL;
	}
	anyTravel * getTravel()
	{
		return anyTravelPtr;
	}
};



int main()
{
	travelType option;
	int op;
again:	
	cout << "Specify Travel Type (Ex Train , Bus , Flight)" << endl;
	cout << "chose options 1 for Bus, 2 for Train and 3 for Flight" << endl;

	cout << "Enter your option" << endl;
	cin >> op;
	if (op == 1)
		option = bus;
	else if (op == 2)
		option = train;
	else if (op == 3)
		option = flight;
	else
	{
		cout << "wrong option selected" << endl;
		getchar();
		getchar();
		goto again;
	}

	client *c1 = new client(option);
	anyTravel * anyTravelPtr = c1->getTravel();

	anyTravelPtr->printTravelType();
	getchar();
	return 0;
}


// LINK : https://www.geeksforgeeks.org/design-patterns-set-2-factory-method/