#include "solution.h"
#include <cstdlib>

int main(int argc, char** argv)
{
  if(argc < 2)
    throw std::runtime_error("Input an integer!");
  Solution s;
  std::cout << s.integerBreak(atoi(argv[1])) << std::endl;
}
