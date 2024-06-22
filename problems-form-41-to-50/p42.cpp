#include <iostream>
#include <string>
#include <vector>
using namespace std;

string readString()
{
  string s1;
  cout << "Please Enter Your String:\n";
  getline(cin, s1);
  return s1;
}

vector<string> splitString(string S1, string Delim)
{
  vector<string> vString;
  short pos = 0;
  string sWord; // define a string variable
                // use find() function to get the position of the delimiters
  while ((pos = S1.find(Delim)) != std::string::npos)
  {
    sWord = S1.substr(0, pos);
    // store the word
    if (sWord != "")
    {
      vString.push_back(sWord);
    }
    S1.erase(0, pos + Delim.length());
    /* erase() until positon and move to next word. */
  }
  if (S1 != "")
  {
    vString.push_back(S1); // it adds last word of the string.
  }
  return vString;
}

string replaceWord(string s, string oldWord, string newWord)
{
  string s2 = "";
  vector<string> vString = splitString(s, " ");
  for (string &word : vString)
  {
    if (word == oldWord)
    {
      word = newWord;
    }
    s2 += word + " ";
  }
  return s2.substr(0, s2.size() - 1);
}

int main()
{
  cout << replaceWord(readString(), "pal", "hi");
  return 0;
}