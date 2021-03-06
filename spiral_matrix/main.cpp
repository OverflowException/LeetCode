#include "solution.h"
#include <iostream>
#include <stack>

using namespace std;

 int main(int argc, char** argv)
{
  Solution s;
  vector<vector<int>> input = 
    {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16},
      {17, 18, 19, 20}
    };
  vector<int> result = s.spiralOrder(input);
  
  for(auto& ele : result)
    cout << ele << " ";
  cout << endl;
  
  return 0;
}
