#include <cstdio>

#define MIN_INT (1 << (sizeof(int) * 8 - 1)) //2147483647
#define MAX_INT (MIN_INT - 1)                //-2147483648

int main(int argc char** argv)
{
  printf("sizeof(long long int) = %d\n", sizeof(long long int));
  long long int lTest = 2147483647 + 1;
  printf("lTest = %ld\n", lTest);
  lTest = -2147483648 - 1;
  printf("lTest = %ld\n", lTest);
}
