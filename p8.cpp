#include <iostream>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
  int randNum = rand() % (To - From + 1) + From;
  return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
  for (short i = 0; i < Rows; i++)
  {
    for (short j = 0; j < Cols; j++)
    {
      arr[i][j] = RandomNumber(1, 10);
    }
  }
}

void multiplyMatrices(int arr1[3][3], int arr2[3][3], int result[3][3], short rows, short cols)
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      result[i][j] = arr1[i][j] * arr2[i][j];
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

int main()
{
  srand((unsigned)time(NULL));

  int matrix1[3][3], matrix2[3][3], resultMatrix[3][3];

  FillMatrixWithRandomNumbers(matrix1, 3, 3);
  FillMatrixWithRandomNumbers(matrix2, 3, 3);

  multiplyMatrices(matrix1, matrix2, resultMatrix, 3, 3);

  printMatrix(matrix1, 3, 3);
  cout << endl;
  printMatrix(matrix2, 3, 3);
  cout << endl;
  printMatrix(resultMatrix, 3, 3);
  cout << endl;
  return 0;
}