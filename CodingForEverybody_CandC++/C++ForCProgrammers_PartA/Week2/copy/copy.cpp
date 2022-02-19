// Copying an Array
// Matthew Yough
// 22 December 2021

#include <iostream>
using namespace std;

const int N = 10; 

template<class array1, class array2>
void copy2(const array1 source[], array2 destination[], int size)
{
	for(int i = 0; i < size; ++i)
	{
		destination[i] = static_cast<array2>(source[i]);
	}
}

int main()
{
	int source[N], destination[N];

	// Generate data array
   for(int i = 0; i < N; ++i)
   {
   		source[i] = i;
   }

   cout << "Source array is: " << source[N] << endl;

   copy2(source, destination, N);

   cout << "Destination array is: " << destination[N] << endl;

   system("pause");
}