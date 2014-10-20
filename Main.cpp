#define EXIT_SUCCESS 0

#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>

#include "Enigma.h"
#include "Reflector.h"
#include "Plugboard.h"
#include "Rotor.h"

using namespace std;
char intToChar(int input);
int charToInt(char chr);

int main(int argc, char **argv)
{
  EnigmaMachine enigmaMachine(argc, argv);

  string input_str;
  cin >> input_str;
  cout << enigmaMachine.input_message(input_str) << endl;    

  return EXIT_SUCCESS;
}