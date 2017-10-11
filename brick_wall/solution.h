#include <vector>
#include <iostream>

using namespace std;

template<typename _C>
void show2D(_C c)
{
  for(const auto& r : c)
    {
      for(const auto& ele : r)
	cout << ele << " ";
      cout << endl;
    }
}


class Solution
{
 public:
  int leastBricks(vector<vector<int>>& wall)
  {
    vector<vector<int>> sum = wall;    
    size_t r_index, c_index;
    for(r_index = 0; r_index < wall.size(); ++r_index)
      for(c_index = 1; c_index < wall[r_index].size(); ++c_index)
	sum[r_index][c_index] = sum[r_index][c_index - 1] + wall[r_index][c_index];
    
    
    size_t wall_width = *(sum.begin()->end() - 1);
    vector<vector<bool>> sum_pos(sum.size());
    for(r_index = 0; r_index < sum_pos.size(); ++r_index)
      {
	sum_pos[r_index].resize(wall_width + 1);
	for(c_index = 0; c_index < sum[r_index].size(); ++c_index)
	  sum_pos[r_index][sum[r_index][c_index]] = true;
      }

    cout << "sum_pos" << endl;
    show2D(sum_pos);
    
    int max_edge_count = 0;
    int edge_count = 0;
    for(c_index = 1; c_index < wall_width; ++c_index)
      {
	edge_count = 0;
	for(r_index = 0; r_index < sum_pos.size(); ++r_index)
	  if(sum_pos[r_index][c_index])
	    ++edge_count;

	max_edge_count = edge_count > max_edge_count ? edge_count : max_edge_count;
      }

    return wall.size() - max_edge_count;
  }
};
