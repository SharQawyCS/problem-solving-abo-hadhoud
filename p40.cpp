#include <iostream>
#include <string>
#include <vector>
using namespace std;

string joinString(string arr[], int length, string delim)
{
  string sentence;
  for (int i = 0; i < length; ++i)
  {
    sentence += arr[i];
    if (i < (length - 1))
    {
      sentence += delim;
    }
  }

  return sentence;
}

int main()
{
  string arr[] = {"gfg", "gfg", "svrf"};
  cout << joinString(arr, 3, "   -   ");

  return 0;
}