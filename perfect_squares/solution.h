#include <vector>
#include <iostream>
using namespace std;

class Solution
{
 public:
  int leastComponents(int target,
		      const vector<int>& v_square,
		      vector<int>::const_reverse_iterator search_head)
  {    
    int taget_copy = target;
    int result = 0;
    decltype(search_head) working_it;

    while(search_head != v_square.crend())
      {
	test_copy
      }
  }

  
  int numSquares(int n)
  {
    //Generates perfect square vector
    int square_number = 1;
    int root = 1;
    vector<int> square_vector;
    while(square_number <= n)
      {
	square_vector.push_back(square_number);
	square_number += (root << 1) + 1;
	root++;
      }

    int n_copy = n;
    int result = 0;
    int result_min = n;
    vector<int>::const_iterator head_it = square_vector.cend() - 1;
    decltype(head_it) working_it;

    while(head_it >= square_vector.cbegin())
      {
	working_it = head_it;
	while(true)
	  {
	    n -= *working_it;
	    if(n > 0)
	      {
		cout << *working_it << " ";
		result++;
		continue;
	      }

	    else if(n < 0)
	      {
		n += *working_it;
		working_it--;
	      }
	
	    else if(n == 0)
	      {
		cout << *working_it << " ";
		result++;
		break;
	      }
	  }
	cout << "result = " << result << endl;
	if(result < result_min)
	  result_min = result;

	result = 0;
	n = n_copy;
	head_it--;
      }
    
    return result_min;
  }
};
