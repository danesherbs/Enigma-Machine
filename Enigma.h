#ifndef ENIGMA_H
#define ENIGMA_H

#include <fstream> // for read_file
#include <vector>  // for read_file
#include "Plugboard.h"

class EnigmaMachine
{
  public:
    EnigmaMachine(char**);
  private: 	
   	std::vector<int> read_file(char *filename);
   	void initialiseIntCharMap();
   	std::map<int,char> intCharMap;
   	static 
   	const char ASCII_A = 65;
};

#endif /* ENIGMA_H */