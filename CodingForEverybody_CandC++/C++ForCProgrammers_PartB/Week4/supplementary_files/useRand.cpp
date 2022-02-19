//Use of random
//Ira Pohl  April 2016

#include<cstddef>  //ptrdiff_t
#include<iostream>
#include<random>
#include<vector>
#include<algorithm>
#include<ctime>   //use time(nullptr) for seed

using namespace std;
   
default_random_engine  e(time(nullptr));   //seed here
uniform_real_distribution<double> u(0, 1); //use a uniform distribution

template< typename RandomAccess>
RandomAccess
pickRandEl( RandomAccess first, RandomAccess last)
{
   
   ptrdiff_t temp = last-first;
   return first + u(e)*temp;
}


int main()
{
   int size_d = 1000;
   vector<int> data(size_d);
   for(auto& element: data)
       element = 10000 * u(e); //uniform distribution with default engine

   double accum =  accumulate(data.begin(), data.end(), 0.0);
   cout << "average value is " << accum/(1.0 * size_d);
   cout << endl;
   for(int i = 0; i < 100; ++i)
      cout << *pickRandEl(data.begin(), data.end()) << '\t';
   cout << endl;
   
   auto mm = minmax_element(data.begin(), data.end());
   cout << "min and max \n";
   cout <<  *mm.first << "   second "  << *mm.second<< endl;

}


