#include <iostream>
#include <string>
#include <vector>
using namespace std;

string joinString(vector<string> vString, string delim)
{
  string sentence;
  for (string &s : vString)
  {
    sentence += s + delim;
  }
  return sentence.substr(0, sentence.length() - delim.length());
}

int main()
{
  vector<string> vString = {"Amed", "Sheko", "Hol", "MOM", "SEES"};

  cout << joinString(vString, "  -  ");

  return 0;
}