#ifndef _SOLUTION
#define _SOLUTION

#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
 public:
  bool isValid(string s)
  {
    stack<char> st;
    char curr;
    char ascii_span;
    for(auto s_it = s.cbegin(); s_it != s.cend(); s_it++)
      {
	curr = *s_it;
	if(curr == '(' || curr == '[' || curr == '{')
	  st.push(curr);
	else if(curr == ')' || curr == ']' || curr == '}')
	  {
	    if(!st.empty())
	      {
		ascii_span = curr - st.top();
		if(ascii_span == 1 || ascii_span == 2)
		  {
		    st.pop();
		    continue;
		  }
		else
		  return false;
	      }
	    else
	      return false;
	  }	  
      }
    return st.empty();
  }
};

#endif

