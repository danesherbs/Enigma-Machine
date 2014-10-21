#include "Rotor.h"
#include <iostream>

using namespace std;

Rotor::Rotor(char *settings)
{
  forward.resize(LETTERS_IN_ALPHABET);
  backward.resize(LETTERS_IN_ALPHABET);

	configure(read_file(settings));

  rotation_count = 0; // hasn't rotated
}

bool Rotor::should_rotate_next() // True if rotates next rotor, false otherwise
{
  return rotation_count % 26 == 0;
}

int Rotor::encode(int input)
{
  /*
  if (forward[input] < 0) {
    return (26 + (input + forward[input])) % 26;
  }
  return (input + forward[input]) % 26;
  */

  /*
  cout << "Forward: " << input << endl;
  
  cout << "Forward map: ";
  for(int elem : forward)
  {
    cout << elem << " ";
  } cout << endl;  
  */

  return (input + forward[input]) % 26; // output = input + offset
}

int Rotor::decode(int input) 
{
  /*
  if (backward[input] < 0) {
    return (26 + (input + backward[input])) % 26;
  }
  return (input + backward[input]) % 26;
  */

  //std::cout << "Backward: " << input << " -> " << backward[input] << std::endl;

  /*
  cout << "Backward: " << input << endl;
  
  cout << "Backward map: ";
  for(int elem : backward)
  {
    cout << elem << " ";
  } cout << endl;
  */

  

  return (input + backward[input]) % 26; // output = input + offset
}


void Rotor::configure(std::vector<int> mapping)
{
  int current_char = 0; // start at 'A'

  for(int num : mapping) // initialize offsets from current char
  {
    forward[current_char] = (num - current_char + 26) % 26; // >= 0
    backward[num] = (current_char - num + 26) % 26; // >= 0
    current_char++; // move to next char
  }

  /*
  for(int elem : forward)
  {
    cout << elem << " ";
  } cout << endl;
  */

  /*
  forward = mapping;
  for(int i = 0; i < forward.size(); i++)
  {
    backward[forward[i]] = i;
  }
  */
}

void Rotor::rotate()
{
  rotation_count++;

  /*
  cout << "Rotation count: " << rotation_count << endl;

  cout << "Printing forward map before rotation: " << endl;
  for(int num : forward)
  {
    cout << num << " ";
  } cout << endl;
  */

  move_head_to_tail(forward);

  /*
  cout << "Printing forward map after rotation: " << endl;
  for(int num : forward)
  {
    cout << num << " ";
  } cout << endl;
  */

  move_head_to_tail(backward);

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
  
  // configure(forward);

}

void Rotor::move_head_to_tail(vector<int> &mapping)
{
  int head = mapping[0];
  mapping.erase(mapping.begin());
  mapping.push_back(head);
}

// FOR TESTING
void Rotor::move_tail_to_head(vector<int> mapping)
{
  int last = mapping.at(LETTERS_IN_ALPHABET-1);
  std::vector<int> temp(LETTERS_IN_ALPHABET, 0);
  for(int pos = 0; pos < LETTERS_IN_ALPHABET-1; pos++)
  {
    temp.at(pos+1) = mapping.at(pos); 
  }
  temp.at(0) = last;
  mapping = temp;
}














