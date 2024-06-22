#include <iostream>
#include <string>
#include <vector>
using namespace std;

string readString()
{
  string s1;
  cout << "Please Enter Your String:\n";
  getline(cin, s1);
  return s1;
}

vector<string> splitString(string s, string delim)
{
  vector<string> vString;
  short pos = 0; // Position
  string word;

  int counter = 0;
  while ((pos = s.find(delim)) != std::string::npos)
  {
    word = s.substr(0, pos);
    if (word != "")
    {
      vString.push_back(word);
    }
    s.erase(0, pos + delim.length());
  }

  if (s != "")
  {
    vString.push_back(word);
  }

  return vString;
}

int main()
{
  vector<string> vString = splitString(readString(), ",");
  for (string &word : vString)
  {
    cout << word << "\n";
  }
  return 0;
}