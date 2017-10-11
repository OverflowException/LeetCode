#include <iostream>

using namespace std;

struct ListNode
{
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL){}
};

void display(ListNode* h)
{
  ListNode* ptr = h;
  while(ptr != NULL)
    {
      cout << ptr->val << " ";
      ptr = ptr->next;
    }
  cout << endl;
}


class Solution
{
 public:
  ListNode* deleteDuplicates(ListNode* head)
  {
    if(!head)
      return NULL;
    ListNode* prev_ptr = head;
    ListNode* curr_ptr = prev_ptr->next;
    while(curr_ptr != NULL)
      {
	if(prev_ptr->val == curr_ptr->val)
	  {
	    prev_ptr->next = curr_ptr->next;
	    delete curr_ptr;
	    curr_ptr = prev_ptr -> next;
	  }
	else
	  {
	    prev_ptr = curr_ptr;
	    curr_ptr = curr_ptr->next;
	  }
      }
    return head;
  }
};
