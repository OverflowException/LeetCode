#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cstdio>
#include <sstream>
#include <algorithm>

using namespace std;

class Node;
class File;
class Dir;

class Node
{
 public:
  Node(const string& name) : _name(name){};
  string name();
 protected:
  string _name;
};

class Dir : public Node
{
 private:
  vector<Node*> _subs;
 public:
  Dir(const string& name = "") : Node(name){};
  void addSub(const string& name, bool isDir);
  const vector<Node*> subs();
};

class File : public Node
{
 private:
  list<string> _content;

 public:
  File(const string& name) : Node(name){};
  void appendContent(const string& content);
};


class FileSystem
{
 private:
  Dir root;
  istringstream path_parser;
 public:
  FileSystem(){};
  
  vector<string> ls(string path);
  void mkdir(string path);
  Dir* cd(string& path);
  void addContentToFile(string filePath, string content);
  string readContentFromFile(string filePath);
};
