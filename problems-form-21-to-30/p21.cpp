#include <iostream>
#include <iomanip>
using namespace std;

// int febSer(int num)
// {
//   if (num == 1 || num == 0)
//   {
//     return 1;
//   }
//   return (febSer(num - 1) + febSer(num - 2));
// }

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
  // cout << febSer(4);

  printFebonacciUsingLoop(10);
  return 0;
}