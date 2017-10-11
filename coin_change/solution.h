#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using std::string;
using std::vector;
using std::sort;
using std::cout;
using std::endl;

//Try solving this problem with recursion
class Solution
{
 private:
  string spacer;
  
 public:
  vector<int> composition;
  int recurseCoinChange(int target_amount, vector<int>& coins, vector<int>::const_iterator coins_it)
  {
    int curr_coin = *coins_it;
    int result = target_amount / curr_coin;
    int next_result = 0;
    int residual = target_amount - result * curr_coin;

    ///////////////
    composition.resize(composition.size() + result, curr_coin);
    /////////////
    
    ////////////////////
    spacer.resize((coins_it - coins.begin()), '\t');
    cout << spacer << "coin = " << curr_coin << endl;
    cout << spacer << "Resu = " << result << endl;
    cout << spacer << "resi = " << residual << endl;
    /////////////////////

    //If can be added up just right
    if(residual == 0)
      return result;

    if(coins_it == coins.end() - 1)
      {
	composition.resize(composition.size() - result);
	return -1;
      }
    
    while(true)
      {
	next_result = recurseCoinChange(residual, coins, coins_it + 1);
	  
	if(next_result != -1)
	  return result + next_result;
	
	if(result == 0)
	  return -1;

	composition.pop_back();
	--result;
	residual += curr_coin;
      }
  }
  
  int coinChange(vector<int>& coins, int amount)
  {
    sort(coins.begin(), coins.end(), [](int a, int b){return a > b;});
    
    return recurseCoinChange(amount, coins, coins.begin());
   
  }
};
