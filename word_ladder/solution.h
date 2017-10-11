#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

struct Node
{
  list<Node*> associates;
  size_t trackedAssociates;
  size_t min_distance;
  Node(size_t maxPossibleDistance) : trackedAssociates(0), min_distance(maxPossibleDistance){}
};

class Solution
{
 public:
  inline bool oneLetterDifference(string::const_iterator a_start, string::const_iterator a_end, string::const_iterator b_start);
  
  //Generate web, and returns the vector of independent heads
  //Returns a pair containing a pointer to source word,
  //and a pointer to target word
  void generateGraph(unordered_map<string, Node*>& m_word_node, string& beginWord, string& endWord, vector<string>& wordList);
  
  int ladderLength(string beginWord, string endWord, vector<string>& wordList);

  void recursiveTrack(Node* head);
};
