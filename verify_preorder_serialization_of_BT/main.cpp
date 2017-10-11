#include "solution.h"
#include <sstream>


int main(int argc, char** argv)
{
  Solution s;
  
  cout.setf(ios::boolalpha);
  cout << s.isValidSerialization("1,#,21,#,#") << endl;
}
