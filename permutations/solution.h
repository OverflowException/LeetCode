#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <vector>
#include <iostream> 
#include <algorithm>

using namespace std;

class Solution
{
 public:
  
  void recursivePermute(vector<int>& nums,
			vector<int>::iterator curr_it,
			vector<vector<int>>& result)
  {
    if(curr_it == nums.end() - 1)
      result.push_back(nums);
    else
      {
	for(auto it = curr_it; it != nums.end(); it++)
	  {
	    swap(*curr_it, *it);
	    recursivePermute(nums, curr_it + 1, result);
	    swap(*curr_it, *it);
	  }
      }
  }
  
  vector<vector<int>> permute(vector<int>& nums)
    {
      vector<vector<int>> result;
      recursivePermute(nums, nums.begin(), result);
      
      return result;
    }
  
};

#endif
