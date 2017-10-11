#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
 private:
  vector<string> content;
  istringstream iss;
  ostringstream oss;
 public:
  void reverseWords(string &s)
  {
    content.resize(1);
    iss.str(s);
    while(iss >> content.back())
      content.emplace_back();
    cout << "Here" << endl;
    if(content.size() == 1)
      {
	s = *content.begin();
	return;
      }
    content.pop_back();
    
    /*for(const auto & ele : content)
      cout << ele << "<>";
      cout << endl;*/


    vector<string>::iterator it;
    it = content.end();
    do
      {
	it--;
	oss << *it << " ";
      }while(it != content.begin());
    s = oss.str();
    s.pop_back();

    content.clear();
    iss.clear();
    oss.clear();
  }
};
