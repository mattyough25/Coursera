// Typedef Days C++ Code
// Matthew Yough
// 24 December 2021

#include <iostream>
using namespace std;

typedef enum days{SUN, MON, TUE, WED, THU, FRI, SAT} days;

inline days operator++(days d)
{
	return static_cast<days>((static_cast<int>(d) + 1) % 7);
}

ostream& operator<<(ostream& out, const days& d)
{
	switch (d)
	{
		case SUN: out<<"SUN";break;
		case MON: out<<"MON";break;
		case TUE: out<<"TUE";break;
		case WED: out<<"WED";break;
		case THU: out<<"THU";break;
		case FRI: out<<"FRI";break;
		case SAT: out<<"SAT";break;
	}
	return out;
}

int main()
{
	days d = MON, e;
	e = ++d;
	cout<<d<<'\t'<<e<<endl;

	system("pause");
}