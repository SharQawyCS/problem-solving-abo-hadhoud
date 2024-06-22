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

char lowercase(char c)
{
  if (c > 64 && c < 91)
  {
    return (c + 32);
  }
  else
  {
    return c;
  }
}

char uppercase(char c)
{
  if (c > 96 && c < 123)
  {
    return (c - 32);
  }
  else
  {
    return c;
  }
}

string lowercaseEntireString(string sentence)
{
  for (int i = 0; i < sentence.length(); ++i)
  {
    sentence[i] = lowercase(sentence[i]);
  }
  return sentence;
}

string uppercaseEntireString(string sentence)
{
  for (int i = 0; i < sentence.length(); ++i)
  {
    sentence[i] = uppercase(sentence[i]);
  }
  return sentence;
}

int main()
{
  string sent = readString();
  cout << lowercaseEntireString(sent) << "\n";
  cout << uppercaseEntireString(sent) << "\n";

  return 0;
}