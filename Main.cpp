#include <stdexcept>
#include <iostream>
#include <vector>
#include <cstring>

#include "Enigma.h"
#include "Reflector.h"
#include "Plugboard.h"
#include "Rotor.h"

using namespace std;
char intToChar(int input);
int charToInt(char chr);

int main(int argc, char **argv)
{
  std::cout << "Before enigmaMachine" << endl;
  EnigmaMachine enigmaMachine(argc, argv);
  std::cout << "After enigmaMachine" << endl;

  /*
  char input[] = "";
  cin >> input;
  while(strcmp(input, ":q") != 0)
  {

  }

  cout << enigmaMachine.input_message('A') << endl;
  */

  std::vector<int> read_file(char *filename);
  return 0;
}