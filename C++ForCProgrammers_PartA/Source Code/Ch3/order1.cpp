/**********************************************************************  Filename:  order1.cpp  Chapter:   3      Functions Pointers and Arrays  Compiler:  Borland C++     Version 5.01      Summer 1998  C++ for C Programmers, Edition 3     By Ira Pohl********************************************************************/#include <iostream>//using namespace std;//Pointer based call-by-referencevoid  order(int*, int*);int main(){   int  i = 7, j = 3;   cout << i << '\t' << j << endl;      //7  3 is printed   order(&i, &j);   cout << i << '\t' << j << endl;      //3  7 is printed   int look; cin >> look;}void order(int* p, int* q){   int  temp;   if (*p > *q) {      temp = *p;      *p = *q;      *q = temp;   }}