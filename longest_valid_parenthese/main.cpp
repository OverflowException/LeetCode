#include "solution.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
  if(argc != 2)
    {
      cout << "Invalid parameters" << endl;
      return 0;
    }

  Solution s;
  cout << s.longestValidParentheses(argv[1]) << endl;
  
}
