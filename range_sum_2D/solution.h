#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

class NumMatrix
{
 private:
  vector<vector<int>> sum;
  size_t sum_height;
  size_t sum_width;
 public:
  
  NumMatrix(vector<vector<int>> matrix)
    {
      sum_height = matrix.size() + 1;
      sum_width = matrix.begin()->size() + 1;
      sum.resize(sum_height);
      for(vector<int>& row : sum)
	row.resize(sum_width, 0);
      
      size_t row, column;
      for(row = 1; row < sum_height; ++row)
	for(column = 1; column < sum_width; ++column)
	  sum[row][column] = matrix[row - 1][column - 1]
	    +sum[row][column - 1]
	    + sum[row - 1][column]
	    - sum[row - 1][column - 1];

      Display2D(this->sum);
    }
  int sumRegion(int row1, int col1, int row2, int col2)
  {
    return (sum[row2 + 1][col2 + 1]
	    - sum[row2 + 1][col1]
	    - sum[row1][col2 + 1]
	    + sum[row1][col1]);
      
  }

  void Display2D(vector<vector<int>>& v)
  {
    for(const auto& line : v)
      {
	for(const auto& ele : line)
	  cout << ele << " ";
	cout << endl;
      }
  }
  
};
