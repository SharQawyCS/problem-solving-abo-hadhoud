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

void printFirstOfEachWord(string sentence)
{
  cout << sentence[0] << "\n";
  for (int i = 0; i < sentence.length(); ++i)
  {
    if (sentence[i] == ' ')
    {
      cout << sentence[i + 1] << "\n";
    }
  }
}

int main()
{
  printFirstOfEachWord(readString());
  return 0;
}