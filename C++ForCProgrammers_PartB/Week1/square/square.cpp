// Square Using Iterator
// 20 January 2022
// Matthew Yough

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
using namespace std;

template<typename ForwardIterator>
void square(ForwardIterator first, Forward Iterator last)
{
	for(; first!=last; first++)
	{
		*first = (*first) * (*first);
	}
}

int main()
{ ...

	square(w.begin(), w.end());

	for(auto i: w) // range for
	{
		cout << i << "\t";
	}
	cout << endl;
}