// Find Algorithm
// Matthew Yough
// 28 January 2022

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string words[5] = {"my","hop","mop","hope","cope"};
	string* where;

	where = find(words, words + 5, "hop");
	cout << *++where<<endl;
	sort(words, words + 5);
	where = find(words, words + 5, "hop");
	cout << *++where << endl;
}