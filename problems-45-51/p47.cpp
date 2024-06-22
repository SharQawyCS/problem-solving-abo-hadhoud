#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>

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

void addClientToFile(stClient client, string fileName)
{
  string dataLine = generateLineFromRecord(client);
  addDataLineToFile("clients.txt", dataLine);
}

stClient readNewClient()
{
  stClient client;
  client.accNum = readString("Plz enter account number: ");
  client.pinCode = readString("plz enter pin Code: ");
  client.name = readString("plz Enter ur name: ");
  client.phone = readString("plz enter ur phone num: ");
  client.accBalance = readFloat("plz enter Account balance($): ");

  return client;
}

void addNewClients(string fileName = "clients.txt")
{
  char addMore = 'Y';
  do
  {
    system("clear");
    cout << "Adding New Client... \n\n";
    addClientToFile(readNewClient(), fileName);
    cout << "Client Added Successefully, Do U wanna add more? (Y/n): ";
    cin >> addMore;
    cin.ignore();
  } while (addMore == 'Y' || addMore == 'y');
}

int main()
{
  system("clear");
  addNewClients();
  return 0;
}