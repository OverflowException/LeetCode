#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
 private:
  list<pair<int, int>> l_parent_child;
  vector<int> result;
  decltype(l_parent_child)::iterator it;
  
 public:
  void displayPID()
  {
    for(const auto ele : l_parent_child)
      cout << ele.first << " " << ele.second << endl;
  }

  void show(const vector<int>& c)
  {
    for(const int ele : c)
      cout << ele << " ";
    cout << endl;
  }

  
  void recursiveKill(vector<int> kill)
  {
    
    if(kill.empty())
      return;

    cout << "kill" << endl;
    show(kill);
    
    auto rb_it = back_inserter(result);
    copy(kill.begin(), kill.end(), rb_it);


    vector<int> next_kill;
    for(const int k : kill)
      {
	it = l_parent_child.begin();
	while(true)
	  {
	    it = find_if(it, l_parent_child.end(), [=](const pair<int, int>& ele)
			 {
			   return ele.first == k;
			 });

	    if(it == l_parent_child.end())
	      break;

	    cout << "k = " << k << " get kill " << it->second << endl;
	    next_kill.push_back(it->second);
	    it = l_parent_child.erase(it);
	  }
      }
    
    recursiveKill(next_kill);
  }

  vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill)
    {
      auto lb_it = back_inserter(l_parent_child);
      for(int index = 0; index < pid.size(); ++index)
	*lb_it = make_pair(ppid[index], pid[index]);

      
      vector<int> init_kill(1, kill);
      
      recursiveKill(init_kill);
      return result;
    }
};
