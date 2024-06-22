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

int countLetterMatchCase(string s, char c, bool matchCase = true)
{
  int counter = 0;
  for (int i = 0; i < s.length(); ++i)
  {
    if (matchCase)
    {
      if (s[i] == c)
      {
        ++counter;
      }
    }
    else
    {
      if (toupper(s[i]) == toupper(c))
      {
        ++counter;
      }
    }
  }
  return counter;
}

int main()
{
  cout << countLetterMatchCase(readString(), 'h', 0);
  return 0;
}
