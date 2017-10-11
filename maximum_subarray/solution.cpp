#include "solution.h"

int Solution::maxSubArray(vector<int>& nums)
{
  vector<int> sums(nums.size() + 1);
  vector<int> valley; //the valleys of sums 

  //To traverse sums, nums ans poles
  vector<int>::const_iterator n_it;
  vector<int>::iterator s_it;
  vector<int>::iterator valley_it;

  //discrete integration, count non-positive and obtain nums maximum 
  int num_max = *nums.begin();
  sums[0] = 0;
  for(n_it = nums.cbegin(), s_it = sums.begin() + 1;
      s_it != sums.end();
      n_it++, s_it++)
    {
      if(*n_it > num_max)
	num_max = *n_it;

      *s_it = *(s_it - 1) + *n_it;
    }

#ifdef _DEBUG
  cout << "nums_max = " << num_max << endl;
  cout << "Sums = ";
  for(const auto ele : sums)
    cout << ele << " ";
  cout << endl;
#endif

  //If all elements of nums are non-positive
  if(num_max <= 0)
    return num_max;

  //The difference between a peak and a valley is called a fall
  int fall;
  int fall_max = 0;
  int current_sum;

  //Generate valleys
  if(*sums.begin() <= *(sums.begin() + 1))
    valley.push_back(*(sums.begin()));

  for(s_it = sums.begin() + 1; s_it != sums.end() - 1; s_it++)
    {
      current_sum = *s_it;
      //A valley
      if(current_sum <= *(s_it + 1) &&
	 current_sum < *(s_it - 1))
	valley.push_back(current_sum);

      //A peak
      else if(current_sum >= *(s_it + 1) &&
	      current_sum > *(s_it - 1))
	{
	  for(valley_it = valley.begin(); valley_it != valley.end();
	      valley_it++)
	    {
	      fall = current_sum - *valley_it;
	      fall_max = fall > fall_max ? fall : fall_max;
	    }
	}
    }

#ifdef _DEBUG
  cout << "valley:" << endl;
  if(valley.empty())
    cout<<"<empty>"<<endl;
  else
    {
      for(auto ele : valley)
	cout << ele << " ";
      cout<< endl;
    }
#endif

  if(*(sums.end() - 1) > *(sums.end() - 2))
    {
      current_sum = *(sums.end() - 1);
      for(valley_it = valley.begin(); valley_it != valley.end();
	  valley_it++)
	{
	  fall = current_sum - *valley_it;
	  fall_max = fall > fall_max ? fall : fall_max;
	}
    }

  return fall_max;
}
