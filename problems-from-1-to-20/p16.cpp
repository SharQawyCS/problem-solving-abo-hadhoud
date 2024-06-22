#include <iostream>
#include <iomanip>
using namespace std;

short countNumInMatrix(int matrix[3][3], short rows, short cols, int num)
{
  short counter = 0;
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (matrix[i][j] == num)
      {
        counter++;
      }
    }
  }
  return counter;
}

bool isSpareMatrix(int matrix[3][3], short rows, short cols)
{
  return (countNumInMatrix(matrix, rows, cols, 0) >= 0.5 * rows * cols);
}

int main()
{
  int mat[3][3] =
      {{0, 1, 80},
       {0, 80, 0},
       {0, 1, 0}};

  cout << isSpareMatrix(mat, 3, 3);

  return 0;
}