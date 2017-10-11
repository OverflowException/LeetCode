#include <list>
#include <string>
#include <vector>
#include <deque>

using namespace std;

class Solution
{
 public:
  string simplifyPath(string path)
  {
    //vector<string::value_type> buffer_1;
    //list<decltype(buffer_1)> buffer_2;
    list<list<string::value_type>> buffer;
    auto curr_buffer_seg = buffer.begin();
    
    for(const auto ele : path)
      {
	if(ele == '/')
	  {
	    buffer.emplace_back();
	    curr_buffer_seg = --buffer.end();
	  }
	  
	else
	  curr_buffer_seg->push_back(ele);
      }
    //Shrink list
    const decltype(buffer)::value_type hold_pattern = {'.'};
    const decltype(buffer)::value_type back_pattern = {'.', '.'};

    auto buffer_it = buffer.begin();
    while(buffer_it != buffer.end())
      {
	//back
	if(*buffer_it == back_pattern)
	  {
	    //Not home directory
	    if(buffer_it != buffer.begin())
	      buffer_it = buffer.erase(buffer.erase(--buffer_it));
	    //Is a home directory
	    else
	      buffer_it = buffer.erase(buffer_it);
	  }
	//hold
	else if(*buffer_it == hold_pattern || buffer_it->empty())
	  buffer_it = buffer.erase(buffer_it);
	//common directory detected
	else
	  buffer_it++;
      }

    if(buffer.empty())
      return "/";
    
    vector<char> v_result;
    for(const auto& ele : buffer)
      {
	v_result.emplace_back('/');
	copy(ele.begin(), ele.end(), back_inserter(v_result));
      }
    
    
    string result(v_result.begin(), v_result.end());
    return result;
  }
};
