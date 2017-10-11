#include <vector>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

class Solution
{
 public:
  int integerBreak(int n)
  {
    //The product of previous and current break-multiply
    int prev_result = 1, curr_result = 1;
    vector<int> parts;
    decltype(parts)::iterator it;
    int n_copy;
    for(int parts_count = 2; parts_count < n; ++parts_count)
      {
	curr_result = 1;
	///////////////////////////
	parts.resize(parts_count);
	for_each(parts.begin(), parts.end(), [](int& n){n = 0;});
	n_copy = n;
	for(it = parts.begin(); n_copy > 0; --n_copy, ++it)
	  {
	    if(it == parts.end())
	      it = parts.begin();
	    
	    (*it)++;
	  }
	for(it = parts.begin(); it != parts.end(); ++it)
	  {
	    cout << *it << " ";
	    curr_result *= *it;
	  }
	cout << endl;
	
	if(prev_result > curr_result)
	  break;
	
	prev_result = curr_result;
      }
    return prev_result;
  }
};
