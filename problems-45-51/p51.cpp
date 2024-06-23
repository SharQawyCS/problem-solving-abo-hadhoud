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

// Functions
string readString(string message)
{
  string s1;
  cout << message;
  getline(cin, s1);
  return s1;
}

float readFloat(string message)
{
  float num;
  cout << message;
  cin >> num;
  return num;
}

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

string generateLineFromRecord(stClient client, string sep = "#//#")
{
  string line = client.accNum + sep;
  line += client.pinCode + sep;
  line += client.name + sep;
  line += client.phone + sep;
  line += to_string(client.accBalance);

  return line;
}

void addDataLineToFile(string fileName, string line)
{
  fstream myFile;
  myFile.open(fileName, ios::out | ios::app);
  if (myFile.is_open())
  {
    myFile << line << endl;
    myFile.close();
  }
}

void addClientToFile(stClient client, string fileName = "clients.txt")
{
  string dataLine = generateLineFromRecord(client);
  addDataLineToFile(fileName, dataLine);
}

void addNewClientsVectorToFile(vector<stClient> vClients)
{
  remove("clients.txt");
  for (stClient &client : vClients)
  {
    addClientToFile(client);
  }
}

void printClientData(stClient client)
{
  cout << "Account Number   : " << client.accNum << "\n";
  cout << "Pin Code         : " << client.pinCode << "\n";
  cout << "Member Name      : " << client.name << "\n";
  cout << "Phone Number     : " << client.phone << "\n";
  cout << "Total Balance    : " << client.accBalance << "\n";
}

bool findClientByAccNumAndRemove(vector<stClient> vClients, string accNum)
{
  bool erased = false;
  for (vector<stClient>::iterator it = vClients.begin(); it != vClients.end();)
  {
    if (it->accNum == accNum)
    {
      cout << "This IS the client: \n";
      printClientData(*it);
      it = vClients.erase(it);
      erased = true;
    }
    else
    {
      ++it;
    }
  }
  if (erased)
  {
    addNewClientsVectorToFile(vClients);
  }
  return erased;
}

void updateClientData(vector<stClient> vClients, string accNum)
{
  if (findClientByAccNumAndRemove(vClients, accNum))
  {
    stClient client;
    client.accNum = accNum;
    client.pinCode = readString("plz enter pin Code: ");
    client.name = readString("plz Enter ur name: ");
    client.phone = readString("plz enter ur phone num: ");
    client.accBalance = readFloat("plz enter Account balance($): ");
    addClientToFile(client, "clients.txt");
    cout << "Data Updated!\n";
  }
  else
  {
    cout << "Client Not found with: " << accNum;
  }
}

int main()
{
  vector<stClient> Vclients = LoadCleintsDataFromFile("clients.txt");
  updateClientData(Vclients, readString("Enter The fuck acc num to update: "));
  return 0;
}