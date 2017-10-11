#include "solution.h"

using std::cout;
using std::endl;

int main()
{
  Solution s;
  vector<int> primes{7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251};

  for(int index = 1; index < 100; ++index)
    if(s.checkPrimeList(index, primes))
      cout << index << " ";
  cout << endl;
    
  cout.setf(ios::boolalpha);
  cout << s.nthSuperUglyNumber(10000, primes) << endl;
}
