#include "solution.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
  vector<int> tester{1, 2, 2, 1};
  Solution s;
  s.sortColors(tester);
  for(const auto & ele : tester)
    cout << ele << " ";
  cout << endl;
  
  return 0;
}
