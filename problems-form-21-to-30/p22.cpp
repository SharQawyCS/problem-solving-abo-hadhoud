#include <iostream>
#include <iomanip>
using namespace std;

void PrintFebSer(short num, int prev1, int prev2)
{
  int febNum = 0;
  if (num > 0)
  {
    febNum = prev1 + prev2;
    prev2 = prev1;
    prev1 = febNum;
    cout << febNum << "    ";
    PrintFebSer(num - 1, prev1, prev2);
  }
}

int main()
{
  PrintFebSer(10, 0, 1);

  return 0;
}