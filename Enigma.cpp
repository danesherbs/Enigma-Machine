#include "Enigma.h"
#include "Rotor.h"

#include <assert.h>

using namespace std;

EnigmaMachine::EnigmaMachine(int argc, char** configFiles) //: plugboard(read_file(configFiles[argc-1]))
{
  // Field(s)
  initialiseIntCharMap();

  // Plugboard
  Plugboard new_plugboard(read_file(configFiles[argc-1]));
  set_plugboard(new_plugboard);

  // Rotor(s)
  initialiseRotors(argc, configFiles);
  this->rotationCount = std::vector<int>(rotors.size(), 0);
}

string EnigmaMachine::input_message(string input_str)
{
    char current_char;
    string str_result;

    for(int pos = 0; pos < input_str.length(); pos++)
    {
        current_char = input_str[pos];
        str_result.push_back(encode(charToInt(current_char)) + ASCII_A);
    }

    return str_result;
}

int EnigmaMachine::charToInt(char chr)
{
  return chr - ASCII_A;
}

int EnigmaMachine::encode(int input)
{
  assert(0 <= input && input <= 25);

  int output = input; // for now
  
  //cout << "Input: " << input << endl;
  output = plugboard.encode(output);
  //cout << "After plugboard: " << output << endl;
  output = push_forward(output);
  //cout << "After rotors: " << output << endl;
  output = reflector.encode(output);
  //cout << "After reflector: " << output << endl;
  output = push_backward(output);
  //cout << "After rotors: " << output << endl;
  output = plugboard.encode(output);
  //cout << "After plugboard: " << output << endl;

  //cout << "Updating rotors... ";
  update_rotors();
  //cout << "Done." << endl;
/* FOR TEST

  cout << "Size of rotationCount = " << this->rotationCount.size() << endl;
  cout << "Rotation count: " << this->rotationCount.at(0) << endl;
*/

  return output;
}

void EnigmaMachine::update_rotors()
{
  if(rotors.size() != 0)
  {
    rotors[0].rotate_anticlockwise();
    rotationCount[0] += 1;
  }

  // update rotation count; propagate rotation if necessary
  for(int pos = 0; pos < rotors.size(); pos++)
  {
    if(rotationCount[pos] == 26)
    {
      rotationCount[pos] = 0;
      if(pos + 1 < rotors.size())
      {
        rotors[pos + 1].rotate_anticlockwise();
        rotationCount[pos + 1] += 1;
      }
      else
      {
        break;
      }
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

vector<int> EnigmaMachine::read_file(char *filename)
{
  vector<int> input; int next;
  ifstream file (filename);
  if(!file.is_open())
  {
    exit(-1);
  }

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
  for(int file = 1; file < argc - 1; file++)
  {
    rotors.push_back(read_file(configFiles[file]));
  }
}

void EnigmaMachine::set_plugboard(Plugboard plugboard)
{
  this->plugboard = plugboard;
}

