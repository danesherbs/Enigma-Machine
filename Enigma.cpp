#include "Enigma.h"

using namespace std;

EnigmaMachine::EnigmaMachine(char** configFile)
{
  initialiseIntCharMap();
  Plugboard plugboard (EnigmaMachine::read_file(configFile[1]));
}

vector<int> EnigmaMachine::read_file(char *filename)
{
  vector<int> input; int next;
  ifstream file (filename);

  while(!file.eof())
  {
  	file >> ws; // ignore whitespace
    file >> next; // store next int
    input.push_back(next); // append to vector
  }

  file.close();
  
  return input;
}

void EnigmaMachine::initialiseIntCharMap()
{
 for (int idx = 0; idx < 26; idx++)
 {
   intCharMap[idx] = (char) ASCII_A + idx;
 }
}