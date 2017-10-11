#include <iostream>
#include <sstream>
#include "solution.h"

using namespace std;

int main(int argc, char** argv)
{
  //The first element of this list is empty
  ListNode* sorted = (ListNode*)malloc(sizeof(ListNode));
  cout << "Please input a list of numbers(sorted)" << endl;
  string str_input;
  int int_input;
  ListNode* ptr = sorted;
  getline(cin, str_input);
  istringstream ss(str_input);
  while(ss >> int_input)
    {
      ptr->next = (ListNode*)malloc(sizeof(ListNode));
      ptr = ptr->next;
      ptr->val = int_input;
    }
  
  //Now display the input list
  cout << "Entered: " << endl;
  display(sorted);
  
  Solution s;
  cout << "After deleted duplicated elements:" << endl;
  display(s.deleteDuplicates(sorted->next));
}
