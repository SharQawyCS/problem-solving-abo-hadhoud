#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stClient
{
  string accNum;
  string pinCode;
  string name;
  string phone;
  float accBalance;
};

vector<string> splitString(string S1, string Delim)
{
  vector<string> vString;
  short pos = 0;
  string sWord; // define a string variable
                // use find() function to get the position of the delimiters
  while ((pos = S1.find(Delim)) != std::string::npos)
  {
    sWord = S1.substr(0, pos);
    // store the word
    if (sWord != "")
    {
      vString.push_back(sWord);
    }
    S1.erase(0, pos + Delim.length());
    /* erase() until positon and move to next word. */
  }
  if (S1 != "")
  {
    vString.push_back(S1); // it adds last word of the string.
  }
  return vString;
}

stClient convertLineToRecored(string line, string sep)
{
  stClient client;
  vector<string> clientData = splitString(line, sep);

  client.accNum = clientData[0];
  client.pinCode = clientData[1];
  client.name = clientData[2];
  client.phone = clientData[3];
  client.accBalance = stof(clientData[4]);

  return client;
}

void printClientData(stClient client)
{
  cout << "Account Number   : " << client.accNum << "\n";
  cout << "Pin Code         : " << client.pinCode << "\n";
  cout << "Member Name      : " << client.name << "\n";
  cout << "Phone Number     : " << client.phone << "\n";
  cout << "Total Balance    : " << client.accBalance << "\n";
}

int main()
{
  stClient client_1 = convertLineToRecored("A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000", "#//#");
  printClientData(client_1);

  return 0;
}