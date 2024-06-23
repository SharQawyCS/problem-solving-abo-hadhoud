#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <iomanip>

using namespace std;

// Data
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

stClient convertLineToRecored(string line, string sep = "#//#")
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

vector<stClient> LoadCleintsDataFromFile(string fileName)
{
  vector<stClient> vClients;
  fstream myFile;
  myFile.open(fileName, ios::in); // read Mode
  if (myFile.is_open())
  {
    string line;
    stClient client;
    while (getline(myFile, line))
    {
      client = convertLineToRecored(line);
      vClients.push_back(client);
    }
    myFile.close();
  }
  return vClients;
}

void printClientDetailsByIndex(vector<stClient> Vclients, int index, string accNum)
{
  if (index == -1)
  {
    cout << "Cannot Found with account number " << accNum << " \n";
  }
  else
  {
    stClient client = Vclients[index];
    cout << "Account Number   : " << client.accNum << "\n";
    cout << "Pin Code         : " << client.pinCode << "\n";
    cout << "Member Name      : " << client.name << "\n";
    cout << "Phone Number     : " << client.phone << "\n";
    cout << "Total Balance    : " << client.accBalance << "\n";
  }
}

void findClientByAccNumAndPrint(vector<stClient> vClients)
{
  string accNum;
  cout << "PLZ enter Acc num:";
  getline(cin, accNum);

  int index = -1;
  for (int i = 0; i < vClients.size(); ++i)
  {
    if (vClients[i].accNum == accNum)
    {
      index = i;
    }
  }
  printClientDetailsByIndex(vClients, index, accNum);
}

int main()
{
  vector<stClient> Vclients = LoadCleintsDataFromFile("clients.txt");
  findClientByAccNumAndPrint(Vclients);
  return 0;
}