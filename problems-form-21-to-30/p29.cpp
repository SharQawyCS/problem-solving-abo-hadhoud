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

int smallCount(string sentence)
{
  int smallCounter = 0;
  for (int i = 0; i < sentence.length(); ++i)
  {
    if (islower(sentence[i]))
    {
      smallCounter++;
    }
  }
  return smallCounter;
}

int capitalCount(string sentence)
{
  int capitalCounter = 0;
  for (int i = 0; i < sentence.length(); ++i)
  {
    if (isupper(sentence[i]))
    {
      capitalCounter++;
    }
  }
  return capitalCounter;
}

void countThenPrint(string s)
{
  cout << "String Length = " << s.length() << "\n";
  cout << "Capital Letters Count = " << capitalCount(s) << "\n";
  cout << "Small Letters Count = " << smallCount(s) << "\n";
}

int main()
{
  countThenPrint(readString());
  return 0;
}