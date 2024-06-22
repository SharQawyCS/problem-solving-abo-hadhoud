#include <iostream>
#include <iomanip>

using namespace std;

bool isScalarMatriox(int matrix[3][3], int rows, int cols)
{
  int scVal = matrix[0][0];
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (j == i)
      {
        if (matrix[i][j] != scVal)
        {
          return false;
        }
      }
      else
      {
        if (matrix[i][j] != 0)
        {
          return false;
        }
      }
    }
  }
  return true;
}

int main()
{
  int mat[3][3] =
      {{0, 0, 0},
       {0, 0, 0},
       {0, 0, 0}};

  cout << isScalarMatriox(mat, 3, 3);
  return 0;
}