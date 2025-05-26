#include <iostream>
#include <string>
#include <random>
#include <sstream>
#include <iomanip>
#include <functional> // for std::hash

using namespace std;

// Generate random salt as hex string (16 bytes)
string generateSalt()
{
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(0, 255);
  stringstream saltStream;
  for (int i = 0; i < 16; ++i)
  {
    saltStream << hex << setw(2) << setfill('0') << dis(gen);
  }
  return saltStream.str();
}
// Convert size_t hash to hex string
string toHexString(size_t hashVal)
{
  stringstream ss;
  ss << hex << setw(sizeof(size_t) * 2) << setfill('0') << hashVal;
  return ss.str();
}

// Hash password + salt multiple rounds using std::hash
string hashPassword(const string &password, const string &salt, int rounds)
{
  string combined = password + salt;
  hash<string> hasher;
  size_t hashedValue = hasher(combined);

  // Multiple rounds of hashing
  for (int i = 1; i < rounds; ++i)
  {
    // Convert previous hash to string and hash again
    string prevHashStr = toHexString(hashedValue);
    hashedValue = hasher(prevHashStr);
  }

  return toHexString(hashedValue);
}

int main()
{
  string password;
  int saltRounds;

  cout << "Enter password : ";
  cin >> password;
  cout << "Enter salt rounds : ";
  cin >> saltRounds;

  string salt = generateSalt();
  string hashed = hashPassword(password, salt, saltRounds);

  cout << "Salt (hex): " << salt << endl;
  cout << "Hashed password: " << hashed << endl;

  return 0;
}
