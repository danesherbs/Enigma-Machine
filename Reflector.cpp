#include "Reflector.h"

#include <iostream>

Reflector::Reflector() {}

char Reflector::reflect(char chr)
{
    int chrInt = chr - ASCII_A; // 0 <= chrInt <= 25
	return (char) ( chrInt + SHIFT ) % LETTERS_IN_ALPHABET + ASCII_A;
}