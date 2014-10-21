#include "Configurable.h"

std::vector<int> Configurable::read_file(char *filename)
{
  vector<int> input; int next;
  ifstream file (filename);
  if(!file.is_open())
  {
    exit(-1);
  }

  while(!file.eof())
  {
    file >> ws; // ignore whitespace
    if(file.eof()) break; // don't look for int if eof
    file >> next; // store next int
    input.push_back(next); // append to vector
  }

  file.close();
  
  return input;
}