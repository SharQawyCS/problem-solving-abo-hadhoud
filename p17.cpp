#include <iostream>
#include <iomanip>
using namespace std;

bool isExistInMatrix(int matrix[3][3], short rows, short cols, int num)
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (matrix[i][j] == num)
      {
        return true;
      }
    }
  }
  return false;
}

int main()
{
  int mat[3][3] =
      {{0, 1, 80},
       {0, 80, 0},
       {0, 1, 0}};

  cout << isExistInMatrix(mat, 3, 3, 0);
  return 0;
}