#include "Rotor.h"

Rotor::Rotor(std::vector<int> configSettings)
{
	configure(configSettings);
}

int Rotor::encode(int input) 
{
  int output = forward[input];
  rotate();
  return output;
}

int Rotor::decode(int input) 
{
  return backward[input];
}

void Rotor::configure(std::vector<int> configSettings)
{
  std::vector<int> forward, backward;
  forward = configSettings;
  for(int i = 0; i < configSettings.size(); i++)
  {
    backward[forward[i]] = i;
  }
}

void Rotor::rotate() // anti-clockwise
{
  int first = forward[0];
  forward.erase(forward.begin());
  forward.push_back(first);
  configure(forward);
}