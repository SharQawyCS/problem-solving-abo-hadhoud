#include <iostream>
#include <iomanip>

using namespace std;

void fillMatrixWithOrdered(int matrix[3][3], short rows, short cols)
{
  int val = 1;
  for (int i = 0; i < rows; ++i)
  {

    for (int j = 0; j < rows; ++j)
    {
      matrix[i][j] = val;
      ++val;
    }
  }
}

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

void transposeMatrix(int matrix[][3], int transposedMatrix[][3], const short rows, const short cols)
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      transposedMatrix[i][j] = matrix[j][i];
    }
  }
}

int main()
{
  int matrix[3][3], transposedMatrix[3][3];
  fillMatrixWithOrdered(matrix, 3, 3);
  transposeMatrix(matrix, transposedMatrix, 3, 3);
  printMatrix(transposedMatrix, 3, 3);
  return 0;
}