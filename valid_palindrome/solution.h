#include <string>
#include <iostream>

using namespace std;

class Solution
{
 public:
  bool isPalindrome(string s)
  {
    if(s == " ")
      return true;
    string::const_iterator forward_it = s.cbegin();
    string::const_iterator backward_it = s.cend() - 1;

    while(forward_it <= backward_it)
      {
	for(; !isalnum(*forward_it); forward_it++)
	  if(forward_it == s.end())
	    return true;
	for(; !isalnum(*backward_it); backward_it--);
	  
	if(tolower(*forward_it) != tolower(*backward_it))
	  return false;

	backward_it--; forward_it++;
      }

    return true;
  }
  
};
