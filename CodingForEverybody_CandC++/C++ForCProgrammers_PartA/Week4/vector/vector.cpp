// Vector Methods
// 01/11/2022
// Matthew Yough

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int how_many;

	cout << "How many ints in data?:" << endl;
	cin >> how_many;
	vector<int> data (how_many );
	cout << "The contents of data:";
	for (auto it = data.begin(); it != data.end(); ++it)
	{
		cin >> *it;
	}
	//cout << data << endl; error

}