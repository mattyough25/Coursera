// Point in C++
// Matthew Yough
// 27 December 2021

#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

class point{    
public:
double get_x();
void  set_x(double v);

double get_y();
void  set_y(double z);

private:
double x, y;
};

point operator+(point& p1, const point& p2)
{   
 point sum = {p1.x + p2.x, p1.y + p2.y};
 return sum;
}

int main()
{
 point a = {3.5,2.5}, b = {2.5,4.5}, c;
}

/*class point{


public:
	point(double x = 0.0, double y = 0.0):x(x),y(y){} //constructor
	double get_x();
	void  set_x(double v);

	//double get_y();
	//void  set_y(double z);

	friend point operator+(point& p1, point& p2)
	{	

   	// point sum = {p1.x};//+ p2.x, p1.y + p2.y};
	 	 return sum;
	}

private:
	double x, y;
};

point operator+(point& p1, point& p2)
{	
    point sum = {p1.get_x() + p2.get_x(), p1.get_x() + p2.get_x()};
	 return sum;
}

/*ostream& operator<<(ostream& out, point p)    
{
	out << "(" << p.get_x() << "," << p.get_x() << ")";
	return out;
} */

int main()
{
	point a = {3.5,2.5}, b = {2.5,4.5}, c;
	//cout << "a = " << a << " b = " << b << endl;
	//cout << "sum = " << a + b << endl;

	system("pause");
}