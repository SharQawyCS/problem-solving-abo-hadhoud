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

bool findClientByAccNumAndRemove(vector<stClient> vClients, string accNum)
{
  bool erased = false;
  for (vector<stClient>::iterator it = vClients.begin(); it != vClients.end();)
  {
    if (it->accNum == accNum)
    {
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

int main()
{
  vector<stClient> Vclients = LoadCleintsDataFromFile("clients.txt");
  if (findClientByAccNumAndRemove(Vclients, "N606"))
  {
    cout << "deleted";
  }
  else
  {
    cout << "not";
  }
  return 0;
}