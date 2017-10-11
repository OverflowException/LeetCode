#include "solution.h"

inline void displayList(ListNode* head)
{
  for(; head != NULL; head = head ->next)
    cout << head->val << " ";
  cout << endl;
}

int main(int argc, char** argv)
{
  ListNode *head = new ListNode(1);
  ListNode *iter = head;
  for(size_t index = 2; index <= 8; ++index, iter = iter->next)
    iter->next = new ListNode(index);

  cout << "Generated: " << endl;
  displayList(head);
  
  Solution s;
  head = s.oddEvenList(head);

  cout << "Processed: " << endl;
  displayList(head);
}
