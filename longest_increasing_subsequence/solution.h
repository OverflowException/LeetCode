#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::max_element;
using std::cout;
using std::endl;

class Solution
{
 public:
  int lengthOfLIS(vector<int>& nums)
  {
    vector<int> LIS_length;
    int result = 0;
    for(auto it = nums.begin() + 1; it != nums.end(); ++it)
      {
	if(*it > *(it - 1))
	  {
	    cout << "Get " << *it << endl;
	    ++result;
	  }
	else
	  if(result != 0)
	    {
	      LIS_length.push_back(result + 1);
	      result = 0;
	    }
      }
    if(result != 0)
      LIS_length.push_back(result + 1);

    for(const auto l : LIS_length)
      cout << l << " ";
    cout << endl;
    return *max_element(LIS_length.begin(), LIS_length.end());
  }
};
