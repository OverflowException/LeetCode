#include "solution.h"

int main(int argc, char** argv)
{
  Solution* s = new Solution;
  vector<int> nums(5);
  for(auto it = nums.begin(); it != nums.end(); it++)
    *it = it - nums.begin();
  
  vector<vector<int>> result = s->permute(nums);
  for(const auto ele_l1 : result)
    {
      for(const auto ele_l2 : ele_l1)
	cout << ele_l2 << " ";
      cout << endl;
    }
  return 0;
}
