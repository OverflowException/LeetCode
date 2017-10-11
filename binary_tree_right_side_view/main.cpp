#include "solution.h"

int main(int argc, char** argv)
{
  //l0
  TreeNode *root = new TreeNode(1);
  //l1
  TreeNode *rl = new TreeNode(2);
  root->left = rl;
  TreeNode *rr = new TreeNode(3);
  root->right = rr;
  //l2
  TreeNode *rll = new TreeNode(4);
  rl->left = rll;
  TreeNode *rlr = new TreeNode(5);
  rl->right = rlr;
  TreeNode *rrl = new TreeNode(6);
  rr->left = rrl;
  TreeNode *rrr = new TreeNode(7);
  rr->right = rrr;
  
  TreeNode *rlrl = new TreeNode(8);
  rlr->left = rlrl;
  TreeNode *rlrr = new TreeNode(9);
  rlr->right = rlrr;  
  
  Solution s;
  s.rightSideView(root);
  return 0;
}
