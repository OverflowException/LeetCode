#include "solution.h"

int main(int argc, char** argv)
{
  if(argc < 2)
    throw std::runtime_error("Not enough parameters!");
  Solution s;
  s.bulbSwitch(atoi(argv[1]));
}
