#include "solution.h"

int main(int argc, char** argv)
{
  Solution s;
  vector<int> test{3, 2, 1, 5, 6, 4};
  cout << s.findKthLargest(test, 4) << endl;
}
