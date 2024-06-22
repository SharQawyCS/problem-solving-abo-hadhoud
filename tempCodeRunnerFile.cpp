hort countNumInMatrix(int matrix[3][3], short rows, short cols, int num)
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