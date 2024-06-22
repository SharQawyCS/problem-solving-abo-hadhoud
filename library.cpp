#include <iostream>
#include <iomanip>

using namespace std;

int readInput(string message)
{
  int inputNum;
  cout << message + "\n";
  cin >> inputNum;
  return inputNum;
}

void ReadArray(int arr[100], int &arrLength)
{
  cout << "\nEnter number of elements:\n";
  cin >> arrLength;
  cout << "\nEnter array elements: \n";
  for (int i = 0; i < arrLength; i++)
  {
    cout << "Element [" << i + 1 << "] : ";
    cin >> arr[i];
  }
  cout << endl;
}

void PrintArray(int arr[100], int arrLength)
{
  for (int i = 0; i < arrLength; i++)
    cout << arr[i] << " ";
  cout << "\n";
}

int randomNumber(int From, int To)
{ // Function to generate a random number
  int randNum = rand() % (To - From + 1) + From;
  return randNum;

  // Put the next line in main
  //  srand((unsigned)time(NULL));
}

int findMax(int arr[], int size)
{
  int max = arr[0];
  for (int i = 0; i < size; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  return max;
}

int findMin(int arr[], int size)
{
  int min = arr[0];
  for (int i = 0; i < size; i++)
  {
    if (arr[i] < min)
    {
      min = arr[i];
    }
  }
  return min;
}

int arrSum(int arr[], int size)
{
  int sum = 0;
  for (int i = 0; i < size; i++)
  {
    sum += arr[i];
  }
  return sum;
}

bool isPrime(int num)
{
  if (num == 1)
  {
    return false;
  }
  for (int i = 2; i <= num / 2; ++i)
  {
    if (num % i == 0)
    {
      return false;
    }
  }

  return true;
}
void shuffleArr(int arr[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    int x = randomNumber(0, size - 1),
        y = randomNumber(0, size - 1);
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
  }
}

void fillArrWithRandom(int arr[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    arr[i] = randomNumber(1, 100);
  }
}

void arrReverseCopy(int originArr[], int reverseArr[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    reverseArr[size - 1 - i] = originArr[i];
  }
}

string generateWord(int length)
{
  string word = "";
  for (int i = 0; i < length; i++)
  {
    word += char(randomNumber(65, 90));
  }
  return word;
}

string generateKey(int length)
{
  string key = "";
  for (int i = 0; i < length; ++i)
  {
    key += generateWord(4);
    if (i != length - 1)
    {
      key += "-";
    }
  }
  return key;
}

void fillArrWithKeys(string arr[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    arr[i] = generateKey(4);
  }
}

int indexOf(int arr[], int size, int value)
{
  for (int i = 0; i < size; ++i)
  {
    if (arr[i] == value)
    {
      return i;
    }
  }

  return -1;
}

void addElementToArr(int arr[], int &size, int element)
{
  arr[size] = element;
  size++;
}

void DynamicRead(int arr[], int &size)
{
  int choice;
  int num;
  cout << "Please Enter a number: ";
  cin >> num;
  addElementToArr(arr, size, num);

  cout << "Do You Want More? [0], [1]: ";
  cin >> choice;
  switch (choice)
  {
  case 0:
  {
    cout << "Array elements is: ";
    for (int i = 0; i < size; ++i)
    {
      cout << arr[i];
    }
    cout << "\n";
    cout << size << "\n";
    break;
  }
  case 1:
  {
    DynamicRead(arr, size);
    break;
  }
  }
}

bool isPalindrome(int arr[], int size)
{
  for (int i = 0; i <= size / 2; ++i)
  {
    if (arr[i] != arr[size - 1 - i])
    {
      return false;
    }
  }
  return true;
}

int countPostive(int arr[], int size)
{
  int count = 0;
  for (int i = 0; i < size; ++i)
  {
    if (arr[i] > 0)
    {
      count++;
    }
  }
  return count;
}

int abs(int num)
{
  if (num < 0)
  {
    return (num * -1);
  }
  return num;
}

int countNegative(int arr[], int size)
{
  int count = 0;
  for (int i = 0; i < size; ++i)
  {
    if (arr[i] < 0)
    {
      count++;
    }
  }
  return count;
}

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

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
  for (short i = 0; i < Rows; i++)
  {
    for (short j = 0; j < Cols; j++)
    {
      arr[i][j] = randomNumber(1, 100);
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

bool isMatricesTypical(int matrix1[3][3], int matrix2[3][3], short rows, short cols)
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (matrix1[i][j] != matrix2[i][j])
      {
        return false;
      }
    }
  }
  return true;
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

bool isIdentityMatrix(int matrix[3][3], int rows, int cols)
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
bool isScalarMatriox(int matrix[3][3], int rows, int cols)
{
  int scVal = matrix[0][0];
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (j == i)
      {
        if (matrix[i][j] != scVal)
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

bool isSpareMatrix(int matrix[3][3], short rows, short cols)
{
  return (countNumInMatrix(matrix, rows, cols, 0) >= 0.5 * rows * cols);
}

bool isExistInMatrix(int matrix[3][3], short rows, short cols, int num)
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (matrix[i][j] == num)
      {
        return true;
      }
    }
  }
  return false;
}

int getMaxInMatrix(int matrix[3][3], int rows, int cols)
{
  int max = matrix[0][0];
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (matrix[i][j] > max)
      {
        max = matrix[i][j];
      }
    }
  }
  return max;
}

int getMinInMatrix(int matrix[3][3], int rows, int cols)
{
  int min = matrix[0][0];
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (matrix[i][j] < min)
      {
        min = matrix[i][j];
      }
    }
  }
  return min;
}

void printMaxAndMinInMatrix(int matrix[3][3], int rows, int cols)
{
  cout << "Min is: " << getMinInMatrix(matrix, rows, cols) << endl;
  cout << "Max is: " << getMaxInMatrix(matrix, rows, cols) << endl;
}

bool isArrPalindrome(int arr[], int size)
{
  for (int i = 0; i <= size / 2; ++i)
  {
    if (arr[i] != arr[size - 1 - i])
    {
      return false;
    }
  }
  return true;
}

bool isMatrixPalindrome(int matrix[3][3], short rows, short cols)
{
  for (int i = 0; i < rows; ++i)
  {
    // for (int j = 0; j < cols; ++j)
    // {
    if (!isArrPalindrome(matrix[i], cols))
    {
      return false;
    }
    // }
  }
  return true;
}

void PrintFebSer(short num, int prev1, int prev2)
{
  int febNum = 0;
  if (num > 0)
  {
    febNum = prev1 + prev2;
    prev2 = prev1;
    prev1 = febNum;
    cout << febNum << "    ";
    PrintFebSer(num - 1, prev1, prev2);
  }
}

void printFebonacciUsingLoop(int num)
{
  int prev1 = 1, prev2 = 0;
  for (int i = 2; i <= num; ++i)
  {
    int febNum = prev1 + prev2;
    cout << febNum << "  ";
    prev2 = prev1;
    prev1 = febNum;
  }
}

string readString()
{
  string s1;
  cout << "Please Enter Your String:\n";
  getline(cin, s1);
  return s1;
}

void printFirstOfEachWord(string sentence)
{
  cout << sentence[0] << "\n";
  for (int i = 0; i < sentence.length(); ++i)
  {
    if (sentence[i] == ' ')
    {
      cout << sentence[i + 1] << "\n";
    }
  }
}

char uppercase(char c)
{
  if (c > 96 && c < 123)
  {
    return (c - 32);
  }
  else
  {
    return c;
  }
}

string makeFirstLetterUppercase(string sentence)
{
  sentence[0] = uppercase(sentence[0]);
  for (int i = 0; i < sentence.length(); ++i)
  {
    if (sentence[i] == ' ')
    {
      sentence[i + 1] = uppercase(sentence[i + 1]);
    }
  }
  return sentence;
}

char lowercase(char c)
{
  if (c > 64 && c < 91)
  {
    return (c + 32);
  }
  else
  {
    return c;
  }
}

string makeFirstLetterLowercase(string sentence)
{
  sentence[0] = lowercase(sentence[0]);
  for (int i = 0; i < sentence.length(); ++i)
  {
    if (sentence[i] == ' ')
    {
      sentence[i + 1] = lowercase(sentence[i + 1]);
    }
  }
  return sentence;
}

string lowercaseEntireString(string sentence)
{
  for (int i = 0; i < sentence.length(); ++i)
  {
    sentence[i] = lowercase(sentence[i]);
  }
  return sentence;
}

string uppercaseEntireString(string sentence)
{
  for (int i = 0; i < sentence.length(); ++i)
  {
    sentence[i] = uppercase(sentence[i]);
  }
  return sentence;
}

char readChar()
{
  char c;
  cout << "Plz Enter Char: ";
  cin >> c;
  return c;
}

char toggleCharCase(char c)
{
  return islower(c) ? toupper(c) : tolower(c);
}

int smallCount(string sentence)
{
  int smallCounter = 0;
  for (int i = 0; i < sentence.length(); ++i)
  {
    if (islower(sentence[i]))
    {
      smallCounter++;
    }
  }
  return smallCounter;
}

int capitalCount(string sentence)
{
  int capitalCounter = 0;
  for (int i = 0; i < sentence.length(); ++i)
  {
    if (isupper(sentence[i]))
    {
      capitalCounter++;
    }
  }
  return capitalCounter;
}

void countThenPrint(string s)
{
  cout << "String Length = " << s.length() << "\n";
  cout << "Capital Letters Count = " << capitalCount(s) << "\n";
  cout << "Small Letters Count = " << smallCount(s) << "\n";
}

int countLetter(string s, char c)
{
  int counter = 0;
  for (int i = 0; i < s.length(); ++i)
  {
    if (s[i] == c)
    {
      ++counter;
    }
  }
  return counter;
}

int main()
{

  return 0;
}