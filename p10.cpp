#include <iostream>
#include <iomanip>

using namespace std;

int randomNumber(int From, int To)
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
      arr[i][j] = randomNumber(1, 10);
    }
  }
}

short getSumMatrix(int matrix[3][3], short rows, short cols)
{
  short sum = 0;
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      sum += matrix[i][j];
    }
  }
  return sum;
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

  int matrix[3][3];

  FillMatrixWithRandomNumbers(matrix, 3, 3);
  printMatrix(matrix, 3, 3);

  cout << getSumMatrix(matrix, 3, 3);

  return 0;
}