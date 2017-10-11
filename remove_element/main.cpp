#include "solution.h"

int main(int argc, char** argv)
{
  vector<int> v;
  for(int count = 1; count < argc; count++)
    v.push_back(atoi(argv[count]));
  
  Solution s;
  cout << s.removeElement(v, 3) << endl;
  
  return 0;
}
