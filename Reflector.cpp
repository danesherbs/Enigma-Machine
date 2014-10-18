#include "Reflector.h"

// Pre: 0 <= chr <= 25
int Reflector::reflect(int input)
{
	assert(0 <= input && input <= 25);
	return ( input + SHIFT ) % LETTERS_IN_ALPHABET;
}