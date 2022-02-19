// Input Iterator
// 01/11/2022
// Matthew Yough

#include <iostream>
#include <fstream>
#include <numeric>
#include <iterator>
using namespace std;

int main()
{
	ifstream myin("data");
	istream_iterator<int> in(myin);
	istream_iterator<int> eos;
	cout << "Sum of data is " << accumulate(in, eos, 0) << endl;
}