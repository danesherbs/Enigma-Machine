#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <map>

const int ASCII_A (65);
const int SHIFT (13);
const int LETTERS_IN_ALPHABET (26);

// Map from int to char
/*
std::map<int,char> create_mappy()
{
  std::map<int,char> intCharMap;
  for (int idx = 0; idx < LETTERS_IN_ALPHABET; idx++)
  {
    intCharMap[idx] = (char) ASCII_A + idx;
  }
  return intCharMap;
}

std::map<int,char> intCharMap = create_mappy();
*/

#endif // CONSTANTS_H