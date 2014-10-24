#include "Enigma.h"
#include "Rotor.h"

#include <assert.h>
#include <numeric>

using namespace std;

EnigmaMachine::EnigmaMachine(int argc, char** configFiles)
{
  intCharMap.resize(LETTERS_IN_ALPHABET);
  std::iota(intCharMap.begin(), intCharMap.end(), 65);

  plugboard = Plugboard(configFiles[argc-1]);

  initialiseRotors(argc, configFiles);
}

string EnigmaMachine::input_message(string input_str)
{
  char current_char;
  string str_result;

  for(int pos = 0; pos < input_str.length(); pos++)
  {   
    current_char = input_str[pos];
    str_result.push_back(encode(current_char -ASCII_A) + ASCII_A);
  }
  
  return str_result;
}

int EnigmaMachine::encode(int input)
{
  int output = input - ASCII_A; // for now

  assert(0 <= output && output <= 25);
  
  output = plugboard.encode(output);
  output = push_forward(output);
  output = reflector.encode(output);
  output = push_backward(output);
  output = plugboard.encode(output);

  if(!rotors.empty()) update_rotors(0);

  return output + ASCII_A;
}

void EnigmaMachine::update_rotors(int current_pos)
{
  rotors.at(current_pos).rotate();

  for (Rotor rotor : rotors)
  {
    if(rotor.should_rotate_next() && current_pos + 1 < rotors.size())
    {
      rotors.at(current_pos + 1).rotate();
    } else {
      break;
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
  for(auto it = rotors.rbegin(); it != rotors.rend(); ++it)
  {
    output = it->decode(output);
  }
  return output;
}

void EnigmaMachine::initialiseRotors(int argc, char** configFiles)
{
  for(int file = 1; file < argc - 1; file++)
  {
    rotors.push_back(Rotor(configFiles[file]));
  }
}