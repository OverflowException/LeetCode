#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
 public:
  int majorityElement(vector<int>& nums)
  {
    size_t threshold = nums.size() / 2;
    unordered_map<int, size_t> m_total;

    for(const int ele : nums)
      {
	if(++m_total[ele] > threshold)
	  return ele;
      }
  }
};
