#include <stdio.h>
#include <stdlib.h>

int* twosum(int* nums, int numsSize, int target);

int main(int argc, char** argv)
{
  if(argc != 2)
    {
      printf("Invalid input parameters!\n");
      return 1;
    }

  int nums[] = {14, 2, 5, 3, 13, 21, 9, 10}; 
  int* r = twosum(nums, 8, atoi(argv[1]));

  printf("The indeces are %d, %d\n", r[0], r[1]);
  printf("The result numbers are %d, %d\n", nums[r[0]], nums[r[1]]);
  return 0;
}

int* twosum(int* nums, int numsSize, int target)
{

  int counter_1 = 0;
  int counter_2 = 0;
  int comple = 0;
  int* result = (int*)malloc(2 * sizeof(int));
  for(counter_1 = 0; counter_1 < numsSize - 1; counter_1++)
    {
      comple = target - nums[counter_1];
      for(counter_2 = counter_1 + 1; counter_2 < numsSize; counter_2++)
	{
	  if(comple == nums[counter_2])
	    {
	      result[0] = counter_1;
	      result[1] = counter_2;
	      return result;
	    }
	}
    }

  result[0] = -1;
  result[1] = -1;
  return result;
}
