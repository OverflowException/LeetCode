#include "solution.h"

int main()
{
  vector<vector<int>> m =
    {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
    };
  NumMatrix s(m);
  cout << s.sumRegion(1, 1, 1, 2) << endl;
}
