/**********************************************************************  Filename:  stl_revr.cpp  Chapter:   7      Templates Generic Programming and STL  Compiler:  Borland C++     Version 5.01      Summer 1998  C++ for C Programmers, Edition 3     By Ira Pohl********************************************************************/#include <iostream>#include <vector>#include <algorithm>#include <string>using namespace std;//Use of mutating copy and reverseint main(){   string first_names[5] = {"laura", "ira",        "buzz", "debra", "twinkle"};   string last_names[5] = {"pohl", "pohl",        "dolsberry", "dolsberry", "star"};   vector<string> names(first_names, first_names + 5);   vector<string> names2(10);   vector<string>::iterator p;   copy(last_names, last_names + 5, names2.begin());   copy(names.begin(), names.end(), names2.begin()+5);   reverse(names2.begin(), names2.end());   for (p = names2.begin(); p != names2.end(); ++p)      cout << *p <<'\t';   int look; cin >> look;}