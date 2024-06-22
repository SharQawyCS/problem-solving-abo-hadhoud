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

int countWordsInString(string s)
{
  string space = " ";
  short pos = 0; // Position
  string word;

  int counter = 0;
  while ((pos = s.find(space)) != std::string::npos)
  {
    word = s.substr(0, pos);
    if (word != "")
    {
      counter++;
    }
    s.erase(0, pos + space.length());
  }

  if (s != "")
  {
    counter++;
  }
  return counter;
}

int main()
{
  cout << countWordsInString(readString());
  return 0;
}