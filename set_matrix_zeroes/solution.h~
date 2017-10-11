#include <vector>
#include <iostream>

using namespace std;

class Solution
{
 public:
  void setZeroes(vector<vector<int>>& matrix)
  {
    size_t temp_row, temp_column, row_index, column_index;
    size_t height = matrix.size();
    size_t width = matrix.begin()->size();
    
    vector<pair<size_t, size_t>> zero_positions;
    
    for(row_index = 0; row_index < height; row_index++)
      {
	for(column_index = 0; column_index < width; column_index++)
	  {
	    if(matrix[row_index][column_index] == 0)
	      zero_positions.push_back(make_pair(row_index, column_index));
	  }
      }

    size_t row_temp, column_temp;
    for(const auto & ele : zero_positions)
      {
	for(row_temp = 0; row_temp < height; row_temp++)
	  matrix[row_temp][ele.second] = 0;

	for(column_temp = 0; column_temp < width; column_temp++)
	  matrix[ele.first][column_temp] = 0;
      }      
  }  
};
