#include <iostream>
#include <string>
using namespace std;

char readChar()
{
  char c;
  cout << "Plz Enter Char: ";
  cin >> c;
  return c;
}

char toggleCharCase(char c)
{
  return islower(c) ? toupper(c) : tolower(c);
}

int main()
{
  cout << toggleCharCase(readChar());
  return 0;
}