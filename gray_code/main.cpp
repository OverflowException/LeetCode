#include "solution.h"
#include <iostream>

using std::cout;
using std::endl;


int main(int argc, char** argv)
{
  Solution s;
  auto result = s.grayCode(3);

  for(const auto ele : result)
    cout << ele << " ";
  cout << endl;
}
