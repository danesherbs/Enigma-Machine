#include "Rotor.h"
#include <iostream>

using namespace std;

Rotor::Rotor(char *settings)
{
  forward.resize(LETTERS_IN_ALPHABET);
  backward.resize(LETTERS_IN_ALPHABET);

	configure(read_file(settings));

  rotation_count = 0; // hasn't rotated
}

bool Rotor::should_rotate_next() // True if rotates next rotor, false otherwise
{
  return rotation_count % 26 == 0;
}

int Rotor::encode(int input)
{
  return (input + forward[input]) % 26; // output = input + offset
}

int Rotor::decode(int input) 
{
  return (input + backward[input]) % 26; // output = input + offset
}

void Rotor::configure(std::vector<int> mapping)
{
  int current_char = 0; // start at 'A'

  for(int num : mapping) // initialize offsets from current char
  {
    forward[current_char] = (num - current_char + 26) % 26; // >= 0
    backward[num] = (current_char - num + 26) % 26; // >= 0
    current_char++; // move to next char
  }
}

void Rotor::rotate()
{
  rotation_count++;
  move_head_to_tail(forward);
  move_head_to_tail(backward);
}

void Rotor::move_head_to_tail(vector<int> &mapping)
{
  int head = mapping[0];
  mapping.erase(mapping.begin());
  mapping.push_back(head);
}