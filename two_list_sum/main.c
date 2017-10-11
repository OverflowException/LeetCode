#include <iostream>
#include <cstdio>
using std::cout;
using std::endl;

struct ListNode 
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* ptr_1 = l1;
        ListNode* ptr_2 = l2;
	int carry = 0;

	//Generate the head
	int tmp = ptr_1->val + ptr_2->val;
	carry = tmp / 10;
	ListNode* result = new ListNode(tmp % 10);
	ptr_1 = ptr_1->next;
	ptr_2 = ptr_2->next;
	ListNode *ptr_r = result;
      
        while(true)
        {
            if(ptr_1 == NULL)
            {
                if(ptr_2 == NULL)
		  {
		    if(carry)
			ptr_r->next = new ListNode(carry);

                    break;
		  }
                else
                {
                    tmp = ptr_2->val + carry;
                    carry = tmp / 10;
                    ptr_r->next = new ListNode(tmp % 10);
                    ptr_r = ptr_r->next;
                    ptr_2 = ptr_2->next;
                }
            }
            else
            {
                if(ptr_2 == NULL)
                {
                    tmp = ptr_1->val + carry;
                    carry = tmp / 10;
                    ptr_r->next = new ListNode(tmp % 10);
                    ptr_r = ptr_r->next;
                    ptr_1 = ptr_1->next;
                }
                else
                {
                    tmp = ptr_1->val + ptr_2->val + carry;
                    carry = tmp / 10;
                    ptr_r->next = new ListNode(tmp % 10);
                    ptr_r = ptr_r->next;
                    ptr_1 = ptr_1->next;
                    ptr_2 = ptr_2->next;
                }
            }
        }
        return result;
    }
    ListNode* generateList(int* arr, int length);
    void displayList(ListNode* list);
};


ListNode* Solution::generateList(int* arr, int length)
{

  ListNode* result = new ListNode(arr[0]);
  ListNode* ptr = result;
  for(int count = 1; count < length; count++)
    {
      ptr->next = new ListNode(arr[count]);
      ptr = ptr->next;
    }

  return result;
}

void Solution::displayList(ListNode* list)
{
  cout << list->val << "->";
  ListNode* ptr = list->next;
  while(true)
    {
      if(ptr == NULL)
	  break;

      cout<<ptr->val<<"->";
      ptr = ptr->next;
    }
  cout << "<E>" << endl;
}

int main(int argc, char** argv)
{
  Solution* s = new Solution();
  int arr_1[] = {1};
  int arr_2[] = {9, 9};
  ListNode* ln_1 = s->generateList(arr_1, 1);
  ListNode* ln_2 = s->generateList(arr_2, 2);
  s->displayList(ln_1);
  s->displayList(ln_2);
  ListNode* ln_r = s->addTwoNumbers(ln_1, ln_2);
  s->displayList(ln_r);
  return 0;
}
