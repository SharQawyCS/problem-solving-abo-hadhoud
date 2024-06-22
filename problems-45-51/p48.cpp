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

void printHeader(int clientsNO)
{
  cout << "\n\t\t\tClient List (" << clientsNO << ") Client(s).";
  cout << "\n______________________________________________";
  cout << "________________________________\n"
       << endl;
  cout << "| " << left << setw(15) << "Accout Number";
  cout << "| " << left << setw(10) << "Pin Code";
  cout << "| " << left << setw(20) << "Client Name";
  cout << "| " << left << setw(12) << "Phone";
  cout << "| " << left << setw(12) << "Balance";
  cout << "\n______________________________________________";
  cout << "________________________________\n"
       << endl;
}

void printOneRow(stClient client)
{
  cout << "| " << setw(15) << left << client.accNum;
  cout << "| " << setw(10) << left << client.pinCode;
  cout << "| " << setw(20) << left << client.name;
  cout << "| " << setw(12) << left << client.phone;
  cout << "| " << setw(12) << left << client.accBalance;
}

void printTable()
{
  vector<stClient> vClients = LoadCleintsDataFromFile("clients.txt");
  printHeader(vClients.size());

  for (stClient &singleClient : vClients)
  {
    printOneRow(singleClient);
    cout << "\n";
  }
  cout << "______________________________________________";
  cout << "________________________________\n"
       << endl;
}

int main()
{
  printTable();
  return 0;
}