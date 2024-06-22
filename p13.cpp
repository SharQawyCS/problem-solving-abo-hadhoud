#include <iostream>
#include <iomanip>

using namespace std;

void printMatrix(int arr[3][3], short Rows, short Cols)
{
  for (short i = 0; i < Rows; i++)
  {
    for (short j = 0; j < Cols; j++)
    {
      cout << setw(3) << arr[i][j] << "     ";
    }
    cout << "\n";
  }
}

bool isIdentityMatriox(int matrix[3][3], int rows, int cols)
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (j == i)
      {
        if (matrix[i][j] != 1)
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
      {{2, 0, 0},
       {0, 2, 0},
       {0, 0, 2}};

  cout << isIdentityMatriox(mat, 3, 3);
  return 0;
}