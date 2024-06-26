#include <iostream>
#include <string>
using namespace std;

string readString()
{
  string s1;
  cout << "Please Enter Your String:\n";
  getline(cin, s1);
  return s1;
}

void printEachWordOfString(string s)
{
  string space = " ";
  cout << "\n Your String Words Are: \n";
  short pos = 0; // Position
  string word;

  while ((pos = s.find(space)) != std::string::npos)
  {
    word = s.substr(0, pos);
    if (word != "")
    {
      cout << word << endl;
    }
    s.erase(0, pos + space.length());
  }

  if (s != "")
  {
    cout << s << endl;
  }
}

int main()
{
  printEachWordOfString(readString());
  return 0;
}