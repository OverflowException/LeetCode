#ifndef _SOLUTION
#define _SOLUTION

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
  const static size_t upper_index = 1;
  const static size_t left_index = 1;
  
public:
  void recurseWipeOutIslands(vector<vector<char>>& g, size_t _row,
			     size_t _col)
  {
    if(g[_row][_col] == '0')
      return;

    g[_row][_col] = '0';
    recurseWipeOutIslands(g, _row - 1, _col);
    recurseWipeOutIslands(g, _row + 1, _col);
    recurseWipeOutIslands(g, _row, _col - 1);
    recurseWipeOutIslands(g, _row, _col + 1);
  }
  
  int numIslands(vector<vector<char>>& grid)
  {
    if(grid.empty())
      return 0;
    
    size_t bottom_index = grid.size();    
    size_t right_index = grid.begin()->size();
    
    vector<vector<char>> wrapped_grid(bottom_index + 2);
    wrapped_grid[0].assign(right_index + 2, '0');
    for(size_t index = 1; index <= bottom_index; index++)
      {
	wrapped_grid[index].push_back('0');
	wrapped_grid[index].insert(wrapped_grid[index].end(),
				   grid[index - 1].begin(),
				   grid[index - 1].end());
	wrapped_grid[index].push_back('0');
      }
    wrapped_grid[bottom_index + 1].assign(right_index + 2, '0');

    int result = 0;
    size_t row_index, col_index;
    for(row_index = upper_index; row_index <= bottom_index;
	row_index++)
      for(col_index = left_index; col_index <= right_index;
	  col_index++)
	if(wrapped_grid[row_index][col_index] == '1')
	  {
	    result++;
	    recurseWipeOutIslands(wrapped_grid, row_index, col_index);
	  }

    return result;
  }
};

#endif
