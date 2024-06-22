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

string readString(string message)
{
  string s1;
  cout << message;
  getline(cin, s1);
  return s1;
}

int readFloat(string message)
{
  int num;
  cout << message;
  cin >> num;
  return num;
}

string generateLineFromRecord(stClient client, string sep)
{
  string recored = client.accNum + sep;
  recored += client.pinCode + sep;
  recored += client.name + sep;
  recored += client.phone + sep;
  recored += to_string(client.accBalance);

  return recored;
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

int main()
{
  stClient client_1 = readNewClient();

  cout << "line recored is: \n"
       << generateLineFromRecord(client_1, "#//#") << endl;
  return 0;
}