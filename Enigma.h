#ifndef ENIGMA_H
#define ENIGMA_H

#include "Constants.h"
#include <fstream> // for read_file
#include <vector>  // for read_file
#include <map>

class EnigmaMachine
{
  public:
    EnigmaMachine(char**);
    std::map<int,char> mapIntToChar; // TODO: abstract to constants and make static const
  private: 	
   	void initialiseMapping();
   	std::vector<int> read_file(char *filename);
};

#endif /* ENIGMA_H */