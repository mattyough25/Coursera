// STL Example
// 01/11/2022
// Matthew Yough

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v(100); // allocate space
	
	// creates array
	for (int i = 0; i < 100; ++i) // C idiom
	{
		v[i] = i; // index thru like an array
	}	

	// outputs array
	for (vector<int>::iterator p = v.begin(); p != v.end(); ++p) // C++ idiom
	{
		cout << *p << '\t';
	}
	cout << endl;

	for (auto p = v.begin(); p != v.end(); ++p) // same as prior for loop but easier/better
	{
		cout << *p << '\t';
	}
	cout << endl;
	// auto means to "infer type"
	// ex. auto i = 3; int
	// ex. auto d = 3.7; double
	// ex. auto c = d; // c is a double
}

/* 
Vector Methods
v.size() get current size
v.resize(int size) resize vector
v.begin() beginning of vector
v.end() end of vector

Constructors
vector<T> v; empty sequence
vector<T> v(n); size n with default constructor T() called for each element
vector<T> v(n, value); value is of type T