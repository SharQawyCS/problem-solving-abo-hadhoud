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

bool isVowel(char c)
{
  c = tolower(c);
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
  {
    return true;
  }
  else
  {
    return false;
  }
}

void printVowel(string s)
{
  for (int i = 0; i < s.length(); ++i)
  {
    if (isVowel(s[i]))
    {
      cout << s[i] << "   ";
    }
  }
}

int main()
{
  printVowel(readString());
  return 0;
}