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

string reverseVectorToString(string str)
{
  vector<string> vString = splitString(str, " ");
  string s;
  for (int i = vString.size() - 1; i >= 0; --i)
  {
    s += vString[i] + " ";
  }
  return s;
}

int main()
{

  cout << "= = = = = = = = = = = = = = = = = \n";

  cout << reverseVectorToString(readString());
  return 0;
}