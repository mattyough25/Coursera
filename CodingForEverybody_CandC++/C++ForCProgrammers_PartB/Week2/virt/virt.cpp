// Virtual Member Functions
// Matthew Yough
// 07 February 2022

// Example of inheritence 

#include <iostream>
#include <algorithm>
#include <cmath>
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

class point:public duo{
public:
	point():duo(){} //initialize base object
	point(double x, double y = 0.0):duo(x,y){}
	virtual double length(){return sqrt(first*first+second*second);}
}; //virtual is pure polymorphism and remains

class point3d final:public point{ //final prevents this class from being inherited from
public:
	point3d():point(),z(0.0){}
	double length(){return sqrt(first*first+second*second+z*z);} //virtual
	void set_z(double d){z = d;}
private:
	double z;
};

