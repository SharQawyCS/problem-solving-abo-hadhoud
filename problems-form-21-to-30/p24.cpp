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

string makeFirstLetterUppercase(string sentence)
{
  sentence[0] = uppercase(sentence[0]);
  for (int i = 0; i < sentence.length(); ++i)
  {
    if (sentence[i] == ' ')
    {
      sentence[i + 1] = uppercase(sentence[i + 1]);
    }
  }
  return sentence;
}

int main()
{
  cout << makeFirstLetterUppercase(readString());
  return 0;
}