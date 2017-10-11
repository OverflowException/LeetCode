#include "solution.h"
#include <iostream>
#include <algorithm>

using namespace std;

inline bool Solution::oneLetterDifference(string::const_iterator a_start, string::const_iterator a_end, string::const_iterator b_start)
{
  size_t difference_count = 0;
  for(;a_start != a_end; a_start++, b_start++)
    difference_count += (*a_start != *b_start) ? 1 : 0;

  return difference_count == 1;
}

void Solution::generateGraph(unordered_map<string, Node*>& m_word_node, string& beginWord, string& endWord, vector<string>& wordList)
{
  Node* working_ptr = NULL;
  size_t maxPossibleDistance  = wordList.size();
  //Assume that every word in the word list is unique
  //Traverse every word in the wordList
  for(const auto & w: wordList)
    {
      working_ptr = new Node(maxPossibleDistance);
      //Traverse all exsiting nodes
      for(const auto & p : m_word_node)
	{
	  //If there is only one different letter
	  if(oneLetterDifference(p.first.cbegin(), p.first.cend(),
				 w.cbegin()))
	    {
	      //Associate two nodes
	      working_ptr->associates.push_back(p.second);
	      p.second->associates.push_back(working_ptr);
	    }
	}
      //Add current node to map
      m_word_node.insert(make_pair(w, working_ptr));
    }
}

int Solution::ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
  unordered_map<string, Node*> m_word_node;
  generateGraph(m_word_node, beginWord, endWord, wordList);

  //mark head
  Node* head = m_word_node[beginWord];
  head->min_distance = 0;

  //mark end
  Node* end = m_word_node[endWord];
  
  
  //Debug
  for(const auto & ele : m_word_node)
    {
      cout << ele.first << "\t";
      cout << ele.second->associates.size() << "\t";
      cout << ele.second->min_distance << endl;
    } 

  recursiveTrack(head);
  cout << "result = " << end->min_distance << endl;
}

void Solution::recursiveTrack(Node* head)
{
  cout << "Tracking " << head << endl;
  //If every associated node of this node was tarcked
  if(head->associates.empty())
    return;

  else
    {
      Node* temp;
      list<Node*>* curr_list_ptr = &(head->associates);
      list<Node*>* next_list_ptr;
      for(list<Node*>::iterator list_it = curr_list_ptr->begin();
	  list_it != curr_list_ptr->end(); list_it++)
	{
	  (*list_it)->min_distance = head->min_distance + 1 <
	    (*list_it)->min_distance ?
	    head->min_distance + 1 : (*list_it)->min_distance;

	  next_list_ptr = &((*list_it)->associates);
	  next_list_ptr->erase(find(next_list_ptr->begin(),
			   next_list_ptr->end(),
				    head));
	}
      //recursiveTrack(temp);
    }
}
