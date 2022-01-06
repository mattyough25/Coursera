/**********************************************************************  Filename:  stack_t2.cpp  Chapter:   8      Inheritance  Compiler:  Borland C++     Version 5.01      Summer 1998  C++ for C Programmers, Edition 3     By Ira Pohl********************************************************************/#include <iostream>#include <assert>//template stack implementationtemplate <class TYPE>class stack {public:   explicit stack(int size = 100)      : max_len(size), top(EMPTY),s(new TYPE[size])       { assert(s != 0); }   ~stack() { delete []s; }   void  reset() { top = EMPTY; }   void  push(TYPE c) { s[++top] = c; }   TYPE  pop() { return s[top--]; }   TYPE  top_of()const { return s[top]; }   bool  empty()const { return top == EMPTY;}   bool  full()const { return top == max_len - 1;}private:   enum   { EMPTY = -1 };   TYPE*  s;   int    max_len;   int    top;};//safe character stackclass safe_char_stack : public stack<char> {public:   // test push and pop   void  push(char c)     { assert (!full()); stack<char>::push(c); }   char  pop()     { assert (!empty()); return (stack<char>::pop()); }};//Reversing an array of char* represented stringsvoid reverse(char* str[], int n){   stack<char*>  stk(n);   int i;   for (i = 0; i < n; ++i)      stk.push(str[i]);   for (i = 0; i < n; ++i)      str[i] = stk.pop();}template <class T1>void print_and_pop(T1& a, char* comment){   cout << "Printing " << comment << endl;   while (!a.empty())      cout << a.pop() << '\t';   cout << endl;}//Initializing stack of complex numbers from an arrayint main(){   stack<char>     stk_ch;         // 1000 char stack   stack<char*>    stk_str(200);   // 200 char* stack   char* str[3] = {"Reverse", "these", "three"};   stk_ch.push('A');   stk_ch.push('B');   print_and_pop(stk_ch, "char");   stk_str.push("ABCD");   stk_str.push("EFGH");   print_and_pop(stk_str, "char*");   reverse(str, 2);   cout << "Reversed 2" << endl << str[0] << str[1]        << str[2] << endl;   int look; cin >> look;}