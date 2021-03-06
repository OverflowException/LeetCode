#include <vector>
#include <iostream>

using namespace std;

/*Something like:
  1 2 3 7 4 0 0 0 9 3 4
The continous 0s are called a 'trap'
*/


class Solution
{
 public:
  
  typedef vector<int>::iterator Pos;
  /*Returns the last postion
  //beg will be placed at the off-end position of
  a trap after this function returned*/
  size_t getNextTrapLength(Pos& beg, Pos end)
    {
      while(beg != end)
	{
	  //Found the head of a trap
	  if(*beg == 0)
	    break;
	  ++beg;
	}
      auto _trap_beg = beg;
      while(beg != end)
	{
	  if(*beg != 0)
	    break;
	  ++beg;
	}
      
      return beg - _trap_beg;
    }
  
  bool canJump(vector<int>& nums)
  {
    if(nums.size() == 1)
      return true;
    
    if(*nums.begin() == 0)
      return false;
    
    Pos nums_pos = nums.begin();
    Pos r_nums_pos = nums_pos;
    Pos prev_trap_offend = nums_pos;
    size_t trap_length;
    bool can_jump_over = false;
    //Search for every trap
    while((trap_length = getNextTrapLength(nums_pos, nums.end())) != 0)
      {
	cout << "Pos: " << nums_pos - nums.begin() << endl;
	cout << "Length: " << trap_length << endl;
	/*
	  If the last element of this trap is also
	  the last element of nums
	*/
	if(nums_pos == nums.end())
	  {
	    //Back trace. See if this trap can be jumped over.
	    for(r_nums_pos = nums_pos - trap_length - 1;
		;--r_nums_pos)
	      {
		//This trap can be jumped over.
		if(nums_pos - r_nums_pos <= *r_nums_pos + 1)
		  {
		    can_jump_over = true;
		    break;
		  }
	    
		if(r_nums_pos == prev_trap_offend)
		  break;
	      }
	  }
	
	/*
	  If the last element of this trap is not 
	  the last element of nums
	*/
	else
	  {
	    //Back trace. See if this trap can be jumped over.
	    for(r_nums_pos = nums_pos - trap_length - 1;
		;--r_nums_pos)
	      {
		cout << "r_nums_pos " << r_nums_pos - nums.begin() << endl;
		//This trap can be jumped over.
		if(nums_pos - r_nums_pos <= *r_nums_pos)
		  {
		    can_jump_over = true;
		    break;
		  }
	    
		if(r_nums_pos == prev_trap_offend)
		  break;
	      }
	  }
	
	prev_trap_offend = nums_pos;
	
	//If this trap cannot be jumped over, then game over
	if(!can_jump_over)
	  return false;

	can_jump_over = false;
      }

    return true;
  }
};

