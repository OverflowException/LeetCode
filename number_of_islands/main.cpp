#include "solution.h"

int main()
{
  Solution s;
  vector<vector<char>> test{{'1', '1', '1'},
      {'1', '1', '1'},
	{'0', '1', '1'},
	  {'0', '0', '0'},
	    {'1', '1', '1'}};

  cout << s.numIslands(test) << endl;
}
  
