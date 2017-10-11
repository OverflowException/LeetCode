#include <stack>
#include <vector>
#include <string>
#include <array>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
 public:
  int longestValidParentheses(string s)
  {
    stack<string::difference_type> st;
    vector<array<string::difference_type, 2>> v_pos;    
    
    string::const_iterator s_it;
    const auto s_beg = s.cbegin();

    vector<array<string::difference_type, 2>>::reverse_iterator v_rit;
    
    for(s_it = s_beg; s_it != s.end(); s_it++)
      {
	//'(' is found
 	if(*s_it == '(')
	  st.push(s_it - s_beg);
	//')' is found
	else
	  {
	    if(!st.empty())
	      {
		auto top_temp = st.top();
		st.pop();
		for(v_rit = v_pos.rbegin(); v_rit != v_pos.rend(); v_rit++)
		  {
		    //Adjacent found
		    if(top_temp == (*v_rit)[1] + 1)
		      {
			(*v_rit)[1] = s_it - s_beg;
			break;
		      }
		  }
		//No adjacent
		if(v_rit == v_pos.rend())
		  {
		    v_pos.emplace_back();
		    (*(v_pos.end() - 1))[0] = top_temp;
		    (*(v_pos.end() - 1))[1] = s_it - s_beg;
		  }
	      }
	  }
      }
    
    if(v_pos.empty())
      return 0;

    size_t result = 0;
    size_t temp = result;
    vector<array<string::difference_type, 2>>::iterator v_it;
    for(v_it = v_pos.begin();
	v_it != v_pos.end();
	v_it++)
      {
	temp = (*v_it)[1] - (*v_it)[0];
	result = temp > result ? temp : result;
      }
        
    cout << "v_pos:" << endl;
    for(const auto &ele : v_pos)
      {
	cout << ele[0] << " " << ele[1] << endl;
      }

    return result + 1;
  }
};
