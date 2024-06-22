#include <iostream>
#include <iomanip>
using namespace std;

void printFebonacciUsingLoop(int num)
{
  int prev1 = 1, prev2 = 0;
  for (int i = 2; i <= num; ++i)
  {
    int febNum = prev1 + prev2;
    cout << febNum << "  ";
    prev2 = prev1;
    prev1 = febNum;
  }
}

int main()
{
  printFebonacciUsingLoop(10);
  return 0;
}