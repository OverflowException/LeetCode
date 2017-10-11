#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inPlaceRotate(int** matrix, int matrixRowSize, int matrixColSize);
void allocPlaceRotate(int** matrix, int matrixRowSize, int matrixColSize);
void principalDiagonalSym(int** matrix, int rank);
void verticalAxisSym(int** matrix, int rank);
void swap(int* a, int* b);
void displayMatrix(int** matrix, int rank);

int main(int argc, char** argv)
{
  int rank = 7;
  int** test = (int**)malloc(rank * sizeof(int*));
  printf("main : Initial test address = %d\n", test);
  int rowCount, columnCount;
  srand((unsigned)time(NULL));
  for(rowCount = 0; rowCount < rank; rowCount++)
    {
      test[rowCount] = (int*)malloc(rank * sizeof(int));
      for(columnCount = 0; columnCount < rank; columnCount++)
	test[rowCount][columnCount] = rand() % 10;
    }
  printf("Original:\n");
  displayMatrix(test, rank);
  printf("Processed:\n");
  allocPlaceRotate(test, rank, rank);
  printf("main : processed test address = %d\n", test);
  displayMatrix(test, rank);
  return 0;
}

void inPlaceRotate(int** matrix, int matrixRowSize, int matrixColSize)
{
  principalDiagonalSym(matrix, matrixRowSize);
  verticalAxisSym(matrix, matrixRowSize);
}

void allocPlaceRotate(int** matrix, int matrixRowSize, int matrixColSize)
{
  int** rotatedMatrix = (int**)malloc(matrixRowSize * sizeof(int*));
  int rowCount, columnCount;
  for(rowCount = 0; rowCount < matrixRowSize; rowCount++)
    {
      rotatedMatrix[rowCount] = (int*)malloc(matrixRowSize * sizeof(int));
      for(columnCount = 0; columnCount < matrixRowSize; columnCount++)
	rotatedMatrix[rowCount][columnCount] = matrix[matrixRowSize - columnCount - 1][rowCount];
    }

  for(rowCount = 0; rowCount < matrixRowSize; rowCount++)
    {
      for(columnCount = 0; columnCount < matrixRowSize; columnCount++)
	matrix[rowCount][columnCount] = rotatedMatrix[rowCount][columnCount];
    }
}

void principalDiagonalSym(int** matrix, int rank)
{
  int rowCount, columnCount;
  for(rowCount = 0; rowCount < rank; rowCount++)
    {
      for(columnCount = 0; columnCount < rowCount; columnCount++)
	swap(&matrix[rowCount][columnCount], &matrix[columnCount][rowCount]);
    }
}

void verticalAxisSym(int** matrix, int rank)
{
  int rowCount, columnCount;
  int middle = (int)(rank / 2);
  for(rowCount = 0; rowCount < rank; rowCount++)
    {
      for(columnCount = 0; columnCount < middle; columnCount++)
	swap(&matrix[rowCount][columnCount], &matrix[rowCount][rank - columnCount - 1]);
    }
}

void swap(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void displayMatrix(int** matrix, int rank)
{
  int rowCount, columnCount;
  for(rowCount = 0; rowCount < rank; rowCount++)
    {
      for(columnCount = 0; columnCount < rank; columnCount++)
	{
	  printf("%d ", matrix[rowCount][columnCount]);
	}
      printf("\n");
    }
}
