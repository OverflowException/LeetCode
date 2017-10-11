#include <vector>
#include <cstdio>

using std::vector;

enum AltStat
  {
    remain,
    reverse
  };

struct Node
{
  Node* left;
  Node* right;
  int depth;
  AltStat stat;
  Node(int d, AltStat s = remain) : left(NULL), right(NULL), depth(d), stat(s){};
};

class Solution
{
  
 private:
  int curr_code;
  vector<int> result;
  //Depth starts from total_depth.
  //The depth of every leaf is 0.
  void generateBinaryTree(Node* head);
  void reversePos(Node* head);
  void traverseTree(Node* head);
  
 public:  
  vector<int> grayCode(int n);
};
