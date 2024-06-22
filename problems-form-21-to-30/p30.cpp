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

int countLetter(string s, char c)
{
  int counter = 0;
  for (int i = 0; i < s.length(); ++i)
  {
    if (s[i] == c)
    {
      ++counter;
    }
  }
  return counter;
}

int main()
{
  cout << countLetter(readString(), 'h');
  return 0;
}
