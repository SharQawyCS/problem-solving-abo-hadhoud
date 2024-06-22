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
