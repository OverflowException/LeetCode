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
    if(s.empty())
      return 0;
    
    typedef string::const_iterator Position;
    stack<Position> st;

    string::const_iterator s_it;
    for(s_it = s.begin(); s_it != s.end(); s_it++)
      {
	//'(' found
	if(*s_it == '(')
	  st.push(s_it);
	//')' found
	else
	  {
	    if(!st.empty())
	      {
		if(*st.top() == '(')
		  st.pop();
		else
		  st.push(s_it);
	      }
	    else
	      st.push(s_it);
	  }
      }
    st.push(s.cend());
    
    int result = 1;
#ifdef _DEBUG
    cout << "s.size() = " << s.size() << endl;
    while(!st.empty())
      {
	cout << st.top() - s.cbegin() << " ";
	st.pop();
      }
    cout << endl;
#endif
#ifndef _DEBUG
    //if stack size is 1, the string is completely valid
    if(st.size() == 1)
      return s.size();

    int diff = 0;
    Position prev_pos;
    Position curr_pos = st.top();
    while(!st.empty())
      {
	prev_pos = curr_pos;
	curr_pos = st.top();
	st.pop();
	diff = prev_pos - curr_pos;
	result = result >= diff ? result : diff;
      }
    result--;
    result = result >= curr_pos - s.begin() ?
      result : curr_pos - s.begin();
    //if result = 1, then there are no valid parentheses
#endif
    return result;
  }
};
