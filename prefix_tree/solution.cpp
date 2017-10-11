#include "solution.h"

void Trie::insert(string word)
{
  Node* curr_node = trie;
  //Do NOT use reference here!
  //After a reference was initialized, it cannot be altered.
  array<Node*, 26>* curr_node_dict = &curr_node->dict;
  size_t dict_index;
  
  for(const auto ch : word)
    {
      dict_index = ch - 'a';
      
      if((*curr_node_dict)[dict_index] == NULL)
	(*curr_node_dict)[dict_index] = new Node;

      curr_node = (*curr_node_dict)[dict_index];
      curr_node_dict = &curr_node->dict;
    }

  curr_node->isend = true;
}

bool Trie::search(string word)
{
  Node* curr_node = trie;
  array<Node*, 26>* curr_node_dict = &curr_node->dict;
  size_t dict_index;
  
  for(const auto ch : word)
    {
      dict_index = ch - 'a';
      
      if((*curr_node_dict)[dict_index] == NULL)
	return false;
      
      curr_node = (*curr_node_dict)[dict_index];
      curr_node_dict = &curr_node->dict;
    }

  return curr_node->isend;
     
}

bool Trie::startsWith(string prefix)
{
  Node* curr_node = trie;
  array<Node*, 26>* curr_node_dict = &curr_node->dict;
  size_t dict_index;
  
  for(const auto ch : prefix)
    {
      dict_index = ch - 'a';
      
      if((*curr_node_dict)[dict_index] == NULL)
	return false;

      curr_node = (*curr_node_dict)[dict_index];
      curr_node_dict = &curr_node->dict;
    }

  return true;
}
