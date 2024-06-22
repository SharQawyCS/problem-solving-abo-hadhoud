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

void printIntersectedNumbersInMatrices(int matrix1[3][3], int matrix2[3][3], int rows, int cols)
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (isExistInMatrix(matrix2, rows, cols, matrix1[i][j]))
      {
        cout << matrix1[i][j] << "  ";
      }
    }
  }
}
int main()
{
  int mat1[3][3] =
      {{0, 0, 0},
       {0, 0, 0},
       {0, 1, 0}};
  int mat2[3][3] =
      {{0, 1, 0},
       {0, 0, 0},
       {0, 0, 0}};

  printIntersectedNumbersInMatrices(mat1, mat2, 3, 3);

  return 0;
}