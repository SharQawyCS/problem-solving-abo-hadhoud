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

int main()
{
  int mat[3][3] =
      {{0, 0, 80},
       {0, 80, 0},
       {0, 0, 0}};

  cout << countNumInMatrix(mat, 3, 3, 80);

  return 0;
}