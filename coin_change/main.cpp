#include "solution.h"

int main()
{
  Solution s;
  vector<int> v{186, 419, 83, 408};
  cout << s. coinChange(v, 6249) << endl;
  for(const int c : s.composition)
    cout << c << " ";
  cout << endl;
}
