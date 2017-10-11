#include <cstdio>
#include <iostream>

using std::cout;
using std::endl;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL){}
};

class Solution
{
 public:
  ListNode* oddEvenList(ListNode* head)
  {
    if(head == NULL || head->next == NULL)
      return head;

    //Now the list should be at least 2 nodes long
    ListNode *oddHead = head;
    ListNode *oddTail = head;
    ListNode *evenHead = head->next;
    ListNode *evenTail = head->next;
    
    ListNode *iter = evenTail->next;
    
    //Beware of the initial and terminal situation
    while(iter)
      {
	iter = evenTail->next;
	  
	evenTail = evenTail->next = iter->next;
	oddTail = oddTail->next = iter;
	iter->next = evenHead;
	
	if(evenTail != NULL)
	  iter = evenTail->next;
	else
	  break;
      }
    return oddHead;
  }
};
