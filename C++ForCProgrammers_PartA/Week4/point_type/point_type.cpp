// Point Type
// Matthew Yough
// 01/11/2022

#include <iostream>
using namespace std;

class point{
public:
	point(double u):x(u),y(0.0){} // explicit point()... *turns off implicit conversion*

private:
	double x, y;
};

/*point::operator double(){
	return sqrt(x*x + y*y);
}*/

ostream& operator<<(ostream& out, const point& p){
	out << "(" << x << "," << y << ")";
	return out;
}

int main(){
	point s = 3.5;
	double d;

	d = s;

}