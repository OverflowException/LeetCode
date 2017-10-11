#include <map>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
  map<string, size_t> test_map;
  test_map.insert({"a", 67});
  test_map.insert({"c", 55});
  test_map.insert({"b", 56});

  ostream_iterator<string> out_it(cout, "\n");
  for_each(test_map.begin(), test_map.end(),
	   [&](decltype(test_map)::value_type ele)
	   {
	     *out_it = ele.first;
	   });  
  
  return 0;
}
