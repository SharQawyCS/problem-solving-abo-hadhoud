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

void getMids(int matrix[3][3], int midRow[3], int midCol[3], short rows, short cols)
{
  const short midRowIndex = rows / 2;
  const short midColIndex = cols / 2;

  for (int i = 0; i < cols; ++i)
  {
    midRow[i] = matrix[midRowIndex][i];
  }

  for (int j = 0; j < cols; ++j)
  {
    midCol[j] = matrix[j][midColIndex];
  }
}

void PrintArray(int arr[3], int arrLength)
{
  for (int i = 0; i < arrLength; i++)
    cout << arr[i] << " ";
  cout << "\n";
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

  int matrix[3][3], midRow[3], midCol[3];

  FillMatrixWithRandomNumbers(matrix, 3, 3);
  printMatrix(matrix, 3, 3);

  getMids(matrix, midRow, midCol, 3, 3);

  PrintArray(midRow, 3);
  PrintArray(midCol, 3);

  return 0;
}