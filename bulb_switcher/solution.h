#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
  int bulbSwitch(int n)
    {
      vector<bool> bulbs(n, true);
      size_t index;
      cout.setf(ios::boolalpha);
      for(int round = 2; round <= n; ++round)
        {
	  for(index = round - 1; index < n; index += round)
	    bulbs[index] = !bulbs[index];
	  for(bool b : bulbs)
	    cout << b << " ";
	  cout << endl;
        }
      int result = 0;
      for(bool b : bulbs)
	if(b)
	  ++result;
      return result;
    }
};
