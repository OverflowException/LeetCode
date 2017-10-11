#include "solution.h"

int main(int argc, char**argv)
{
  Solution s;
  vector<int> ppid{5,8,4,5,10,5,3,8,0};
  vector<int>  pid{6,1,3,9,5,8,7,4,10};

  auto result = s.killProcess(pid, ppid, 5);

  cout << "result" << endl;
  for(const int ele : result)
    cout << ele << endl;
}
