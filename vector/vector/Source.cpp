#include<iostream>
#include <vector>
using namespace std;
//Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container. 
int main()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for (auto i =v.begin(); i!=v.end();i++)
	{
		cout << *i;
	}
	cout << endl;
	for (auto i = v.rbegin(); i != v.rend(); ++i)
	{
		cout << *i;
	}
	cout << endl;
	for (auto i = v.cbegin(); i != v.cend(); ++i)   // const iterator mean , iterator can not be use to change or modify value.
	{
		cout << *i;
	}

	v.resize(20);
	cout << endl;
	cout << "size of vector " << v.size() << endl;
	cout << "max_size of vector " << v.max_size() << endl;
	cout << "capacity of vector " << v.capacity() << endl;

	// checks if the vector is empty or not 
	if (v.empty() == false)
		cout << "\nVector is not empty";
	else
		cout << "\nVector is empty";

	// Shrinks the vector 
	v.shrink_to_fit();
	cout << "\nVector elements are: ";
	for (auto it = v.begin(); it != v.end(); it++)
		cout << *it << " ";


	//cout << "size of vector" << v.size() << endl;
	getchar();
	return 0;
}



/// reserve : LINK : https://www.geeksforgeeks.org/vector-in-cpp-stl/
// capacity is the maximum number of elements that the vector can store without reallocation.

//reserve will allocate new memory for vector and move all old veriable to new location. it will allocate new memory location with new capacity.
//so we can use vectore for more sapce and capacity.

//advantage

//1. vectore not required to deallocate
//2. vectore directlly assign
//3. size of vectore always available
//4. reallocate vectore size and capacity run time(implicit)