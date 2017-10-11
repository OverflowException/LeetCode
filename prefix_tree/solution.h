#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <cstdio>

using namespace std;

struct Node
{
  array<Node*, 26> dict;
  bool isend;
  Node() : isend(false){dict.fill(NULL);}
};

class Trie
{
 private:
  Node* trie;
  
 public:
  
  Trie(){trie = new Node; trie->isend = true;}
  void insert(string word);
  bool search(string word);
  bool startsWith(string prefix);
};
