#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution
{
 public:
  uint32_t reverseBits(uint32_t n)
  {
    uint32_t result = 0;
    uint32_t read_mask = 1;
    uint32_t write_mask = 0x80000000;
    
    for(size_t position = 0; position < 32; position++)
      {
	result |= (bool)(read_mask & n) ? write_mask : 0;  
	read_mask <<= 1;
	write_mask >>= 1;
      }
    return result;
  }
};
