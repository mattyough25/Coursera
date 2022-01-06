// Point and its Constructors
// Matthew Yough
// 29 December 2021

class point
{
public:
	point(double x = 0.0, double y = 0.0):x(x),y(y){} //constructor
	double getx(){return x;}
	void setx(double v){x=v;}

	double gety(){return y;}
	void sety(double z){y=z;} 
private:
	double x, y;
};