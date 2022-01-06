// C++ Converted Program
// Sum Numbers of Array
// 21 December 2021

#include <iostream>
using namespace std;

const int N = 40; //Define constant value N for size of data array to be summed

// Generic sum function
template<class summable>
inline void sum(summable& s, int size, const summable data[])
{
	for(int i = 0; i < size; ++i)
	{
		s += data[i];
	}
	
}

int main()
{
   int accum = 0, data[N];

   // Generate data array to be summed
   for(int i = 0; i < N; ++i)
   {
   		data[i] = i;
   }

    sum(accum, N, data); // Sum array
    cout << "sum is " << accum << endl; // Print sum to screen

    system("pause");
}