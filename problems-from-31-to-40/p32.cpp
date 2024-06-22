#include <iostream>
using namespace std;

bool isVowel(char c)
{
  c = tolower(c);
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  cout << isVowel('I');
  return 0;
}
