#include "solution.h"

int main(int argc, char** argv)
{
  Solution s;
  vector<vector<int>> test{
    {1, 2, 2, 1},
      {3, 1, 2},
	{1, 3, 2},
	  {2, 4},
	    {3, 1, 2},
	      {1, 3, 1, 1}

  };

  
  cout << s.leastBricks(test) << endl;
}
