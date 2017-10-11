#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
 public:
  
  int maximumGap(vector<int>& nums)
  {
    if(nums.size() < 2)
      return 0;
    
    int num_min = *nums.begin();
    int num_max = num_min;
    
    for(const int ele : nums)
      if(ele > num_max)
	num_max = ele;
      else if(ele < num_min)
	num_min = ele;

    ////////////////////
    cout << num_min << endl;
    cout << num_max << endl;
    ///////////////////
    
    //Set markers
    vector<bool> markers(num_max - num_min + 1, false);        
    for(const auto ele : nums)
      markers[ele - num_min] = true;
            
    vector<bool>::iterator prev_marker_it = markers.begin();
    
    int result = 0;
    int curr_diff;
    for(auto curr_marker_it = prev_marker_it + 1; curr_marker_it != markers.end(); ++curr_marker_it)
      if(*curr_marker_it)
	{
	  if((curr_diff = curr_marker_it - prev_marker_it) > result)
	    result = curr_diff;
	    
	  prev_marker_it = curr_marker_it;
	}

    return result;
  }
};
