// STL Input File
// 01/11/2022
// Matthew Yough

#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ifstream word_file("word.txt");
	istream_iterator<string> start(word_file), end;
	vector<string> words(start, end);

	cout << " \n\nwords as read\n";
	for (auto str : words)
	{
		cout << str << "\t" ;
	}
	sort(words.begin(), words.end());
	cout << "\n\nwords as sorted\n";

	for(auto str : words)
	{
		cout << str << "\t" ;
	}
	cout << endl;
}