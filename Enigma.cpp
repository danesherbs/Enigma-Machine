#include "Enigma.h"

using namespace std;

EnigmaMachine::EnigmaMachine(char** configFile) 
{
  EnigmaMachine::initialiseMapping();
}

void EnigmaMachine::initialiseMapping()
{
  for (int idx = 0; idx < LETTERS_IN_ALPHABET; idx++)
  {
    mapIntToChar[idx] = (char) ASCII_A + idx;
  }
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