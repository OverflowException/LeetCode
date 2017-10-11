#include "solution.h"
#include <sstream>

using std::istringstream;

int main(int argc, char** argv)
{
  if(argc == 1)
    throw std::runtime_error("Please input a string of integers");
  Solution s;
  vector<int> params(argc - 1);
  auto it = params.begin();
  istringstream iss;
  for(int index = 1; index < argc; ++index)
    {
      iss.clear();
      iss.str(argv[index]);
      iss >> *it++;
    }
  cout << "The length of longest increasing subsequence is " << s.lengthOfLIS(params) << endl;
}
