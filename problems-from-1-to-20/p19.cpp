#include <iostream>
#include <iomanip>
using namespace std;

int getMaxInMatrix(int matrix[3][3], int rows, int cols)
{
  int max = matrix[0][0];
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (matrix[i][j] > max)
      {
        max = matrix[i][j];
      }
    }
  }
  return max;
}

int getMinInMatrix(int matrix[3][3], int rows, int cols)
{
  int min = matrix[0][0];
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (matrix[i][j] < min)
      {
        min = matrix[i][j];
      }
    }
  }
  return min;
}

void printMaxAndMinInMatrix(int matrix[3][3], int rows, int cols)
{
  cout << "Min is: " << getMinInMatrix(matrix, rows, cols) << endl;
  cout << "Max is: " << getMaxInMatrix(matrix, rows, cols) << endl;
}

int main()
{
  int mat[3][3] =
      {{0, -65406840, 80},
       {-84903284, 765, 75670},
       {07567, 75676, 99999999}};

  printMaxAndMinInMatrix(mat, 3, 3);
  return 0;
}