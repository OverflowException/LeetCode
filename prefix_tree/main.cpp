#include "solution.h"

int main()
{
  Trie test;
  test.insert("banana");
  cout.setf(ios::boolalpha);
  cout << test.search("banana") << endl;
  cout << test.startsWith("bama") << endl;
}
