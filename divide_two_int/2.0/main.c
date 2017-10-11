#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MIN_INT (1 << (sizeof(int) * 8 - 1)) //2147483647
#define MAX_INT (MIN_INT - 1)                //-2147483648

int divide(int divident, int divisor);
 
int main(int argc, char** argv)
{
  if(argc != 3)
    {
      printf("divide divident divisor");
      return 0;
    }
  int divident = atoi(argv[1]);
  int divisor = atoi(argv[2]);
  printf("divident = 0x%X\n", divident);
  printf("divisor = 0x%X\n", divisor);
  printf("final result = %d\n", divide(divident, divisor));
  //This problem cannot be solved by long long int
  long long int test_1 = (long long int)MAX_INT;
  printf("test_1 = %lx\n", test_1 * 2);
}

int divide(int divident, int divisor)
{
  if(divisor == 0)
    return MAX_INT;

  //Record the signals of both number.
  //And convert both of them to positive
  int dividentSig = divident & 0x80000000;
  int divisorSig = divisor & 0x80000000;
  divident = dividentSig ? -divident : divident;
  divisor = divisorSig ? -divisor : divisor;
  /////////////////////////
  printf("unsigned divident = %d, unsigned divisor = %d\n", divident, divisor);


  int dividentMSB;
  int divisorMSB;

  int MSBfilter = 0x40000000;

  //Fail when divisor = 0
  //Get dividentMSB
  for(MSBfilter = 0x40000000, dividentMSB = 31; ; MSBfilter >>= 1)
    {
      if(!(MSBfilter & divident))
	dividentMSB--;

      else
	break;
    }
  printf("dividentMSB = %d\n", dividentMSB);

  //Get divisorMSB
  for(MSBfilter = 0x40000000, divisorMSB = 31; ; MSBfilter >>= 1)
    {
      if(!(MSBfilter & divisor))
	divisorMSB--;

      else
	break;
    }
  printf("divisorMSB = %d\n", divisorMSB);

  int MSBdiff = dividentMSB - divisorMSB;
  int divisorPower = divisor << MSBdiff; //The result of divisor bit-shift
  int binaryPower = 1 << MSBdiff;      //The result of binary bit-shift
  long long int divisorAccu = 0;
  int result = 0;

  for(; MSBdiff >= 0; MSBdiff--)
    {
      if((divisorAccu += divisorPower) <= divident)
	result += binaryPower;
      else
	divisorAccu -= divisorPower;

      printf("binaryPower = %d, divisorAccu = %ld, result = %d\n", binaryPower, divisorAccu, result);
      divisorPower >>= 1;
      binaryPower >>= 1;
      if(divisorAccu == divident)
	break;
    }

  return result;
}
