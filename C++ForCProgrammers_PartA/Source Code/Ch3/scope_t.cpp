/**********************************************************************  Filename:  scope_t.cpp  Chapter:   3      Functions Pointers and Arrays  Compiler:  Borland C++     Version 5.01      Summer 1998  C++ for C Programmers, Edition 3     By Ira Pohl********************************************************************/#include <iostream>//using namespace std;int main (){   int  a = 2;               //outer block a   cout << a << endl;        //prints 2   {                         //enter inner block      int  a = 7;            //inner block a      cout << a << endl;     //prints 7   }                         //exit inner block   cout << ++a << endl;      //3 is printed   int look; cin >> look;}