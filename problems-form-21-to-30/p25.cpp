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

string makeFirstLetterLowercase(string sentence)
{
  sentence[0] = lowercase(sentence[0]);
  for (int i = 0; i < sentence.length(); ++i)
  {
    if (sentence[i] == ' ')
    {
      sentence[i + 1] = lowercase(sentence[i + 1]);
    }
  }
  return sentence;
}

int main()
{
  cout << makeFirstLetterLowercase(readString());
  return 0;
}