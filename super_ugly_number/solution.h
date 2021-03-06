#include <vector>
#include <iostream>

using std::vector;
using std::ios;

class Solution
{
 public:
  inline bool wholeDivide(int& divisor, int divident)
  {
    
  }
  
  //Must NOT input 0 as num!
  //Or it will be trapped in a death cycle
  inline bool checkPrimeList(int num, vector<int>& primes)
  {
    for(auto p_it = primes.begin(); p_it != primes.end(); ++p_it)
      while(!(bool)(num % *p_it))
	num /= *p_it;
    return num == 1;
  }
  
  int nthSuperUglyNumber(int n, vector<int>& primes)
  {
    size_t traverse = 0;
    while(n > 0)
      {
	traverse++;
	if(checkPrimeList(traverse, primes))
	  --n;
      }
    return traverse;
  }

};
