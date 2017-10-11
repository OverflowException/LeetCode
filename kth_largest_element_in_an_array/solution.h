#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
 public:
  int findKthLargest(vector<int>& nums, int k)
  {
    //Bubble sort
    size_t length = nums.size();
    size_t index;
    for(size_t order = 1; order <= k; order++)
      {
	for(index = length - 1; index >= order; index--)
	  if(nums[index] > nums[index - 1])
	    swap(nums[index], nums[index - 1]);
      }
    return nums[k - 1];
  }
};
