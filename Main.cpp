// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>

#include "Enigma.h"
#include "Reflector.h"

using namespace std;

int main(int argc, char **argv)
{
  cout << "TODO: implement an Enigma machine" << endl;

  Reflector reflector;
  cout << reflector.reflect('A') << endl;
  cout << reflector.reflect('M') << endl;

  return 0;
}