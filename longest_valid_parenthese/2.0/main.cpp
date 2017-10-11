#include "solution.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
  if(argc != 2)
    throw runtime_error("Invalid parameters!");

  fstream s_in;
  s_in.open(argv[1], ios::in);
  if(!s_in)
    throw runtime_error("Cannot find parenthese file!");
    
  string par_str;

  s_in >> par_str;
  
  Solution s;
  cout << s.longestValidParentheses(par_str) << endl;

  s_in.close();
}
