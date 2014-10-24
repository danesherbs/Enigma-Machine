#define EXIT_SUCCESS 0

#include <iostream>
#include "Enigma.h"

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
    cin >> ws;

    if(cin.eof()) cout << endl;
  }

  return EXIT_SUCCESS;
}