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

bool isMatricesEqual(int matrix1[3][3], int matrix2[3][3], short rows, short cols)
{
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      sum1 += matrix1[i][j];
      sum2 += matrix2[i][j];
    }
  }

  if (sum1 == sum2)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  int mat1[3][3] =
      {
          {0, 9, 3},
          {6, 7, 7},
          {7, 8, 8}},

      mat2[3][3] =
          {
              {1, 2, 9},
              {6, 7, 7},
              {7, 8, 8}};
  printMatrix(mat1, 3, 3);
  cout << "\n";
  printMatrix(mat2, 3, 3);
  cout << "\n";

  cout << isMatricesEqual(mat1, mat2, 3, 3);
  return 0;
}