#include "Reflector.h"

int Reflector::encode(int input)
{
	assert(0 <= input && input <= 25);
	return ( input + SHIFT ) % LETTERS_IN_ALPHABET;
}