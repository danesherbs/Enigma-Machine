#include "Rotor.h"
#include <iostream>

Rotor::Rotor(std::vector<int> configSettings)
{
  forward.resize(LETTERS_IN_ALPHABET);
  backward.resize(LETTERS_IN_ALPHABET);
	configure(configSettings);
}

// TEMP

/*
void Rotor::printRotorConfig()
{
  std::cout << "Forward: ";
  for(auto elem : forward)
  {
    std::cout << elem << " ";
  } std::cout << std::endl;

  std::cout << "Backward: ";
  for(auto elem : backward)
  {
    std::cout << elem << " ";
  } std::cout << std::endl;

  rotate_anticlockwise();
}

*/

// end TEMP

int Rotor::encode(int input) 
{
  int output = forward[input];
  rotate_anticlockwise();
  return output;
}

int Rotor::decode(int input) 
{
  return backward[input];
}

void Rotor::configure(std::vector<int> configSettings)
{
  forward = clone(configSettings); // configSettings = forward mapping
  for(int i = 0; i < backward.size(); i++)
  {
    backward[forward[i]] = i;
  }
}

std::vector<int> Rotor::clone(std::vector<int> configSettings)
{
  return configSettings;
}

void Rotor::rotate_anticlockwise() // anti-clockwise
{
  int first = forward[0];
  forward.erase(forward.begin());
  forward.push_back(first);
  configure(forward);
}

void Rotor::rotate_clockwise() // clockwise
{
  int last = forward[25];
  forward.erase(forward.end());
  forward.insert(forward.begin(), last);
  configure(forward);
}