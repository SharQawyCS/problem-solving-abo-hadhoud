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
  for (int i = 0; i < s.length(); ++i)
  {
    if (s[i] == ' ')
    {
      cout << "\n";
    }
    else
    {
      cout << s[i];
    }
  }
}

int main()
{
  printEachWordOfString(readString());
  return 0;
}