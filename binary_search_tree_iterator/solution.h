#include <tuple>
#include <stack>

using namespace std;

struct TreeNode
 {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class BSTIterator
{
 private:
  //node position,  right child not traversed
  stack<tuple<TreeNode*, bool>> pos_stack;
  TreeNode* curr_pos;

  void pushToLeftBottom(TreeNode* const& base)
  {
    bool rNT;
    curr_pos = base;
    while(curr_pos != NULL)
      {
	rNT = (curr_pos->right == NULL) ? false : true;
	curr_pos = curr_pos->left;
	pos_stack.push(make_tuple(curr_pos, rNT));
      }
  }
  
 public:
  BSTIterator(TreeNode *root)
    {
      pushToLeftBottom(root);
    }

    /** @return whether we have a next smallest number */
  bool hasNext()
  {
    return pos_stack.empty();
  }

    /** @return the next smallest number */
  int next()
  {
    auto& node = pos_stack.top();
    TreeNode*& node_ptr = get<0>(node);
    bool& node_rNT = get<1>(node);
    
    int result = node_ptr->val;
    
    if(node_rNT)
      {
	node_rNT = false;
	pushToLeftBottom(node_ptr->right);
      }
    else
      pos_stack.pop();
      
    return result;
  }
};
