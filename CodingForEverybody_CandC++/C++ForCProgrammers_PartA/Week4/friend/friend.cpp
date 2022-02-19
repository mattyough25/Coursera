// Friend Function
// Matthew Yough
// 01/11/2022

#include <iostream>
using namespace std;

class point{
friend ostream& operator<<(ostream& out, const point& p);

public:
	point(double u):x(u),y(0.0){} // explicit point()... *turns off implicit conversion*

private:
	double x, y;
};

ostream& operator<<(ostream& out, const point& p){
	out << "(" << p.x << "," << p.y << ")";
	return out;
}

int main(){

	return 0;
}