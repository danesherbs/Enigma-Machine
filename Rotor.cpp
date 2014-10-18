#include "Rotor.h"

Rotor::Rotor(std::vector<int> configSettings)
{
	configure(configSettings);
}

void Rotor::configure(std::vector<int> configSettings)
{
  std::vector<int> forward, backward;
  int count = 0;
  for(int i = 0; i < configSettings.size(); i++)
  {
    forward_map[i] = configSettings[i];
    backward_map[forward_map[i]] = i;
  }
}

void Rotor::rotate() // review
{
  int first = forward_map[0];
  forward_map.erase(forward_map.begin());
  forward_map = forward_map.push_back(first);
  configure(forward_map);
}