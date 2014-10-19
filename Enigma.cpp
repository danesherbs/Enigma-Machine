#include "Enigma.h"
#include "Rotor.h"

#include <assert.h>

using namespace std;

EnigmaMachine::EnigmaMachine(int argc, char** configFiles) : plugboard(read_file(configFiles[argc-1]))
{
  initialiseIntCharMap();
  initialiseRotors(argc, configFiles);
  std::vector<int> rotationCount(rotors.size(), 0);
}

char EnigmaMachine::input_message(char chr)
{
  return encode(charToInt(chr)) + ASCII_A;
}

int EnigmaMachine::charToInt(char chr)
{
  return chr - ASCII_A;
}

int EnigmaMachine::encode(int input)
{
  assert(0 <= input && input <= 25);

  int output = input; // for now
  
  output = plugboard.encode(output);
  output = push_forward(output);
  output = reflector.encode(output);
  output = push_backward(output);
  output = plugboard.encode(output);

  update_rotors();

  return output;
}

void EnigmaMachine::update_rotors()
{
  rotors[0].rotate_anticlockwise();
  rotationCount[0] += 1;

  for(int pos = 0; pos < rotors.size(); pos++)
  {
    if(rotationCount[pos] == 26)
    {
      rotationCount[pos] = 0;
      rotors[pos+1].rotate_anticlockwise();
      rotationCount[pos+1] += 1;
    }
  }
}

int EnigmaMachine::push_forward(int input)
{
  int output = input; // for now
  for(Rotor rotor : rotors)
  {
    output = rotor.encode(output);
  }
  return output;
}

int EnigmaMachine::push_backward(int input)
{
  int output = input; // for now
  for(Rotor rotor : rotors)
  {
    output = rotor.decode(output);
  }
  return output;
}

vector<int> EnigmaMachine::read_file(char *filename)
{
  vector<int> input; int next;
  ifstream file (filename);

  while(!file.eof())
  {
    file >> ws; // ignore whitespace
    if(file.eof()) break; // don't look for int if eof
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

void EnigmaMachine::initialiseRotors(int argc, char** configFiles)
{
  for(int file = 1; file < argc-1; file++)
  {
    rotors.push_back(read_file(configFiles[file]));
  }
}



