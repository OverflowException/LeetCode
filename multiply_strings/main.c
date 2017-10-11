#include <stdio.h>
#include <stdlib.h>

char* multiply(char* num1, char* num2);
void displayProcess(int** p, int lengthShort, int lengthLong);

#define A 32U
#define B 32

int main(int argc, char** argv)
{
  printf("A= %u\n", (1 << 31) + A);
  printf("B= %d\n", (1 << 31) + B);
  printf("unsigned int: %d, %d\n", sizeof(unsigned int), sizeof(int));

  if(argc != 3)
    {
      printf("Invalid parameters!\n");
      return 0;
    }

  printf("result = %s\n", multiply(argv[1], argv[2]));
  return 0;
}

char* multiply(char* num1, char* num2)
{
  int num1Length, num2Length;
  int count;

  //Get length
  for(count = 0; num1[count] != '\0'; count++);
  num1Length = count;

  for(count = 0; num2[count] != '\0'; count++);
  num2Length = count;

  //Get the shorter string
  int lengthShort, lengthLong;
  char *ptrShort, *ptrLong;
  int** processBuffer;
  if(num1Length < num2Length)
    {
      ptrShort = num1;
      ptrLong = num2;

      lengthShort = num1Length;
      lengthLong = num2Length;
    }
  else
    {
      ptrShort = num2;
      ptrLong = num1;

      lengthShort = num2Length;
      lengthLong = num1Length;
    }

  int rowCount, columnCount;
  processBuffer = (int**)malloc(lengthShort * sizeof(int*));
  for(rowCount = 0; rowCount < lengthShort; rowCount++)
    {
      processBuffer[rowCount] = (int*)malloc((lengthLong + lengthShort) * sizeof(int)); //1 extra for carry
      for(columnCount = 0; columnCount < lengthLong + lengthShort; columnCount++)
	processBuffer[rowCount][columnCount] = 0;
    }

  int carry = 0;
  int singleDigitMul, actualColumn;
  for(rowCount = 0; rowCount < lengthShort; rowCount++)
    {
      carry = 0;
      for(columnCount = lengthLong; columnCount >= 1; columnCount--)
	{
	  singleDigitMul = (ptrShort[lengthShort - 1 - rowCount] - '0') * (ptrLong[columnCount - 1] - '0');
	  //printf("Single digit multiply = %d\n", singleDigitMul);
	  singleDigitMul += carry;
	  actualColumn = columnCount + lengthShort - rowCount - 1;
	  processBuffer[rowCount][actualColumn] = singleDigitMul % 10;
	  carry = (int)(singleDigitMul / 10);
	}
      processBuffer[rowCount][actualColumn - 1] = carry;
    }
  displayProcess(processBuffer, lengthShort, lengthLong);

  char* result = (char*)malloc(lengthShort + lengthLong + 1); //1 extra for '\0'
  int resultDigit;
  result[lengthLong + lengthShort] = '\0';
  //Generate every digit
  carry = 0;
  for(columnCount = lengthLong + lengthShort - 1; columnCount > 0; columnCount--)
    {
      resultDigit = 0;
      result[columnCount] = 0;
      for(rowCount = 0; rowCount < lengthShort; rowCount++)
	resultDigit += processBuffer[rowCount][columnCount];
      resultDigit += carry;

      carry = (int)(resultDigit / 10);
      resultDigit -= carry * 10;

      result[columnCount] = (char)(resultDigit + '0');
    }
  result[0] = carry + processBuffer[lengthShort - 1][0] + '0';

  char* finalResult;
  if(result[0] == '0' && result[1] == '0')
    {
      finalResult = (char*)malloc(2 * sizeof(char));
      finalResult[0] = '0';
      finalResult[1] = '\0';
    }
  else if(result[0] == '0')
    {
      /*finalResult =(char*)malloc((lengthShort + lengthLong) * sizeof(char));
      for(columnCount = 0; columnCount < lengthShort + lengthLong; columnCount++)
      finalResult[columnCount] = result[columnCount + 1];*/
      finalResult = result + 1;
    }
  else
    finalResult = result;

  return finalResult;
}


void displayProcess(int** p, int lengthShort, int lengthLong)
{
  int columnCount, rowCount;
  for(rowCount = 0; rowCount < lengthShort; rowCount++)
    {
      for(columnCount = 0; columnCount < lengthLong + lengthShort; columnCount++)
	printf("%d ", p[rowCount][columnCount]);

      printf("\n");
    }
}
