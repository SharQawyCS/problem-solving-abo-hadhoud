#include <iostream>
#include <iomanip>
using namespace std;

bool isArrPalindrome(int arr[], int size)
{
  for (int i = 0; i <= size / 2; ++i)
  {
    if (arr[i] != arr[size - 1 - i])
    {
      return false;
    }
  }
  return true;
}

bool isMatrixPalindrome(int matrix[3][3], short rows, short cols)
{
  for (int i = 0; i < rows; ++i)
  {
    // for (int j = 0; j < cols; ++j)
    // {
    if (!isArrPalindrome(matrix[i], cols))
    {
      return false;
    }
    // }
  }

  return true;
}

int main()
{
  int mat[3][3] =
      {{1, 0, 1},
       {3, 2, 3},
       {8, 4, 8}};

  cout << isMatrixPalindrome(mat, 3, 3);

  return 0;
}