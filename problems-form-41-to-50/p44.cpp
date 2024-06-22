#include <iostream>
#include <string>
#include <vector>
using namespace std;

string removePuncFromString(string s)
{
  string s2 = "";
  for (int i = 0; i < s.length(); ++i)
  {
    if (!ispunct(s[i]))
    {
      s2 += s[i];
    }
  }
  return s2;
}

int main()
{
  cout << removePuncFromString("Welcome to Jordan, Jordan is a nice country; it's amazing.") << "\n";
  return 0;
}
