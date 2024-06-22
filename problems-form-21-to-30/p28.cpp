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

char toggleCharCase(char c)
{
  return islower(c) ? toupper(c) : tolower(c);
}

string toggleEntireStringCase(string sentence)
{
  for (int i = 0; i < sentence.length(); ++i)
  {
    sentence[i] = toggleCharCase(sentence[i]);
  }
  return sentence;
}

int main()
{
  cout << toggleEntireStringCase(readString());
  return 0;
}
