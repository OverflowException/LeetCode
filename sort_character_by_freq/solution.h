#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  template<typename _I>
    _I myFind(_I beg, _I end, typename _I::value_type::first_type c)
    {
      for(; beg != end; ++beg)
	if(beg->first == c)
	  return beg;
      return end;
    }
  
    string frequencySort(string s)
    {
        vector<pair<char, int>> v;
        decltype(v)::iterator v_it;
        for(const char c : s)
        {
            if((v_it = myFind(v.begin(), v.end(), c)) == v.end())
                v.emplace_back(c, 1);
            else
                ++v_it->second;
        }
        
        sort(v.begin(), v.end(), 
	     [=](pair<char, int>& p1, pair<char, int>& p2)
        {
            return p1.second > p2.second;
	});

        
        string result(s.size(), ' ');
        string::iterator s_it = result.begin();
        int curr_freq;
        char curr_char;
        for(v_it = v.begin(); v_it != v.end(); ++v_it)
        {
            curr_char = v_it->first;
            curr_freq = v_it->second;
            do
            {
                --curr_freq;
                *s_it = curr_char;
                ++s_it;
            }while(curr_freq != 0);
        }
        return result;
    }
};
