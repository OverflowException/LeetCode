#include <vector>
#include <algorithm>
#include <iostream>
#include <array>

#define NULL_ELE 

using namespace std;

class Element
{
 public:
  Element(){_number = 0; _copied = false;};
  Element(int n){_number = n; _copied = false;};
  ~Element(){};
  int GetNumber(){ _copied = true; return _number;};
  bool IsCopied()const{return _copied;};
  const Element& operator=(int n)
    {
      _number = n;
      return *this;
    };
  friend ostream& operator<<(ostream &os, const Element& e)
  {os << e._number << " " << (e._copied ? "true" : "false"); return os;};

 private:
  int _number;
  bool _copied;
};


class Solution
{
 public:
  void Display(auto container)
  {
    for(const auto& ele : container)
      {
	for(const auto& ele_ele : ele)
	  cout << ele_ele << " ";
	cout << endl;
      }
  };

#define _COPY  *it = m[_r][_c].GetNumber()

  void LCopy(vector<vector<Element>>& m, size_t& _r, size_t& _c,
vector<int>::iterator& it)
  {_c--; _COPY;};

  void RCopy(vector<vector<Element>>& m, size_t& _r, size_t& _c,
vector<int>::iterator& it)
  {_c++; _COPY;};

  void UCopy(vector<vector<Element>>& m, size_t& _r, size_t& _c,
vector<int>::iterator& it)
  {_r--; _COPY;};

  void DCopy(vector<vector<Element>>& m, size_t& _r, size_t& _c,
vector<int>::iterator& it)
  {_r++; _COPY;};

  typedef void (Solution::*move_ptr)(vector<vector<Element>>& m, size_t& _r, size_t& _c, vector<int>::iterator& it);

  vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
      if(matrix.empty())
	{
	  vector<int> e;
	  return e;
	}

      //Wrapped matrix
      vector<vector<Element>> w_matrix(matrix.size());
      vector<vector<Element>>::iterator w_row_it;
      auto in_it = back_inserter(*(w_matrix.begin()));
      vector<vector<int>>::const_iterator row_it;
    
      for(row_it = matrix.cbegin(), w_row_it = w_matrix.begin();
	  row_it != matrix.cend();
	  row_it++, w_row_it++)
	{
	  in_it = back_inserter(*w_row_it);
	  copy(row_it->begin(), row_it->end(), in_it);
	}

      size_t _row = 0;
      size_t _column = 0;
      size_t _width = w_matrix.begin()->size();
      size_t _height = w_matrix.size();
      size_t _width_end = _width - 1;
      size_t _height_end = _height - 1;
      vector<int> result(w_matrix.size() * w_matrix.begin()->size());
      vector<int>::iterator r_it = result.begin();;
      *r_it = w_matrix[_row][_column].GetNumber();
      unsigned position_marker = 0;
      array<move_ptr, 16> arr_move_ptr =
	{
	  NULL, NULL, NULL, &Solution::LCopy,//0 -- 3
	  NULL, NULL, &Solution::UCopy, &Solution::UCopy,//4 -- 7
	  NULL, &Solution::DCopy, NULL, &Solution::LCopy,//8 -- 11
	  &Solution::RCopy, &Solution::DCopy, &Solution::RCopy, NULL//12 -- 15
	};

      while(++r_it != result.end())
	{
	  position_marker &= 0;
	  //Right boundary, 0x01
	  if(_column == _width_end)
	    position_marker |= 0x01;
	  else if(w_matrix[_row][_column + 1].IsCopied())
	    position_marker |= 0x01;
	  //Bottom boundary, 0x02
	  if(_row == _height_end)
	    position_marker |= 0x02;
	  else if(w_matrix[_row + 1][_column].IsCopied())
	    position_marker |= 0x02;
	  //Left boundary, 0x04
	  if(_column == 0)
	    position_marker |= 0x04;
	  else if(w_matrix[_row][_column - 1].IsCopied())
	    position_marker |= 0x04;
	  //Top boundary, 0x08
	  if(_row == 0)
	    position_marker |= 0x08;
	  else if(w_matrix[_row - 1][_column].IsCopied())
	    position_marker |= 0x08;

	  //*arr_move_ptr[position_marker](w_matrix, _row, _column, r_it);
	  move_ptr p = arr_move_ptr[position_marker];
	  (this->*p)(w_matrix, _row, _column, r_it);

	}
      return result;
    }
};
