#include "solution.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
  if(argc == 1)
    {
      cout << "Not enough parameters!" << endl;
      return 0;
    }

  Solution s;
  //When initializing with {}, make sure the elements are unique
  //vector<int> test_case = {-2, 1, -3 ,4, -1, 2, 1 -5, 4};
  vector<int> test_case(argc - 1);
  for(auto it = test_case.begin(); it != test_case.end(); it++)
    {
      *it = atoi(argv[it - test_case.begin() + 1]);
    }

  cout << "Input vector: ";
  for(auto ele : test_case)
    cout << ele << " ";
  cout<< endl;

  cout << "Final result = " << s.maxSubArray(test_case) << endl;

  return 0;
}
