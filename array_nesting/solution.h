#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
 public:
  template<typename _C>
    void display(_C c)
    {
      for(const auto& ele : c)
	cout << ele << " ";
      cout << endl;
    }
  
  int setNegative(size_t head_index, vector<int>& nums)
  {
    size_t length = 1;
    size_t walk_index = head_index;
    size_t temp_index = walk_index;
    while(nums[walk_index] != head_index)
      {
	temp_index = nums[walk_index];
	nums[walk_index] = -1;
	walk_index = temp_index;
	++length;
      }
    nums[walk_index] = -1;
    return length;
  }

  
  int arrayNesting(vector<int>& nums)
  {
    list<size_t> lengths;
    for(int index = 0; index < nums.size(); ++index)
      {
	if(nums[index] != -1)
	  lengths.push_back(setNegative(index, nums));
      }
    return *(max_element(lengths.begin(), lengths.end()));
  }
};
