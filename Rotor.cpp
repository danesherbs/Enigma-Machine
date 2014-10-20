#include "Rotor.h"
#include <iostream>

Rotor::Rotor(std::vector<int> configSettings)
{
  forward.resize(LETTERS_IN_ALPHABET);
  backward.resize(LETTERS_IN_ALPHABET);

  forward = configSettings; // configSettings = forward mapping
	configure(forward);
}

int Rotor::encode(int input)
{
  std::cout << "Forward: " << input << " -> " << forward[input] << std::endl;
  return forward[input];
}

int Rotor::decode(int input) 
{
  std::cout << "Backward: " << input << " -> " << backward[input] << std::endl;
  return backward[input];
}

void Rotor::configure(std::vector<int> forward)
{
  for(int i = 0; i < forward.size(); i++)
  {
    backward[forward[i]] = i;
  }
}

void Rotor::rotate_anticlockwise() // anti-clockwise
{
  int first = forward[0];
  forward.erase(forward.begin());
  forward.push_back(first);
  configure(forward);
}