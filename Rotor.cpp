#include "Rotor.h"
#include <iostream>

using namespace std;

Rotor::Rotor(std::vector<int> configSettings)
{
  forward.resize(LETTERS_IN_ALPHABET);
  backward.resize(LETTERS_IN_ALPHABET);

  forward = configSettings; // configSettings = forward mapping
	configure(forward);

  rotation_count = 0; // hasn't rotated
}

// START

bool Rotor::rotate() // True if rotates next rotor, false otherwise
{
  return ++rotation_count % 26 == 0;
}

// END

int Rotor::encode(int input)
{
  cout << "Forward map: ";
  for(int elem : forward)
  {
    cout << elem << " ";
  } cout << endl;

  cout << "Forward: " << input << endl;

  return forward[input];
}

int Rotor::decode(int input) 
{
  //std::cout << "Backward: " << input << " -> " << backward[input] << std::endl;

  cout << "Backward map: ";
  for(int elem : backward)
  {
    cout << elem << " ";
  } cout << endl;

  cout << "Backward: " << input << endl;

  return backward[input];
}


void Rotor::configure(std::vector<int> forward)
{
  for(int i = 0; i < forward.size(); i++)
  {
    backward[forward[i]] = i;
  }
}

void Rotor::rotate_anticlockwise() // anti-clockwise
{
  int first = forward[0];
  forward.erase(forward.begin());
  forward.push_back(first);
  

  /*  
  int last = forward.at(LETTERS_IN_ALPHABET-1);
  std::vector<int> temp(LETTERS_IN_ALPHABET, 0);
  for(int pos = 0; pos < LETTERS_IN_ALPHABET-1; pos++)
  {
    temp.at(pos+1) = forward.at(pos); 
  }
  temp.at(0) = last;
  forward = temp;
  */

  /*  
  cout << "Printing forward map: " << endl;
  for(int num : forward)
  {
    cout << num << " ";
  } cout << endl;

  cout << "Printing backward map: " << endl;
  for(int num : backward)
  {
    cout << num << " ";
  } cout << endl;
  */
  configure(forward);

}