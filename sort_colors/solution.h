#include <vector>

using namespace std;

class Solution
{
 public:
  void sortColors(vector<int>& nums)
  {
    size_t count_0 = 0;
    size_t count_1 = 0;
    size_t count_2 = 0;

    for(const auto & ele : nums)
      {
	switch(ele)
	  {
	  case 0:
	    count_0++;
	    break;
	  case 1:
	    count_1++;
	    break;
	  case 2:
	    count_2++;
	    break;
	  }
      }
    vector<int>::iterator it = nums.begin();
    for(;count_0 != 0; count_0--, it++)
      *it = 0;
    
    for(;count_1 != 0; count_1--, it++)
      *it = 1;
    
    for(;count_2 != 0; count_2--, it++)
      *it = 2;
  }
};
