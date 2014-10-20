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
  EnigmaMachine enigmaMachine(argc, argv);

  
  char input = 'q';
  cin >> input;
  while(input != 'q')
  {
    cout << enigmaMachine.input_message(input) << endl;
    cin >> input;
  }

  //cout << enigmaMachine.input_message('A') << endl;
  


  std::vector<int> read_file(char *filename);
  return 0;
}