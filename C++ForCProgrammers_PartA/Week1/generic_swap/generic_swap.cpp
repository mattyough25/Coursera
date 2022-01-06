// Generic Coding in CPP
// Matthew Yough
// 20 December 2021

#include <iostream>
#include <complex>
using namespace std;

template<class T>
inline void swap2(T& d, T& s)
{
	T temp = d;
	d = s;
	s = temp;
}

int main()
{
	int m = 5, n = 10;
	double x = 5.3, y = 10.6;
	complex<double> r(2.4,3.5), s(3.4,6.7);

	cout << "int inputs:" << m << "," << n << endl;
	swap2(m,n);
	cout << "int outputs:" << m << "," << n << endl;

	cout << "double inputs:" << x << "," << y << endl;
	swap2(x,y);
	cout << "double outputs:" << x << "," << y << endl;

	cout << "complex inputs:" << r << "," << s << endl;
	swap2(r,s);
	cout << "complex outputs:" << r << "," << s << endl;

	system("pause");
}