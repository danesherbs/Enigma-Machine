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

  // START Sacha's code

  /*
  if (argc > 2)
  {
    for(int i = 1; i < argc-1; i++)
    {
      rotor = new Rotor(arg[i]);
      rotors.push_back(*rotor);
    }
  }
  */

  // END Sacha's code

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

    //cout << "IN INPUT MESSAGE: I'm outputting the result " << str_result << endl;

    return str_result;
}

int EnigmaMachine::encode(int input)
{
  assert(0 <= input && input <= 25);

  int output = input; // for now
  
  //cout << endl << "Input: " << input << endl;
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
  if(!rotors.empty()) update_rotors(0);
  //cout << "Done." << endl;

  return output;
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
  //cout << "Number of rotors: " << rotors.size() << endl;

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

