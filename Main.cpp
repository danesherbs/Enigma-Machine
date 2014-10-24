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

  char current_char;
  cin >> ws;
  while(!cin.eof())
  {
    cin >> current_char;
    cout << (char) enigmaMachine.encode(current_char);
    
    if(current_char == '\n') // preserve new lines
    {
      cout << '\n';
    }
    
    cin >> ws;
  }

  return EXIT_SUCCESS;
}