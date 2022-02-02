// Point and Duo
// Matthew YOugh
// 01 February 2022

#include <iostream>
using namespace std;

class duo{
public:
	duo():first(0,0),second(0.0){}
	void set_first(double d){first = d;}
	void set_second(double d){second = d;}
	double get_first(){return first;}
	double get_second(){return second;}
protected: // intermediate data hiding
	double first, second
};

