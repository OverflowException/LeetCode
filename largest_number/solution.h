#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

class Solution
{
 public:
  
  void myItol(int _src, list<char>& _dest)
  {
    if(_src == 0)
      {
	_dest.push_back('0');
	return;
      }
    int _mask = 10;
    //_dest.push_back(_src);
    for(; _src > 0; _src /= _mask)
      _dest.push_front((char)(_src % _mask) + '0');
  }
  
  string largestNumber(vector<int>& nums)
  {
    const size_t r_length = nums.size();
    vector<list<char>*> buffer(r_length);
    for(size_t index = 0; index < r_length; index++)
      {
	buffer[index] = new list<char>;
	myItol(nums[index], *buffer[index]);
      }
    
    //variable for lamda
    sort(buffer.begin(), buffer.end(),
	 [=](list<char>* ptr_a, list<char>* ptr_b)->bool
	 {
	   list<char>::iterator it_1 = ptr_a->begin();
	   list<char>::iterator it_2 = ptr_b->begin();
	   while(it_1 != ptr_b->end())
	     {
	       if(it_1 == ptr_a->end())
		 it_1 = ptr_b->begin();
	       
	       if(it_2 == ptr_b->end())
		 it_2 = ptr_a->begin();

	       if(*it_1 > *it_2)
		 return true;
	       else if(*it_1 < *it_2)
		 return false;
	       it_1++;
	       it_2++;
	     }
	   return false;
	   
	 });
    
    decltype(buffer)::const_iterator outer_r_it;
    list<char>::const_iterator inner_r_it;
    
    string result;    
    for(outer_r_it = buffer.cbegin();
	outer_r_it != buffer.cend(); outer_r_it++)
      for(inner_r_it = (*outer_r_it)->cbegin();
	  inner_r_it != (*outer_r_it)->cend(); inner_r_it++)
	result.push_back(*inner_r_it);


    while(result[0] == '0')
      result.erase(0, 1);
      
    if(result.empty())
      result = "0";

    for(auto & ele : buffer)
      delete ele;

    return result;	
  }
};
