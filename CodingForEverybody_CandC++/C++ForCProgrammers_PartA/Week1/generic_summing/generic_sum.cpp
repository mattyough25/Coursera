// Generic Coding in CPP
// Matthew Yough
// 20 December 2021

#include <iostream>

template<class summable>

summable sum(const summable data[],int size, summable s = 0)
{
	for(int i = 0; i < size; ++i)
	{
		s += data[i];
	}
	return (s);
}
