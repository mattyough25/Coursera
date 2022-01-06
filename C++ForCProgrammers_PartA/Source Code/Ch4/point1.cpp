/**********************************************************************  Filename:  point1.cpp  Chapter:   4      Classes  Compiler:  Borland C++     Version 5.01      Summer 1998  C++ for C Programmers, Edition 3     By Ira Pohl********************************************************************/#include <iostream>#include <string>using namespace std;struct point {   double x, y;   void  plus(point c);       //function prototype   void print(string name);   void print() { cout << "(" << x << "," << y << ")"; }   void init(double u, double v) { x = u; y = v; }};void point::print(string name){   cout << name << " (" << x << "," << y << ")";}void point::plus(point c)     //definition not inline{//offset the existing point by point c   x += c.x;   y += c.y;}int main(){   point w1, w2;   w1.init(0, 0.5);   w2.init(-0.5, 1.5);   cout << "\npoint w1 = ";   w1.print();   cout << "\npoint w2 = ";   w2.print();   w1.plus(w2);   cout << "\npoint w1 after plus = ";   w1.print();   int look; cin >> look;}