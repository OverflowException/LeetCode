#include <vector>
#include <iostream>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
 private:
  vector<int> _sorted_container;
  vector<int>::iterator _curr_it;
  
 public:
  void inOrderTraverse(TreeNode* node)
  {
    if(node == NULL)
      return;

    if(_curr_it != _sorted_container.end())
      inOrderTraverse(node->left);
    else
      return;
	
    if(_curr_it != _sorted_container.end())
      *_curr_it++ = node->val;
    else
      return;

    if(_curr_it != _sorted_container.end())
      inOrderTraverse(node->right);
    else
      return;
  }
  
  int kthSmallest(TreeNode* root, int k)
  {
    _sorted_container.resize(k);
    _curr_it = _sorted_container.begin();
    inOrderTraverse(root);
    return _sorted_container.back();
  }
};
