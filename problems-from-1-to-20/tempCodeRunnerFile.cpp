#include <iostream>
#include <iomanip>
using namespace std;

int randomNumber(int From, int To)
{ // Function to generate a random number
  int randNum = rand() % (To - From + 1) + From;
  return randNum;
}

void fillMatrix(int arr[3][3])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      arr[i][j] = randomNumber(1, 100);
    }
  }
}

void printMatrix(int arr[3][3])
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << setw(3) << arr[i][j] << "  ";
    }
    cout << endl;
  }
}

int main()
{
  srand((unsigned)time(NULL));
  int matrix[3][3];

  fillMatrix(matrix);
  printMatrix(matrix);

  return 0;
}