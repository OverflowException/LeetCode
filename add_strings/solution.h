#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
 private:
  inline char d2c(int d){return char(d + '0');}
  inline int c2d(char c){return c - '0';}

 public:
  string addStrings(string num1, string num2)
  {
    string result;
    result.resize(max(num1.size(), num2.size()) + 1);

    string::reverse_iterator r_it_1;
    string::reverse_iterator r_it_2;
    string::reverse_iterator r_it_r = result.rbegin();
    int carry = 0;
    int temp = 0;
    
    for(r_it_1 = num1.rbegin(), r_it_2 = num2.rbegin();
	r_it_1 != num1.rend() && r_it_2 != num2.rend();
	++r_it_1, ++r_it_2, ++r_it_r)
      {
	temp = c2d(*r_it_1) + c2d(*r_it_2) + carry;
	carry = temp / 10;
	*r_it_r = d2c(temp - carry * 10);
      }
    
    decltype(r_it_1) r_it;
    string* sp;
    if(r_it_1 == num1.rend())
      {
	sp = &num2;
	r_it = r_it_2;
      }
    else
      {
	sp = &num1;
	r_it = r_it_1;
      }

    for(;r_it != sp->rend(); ++r_it, ++r_it_r)
      {
	temp = c2d(*r_it) + carry;
	carry = temp / 10;
	*r_it_r = d2c(temp - carry * 10);
      }

    if(carry == 0)
      result.erase(result.begin());
    else
      *result.begin() = d2c(carry);


    return result;
  }
};
