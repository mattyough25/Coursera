// Random Access
// 25 January 2022
// Matthew Yough

#include <cstddef>

template<typename RandomAccess>
RandomAccess
pickRandEl( RandomAccess first, RandomAccess last)
{
	ptrdiff_t temp = last-first;
	return first + rand()%temp;
}