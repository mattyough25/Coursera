// File Stream
// 01/11/2022
// Matthew Yough

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	ifstream data_file("data.txt"); // text file containing data
	istream_iterator<int> start(data_file), end;
	vector<int> data(start, end);

	// Sum the data
	int sum = 0;
	for (auto it = start; it != end; ++it)
	{
		sum += *it;
	}
	cout << "sum = " << sum << endl;
	cout << "average is = " << 1.0 * sum/data.size() << endl;
}