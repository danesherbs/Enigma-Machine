#include "Plugboard.h"

// Public
Plugboard::Plugboard(std::vector<int> configSettings) {
  initialiseMapping();
	configure(configSettings);
}

int Plugboard::encode(int input)
{
  return mapping[input];
}

// Protected
void Plugboard::configure(std::vector<int> configSettings)
{
  assert(configSettings.size() % 2 == 0); // must have even num of mappings

  int first, second; // elements of pair to be swapped
  for(size_t size = 0; size < configSettings.size(); size++)
  {
    first  = configSettings[size];
    second = configSettings[++size];

    mapping[first]  = second;
    mapping[second] = first;
  }
}

// Private
void Plugboard::initialiseMapping()
{
  for(int i = 0; i < LETTERS_IN_ALPHABET; i++)
  {
    mapping[i] = i;
  }
}