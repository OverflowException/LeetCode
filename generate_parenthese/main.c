#include <stdio.h>
#include <stdlib.h>

/*index = 1, content = '('
  index = -1, content = ')' */
typedef struct treeNode 
{
  char index;           //index = -1 or +1
  char accumulatedIndex; //accumulate all the indeces along path
  char content;      //{'(', '\0'} or {')', '\0'}
  struct treeNode* left;
  struct treeNode* right;
  struct treeNode* father;
}yinYangNode;

//Record valid answer of parenthese
typedef struct chainNode
{
  yinYangNode* leafPtr;
  struct chainNode* next;
  //Next two attribute only works for head chainNode
  struct chainNode* tailPtr;
  int length;
}resultNode;


//root should be malloced before this function is called
void GenerateYinYangTree(yinYangNode* root, int depth, char init_index, yinYangNode* father, resultNode* head);
void ReleaseYinYangTree(yinYangNode* root);
//To generate a chain list of valid leaf pointer
void AppendResult(resultNode* head, yinYangNode* leaf);
void ExtractResultStr(resultNode* head, char** strArr, int strLength);
char** generateParenthesis(int n, int* returnSize);


//The total number of valid parentheses is n*(n-1)/2+1
int main(int argc, char** argv)
{
  if(argc != 2)
    {
      printf("Please input number of parenthesis!\n");
      return 0;
    }
  int returnSize = 0;
  char** finalResult = generateParenthesis(atoi(argv[1]), &returnSize);

  printf("returnSize = %d\n", returnSize);
  //Display
  int count;
  for(count = 0; count < returnSize; count++)
    {
      //printf("Here?");
      printf("%s\n", finalResult[count]);
    }

  return 0;
}

char** generateParenthesis(int n, int* returnSize)
{
  yinYangNode* tree = (yinYangNode*)malloc(sizeof(yinYangNode));
  resultNode* chain = (resultNode*)malloc(sizeof(resultNode));
  //Initialize result chain
  chain->length = 0;
  chain->tailPtr = chain;
  GenerateYinYangTree(tree, n * 2, 1, NULL, chain);
  *returnSize = chain->length;
  char** finalResult = (char**)malloc(*returnSize * sizeof(char*));
  ExtractResultStr(chain, finalResult, n * 2);
  return finalResult;
}

void GenerateYinYangTree(yinYangNode* root, int depth, char init_index, yinYangNode* father, resultNode* head)
{
  root->father = father;
  root->index = init_index;
  root->accumulatedIndex = father == NULL ? init_index : father->accumulatedIndex + root->index; 
  //Check if there is a ')' without matching '('
  if(root->accumulatedIndex < 0)
    {
      root->left = NULL;
      root->right = NULL;
      //printf("Stop at floor %d\n", depth);
      return;
    }

  root->content = init_index > 0 ? '(' : ')';
  depth--;
  //Have not reached required depth yet
  if(depth > 0)
    {
      root->left = (yinYangNode*)malloc(sizeof(yinYangNode));
      root->right = (yinYangNode*)malloc(sizeof(yinYangNode));
      GenerateYinYangTree(root->left, depth, -1, root, head);
      GenerateYinYangTree(root->right, depth, 1, root, head);
    }
  //Already reached required depth
  else 
    {
      root->left = NULL;
      root->right = NULL;
      //printf("%d\t", root->accumulatedIndex);
      //parentheses matched
      if(root->accumulatedIndex == 0)
	{
	  /*while(root != NULL)
	    {
	      printf("%c", root->content);
	      root = root->father;
	    }
	    printf("\n");*/
	  AppendResult(head, root);
	}
    }
  return;
}

void ReleaseYinYangTree(yinYangNode* root)
{
}

//This makes the head of result chain list meaningless
//So remember to read this chain from head->next
void AppendResult(resultNode* head, yinYangNode* leaf)
{
  head->tailPtr->next = (resultNode*)malloc(sizeof(resultNode));
  resultNode* tempPtr = head->tailPtr->next;
  head->tailPtr = tempPtr;
  head->length++;
  /////////////////
  //printf("head: length = %d\n", head->length);
  tempPtr->next = NULL;
  tempPtr->leafPtr = leaf;
} 

void ExtractResultStr(resultNode* head, char** strArr, int strLength)
{
  int totalResultNum = head->length;
  yinYangNode* leafTempPtr;
  resultNode* resultTempPtr;

  int resultCount, strElementCount;
  resultTempPtr = head->next;
  for(resultCount = 0; resultCount < totalResultNum; resultCount++)
    {
      strArr[resultCount] = (char*)malloc((strLength + 1) * sizeof(char));
      strArr[resultCount][strLength] = '\0';
      leafTempPtr = resultTempPtr->leafPtr;
      for(strElementCount = strLength - 1; strElementCount >= 0; strElementCount--)
	{	
	  strArr[resultCount][strElementCount] = leafTempPtr->content;
	  leafTempPtr = leafTempPtr->father;
	}
      resultTempPtr = resultTempPtr->next;
      //printf("%s\n", strArr[resultCount]);
    }
}
