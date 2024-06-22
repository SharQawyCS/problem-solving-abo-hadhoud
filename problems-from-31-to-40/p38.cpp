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

string trimLeft(string s)
{
  for (int i = 0; i < s.length(); ++i)
  {
    if (s[i] != ' ')
    {
      return s.substr(i, s.length() - 1);
    }
  }
  return s;
}

string trimRight(string s)
{

  for (int i = s.length() - 1; i >= 0; --i)
  {
    if (s[i] != ' ')
    {
      return s.substr(0, i + 1);
    }
  }
  return s;
}

string trim(string s)
{
  return trimRight(trimLeft(s));
}

int main()
{
  cout << trim("   hgjdfhg dfghjdf dfghjo dfgi hdfoigh   ");
  return 0;
}