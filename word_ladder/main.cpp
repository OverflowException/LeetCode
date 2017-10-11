#include <iostream>
#include "solution.h"
#include <map>

using namespace std;

int main(int argc, char** argv)
{
  Solution s;
  vector<string> v_test{"hit", "hot", "dog", "dot", "lot", "log", "cog", "lom", "dof"};
  s.ladderLength("hit", "cog", v_test);

  
  return 0;
}
