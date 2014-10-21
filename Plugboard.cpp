#include "Plugboard.h"
#include <iostream>
#include <numeric>

using namespace std;

// Public
Plugboard::Plugboard(char* settings)
{
  mapping = std::vector<int>(LETTERS_IN_ALPHABET,0);
  std::iota(mapping.begin(), mapping.end(), 0);

  configure(read_file(settings));
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
  
  for(int pos = 0; pos < configSettings.size(); pos++)
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
  return mapping;
}

void Plugboard::set_map_val(int value, int index)
{
  mapping[index] = value;
}
