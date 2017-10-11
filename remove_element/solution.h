#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
 public:
  int removeElement(vector<int>& nums, int val)
  {
    return partition(nums.begin(), nums.end(), [=](int n){return n != val;}) - nums.begin();
  }
};
