#include "Plugboard.h"
#include <iostream>
#include <numeric>

using namespace std;

// Public
Plugboard::Plugboard(std::vector<int> configSettings)
{
  set_map(init_map());
  configure(configSettings);
}

int Plugboard::encode(int input)
{
  return get_map().at(input);
}

// Protected
void Plugboard::configure(std::vector<int> configSettings)
{
  assert(configSettings.size() % 2 == 0); // must have even num of mappings

  int first, second; // elements of pair to be swapped
  
  for(size_t pos = 0; pos < configSettings.size(); pos++)
  {
    first  = configSettings[pos];
    second = configSettings[++pos];
    set_map_val(first, second);
    set_map_val(second, first);
  }
}

// Private
std::vector<int> Plugboard::get_map()
{
  return this->mapping;
}


void Plugboard::set_map(std::vector<int> new_map)
{
  this->mapping = new_map;
}

void Plugboard::set_map_val(int value, int index)
{
  this->mapping[index] = value;
}

std::vector<int> Plugboard::init_map()
{
  std::vector<int> map(26);
  std::iota(map.begin(), map.end(), 0);
  return map;
}

