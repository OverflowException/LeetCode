#include "solution.h"

void Solution::generateBinaryTree(Node* head)
{
  int _curr_depth = head->depth;
  if(_curr_depth == 0)
    return;
  
  head->left = new Node(_curr_depth - 1, remain);
  head->right = new Node(_curr_depth - 1, reverse);

  generateBinaryTree(head->left);
  generateBinaryTree(head->right);
}


vector<int> Solution::grayCode(int n)
{ 
  Node* head = new Node(n);
  generateBinaryTree(head);

  curr_code = 0;
  traverseTree(head);
  return result;
}

inline void Solution::reversePos(Node* head)
{
  if(head->stat == remain)
    return;
  else
    curr_code ^= (1 << head->depth);
}

//pre-order
void Solution::traverseTree(Node* head)
{
  reversePos(head);
  if(head->depth == 0)
    {
      result.emplace_back(curr_code);
      return;
    }

  traverseTree(head->left);
  traverseTree(head->right);  
}
