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
 public:
  void recurseOutputLayer(vector<vector<int>>& _layers,
			  TreeNode* _head,
			  size_t _layer_index)
  {
    //Terminate condition
    if(_head == NULL)
      return;

    //A new layer
    if(_layer_index == _layers.size())
      {
	_layers.emplace_back();
	_layers.back().emplace_back(_head->val);
      }
    //Not a new layer
    else
      _layers[_layer_index].emplace_back(_head->val);
    
    recurseOutputLayer(_layers, _head->right, _layer_index + 1);
    recurseOutputLayer(_layers, _head->left, _layer_index + 1);
  }
  
  vector<int> rightSideView(TreeNode* root)
  {
    vector<vector<int>> layers;
    recurseOutputLayer(layers, root, 0);

    const size_t r_length = layers.size();
    vector<int> result(layers.size());
    for(size_t index = 0; index < r_length; index++)
      result[index] = layers[index].front();
    
    return result;
  }
};
