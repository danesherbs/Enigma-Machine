#define EXIT_SUCCESS 0

#include <iostream>
#include <sstream>
#include <string>
#include "Enigma.h"

using namespace std;

int main(int argc, char **argv)
{
  EnigmaMachine enigmaMachine(argc, argv);

  char current_char;
  cin >> ws;
  while(!cin.eof())
  {
    cin >> current_char;
    cout << (char) enigmaMachine.encode(current_char);
    cin >> ws;
  }

  return EXIT_SUCCESS;
}