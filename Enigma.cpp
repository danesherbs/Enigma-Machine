#include "Enigma.h"

EnigmaMachine::EnigmaMachine()
{
	EnigmaMachine::initialiseMapping();
}

void EnigmaMachine::initialiseMapping()
{
  for (int idx = 0; idx < LETTERS_IN_ALPHABET; idx++)
  {
    mapIntToChar[idx] = (char) ASCII_A + idx;
  }
}