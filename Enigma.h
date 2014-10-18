#ifndef ENIGMA_H
#define ENIGMA_H

#include <fstream> // for read_file
#include <vector>  // for read_file
#include "Plugboard.h"

class EnigmaMachine : public Encode
{
  public:
    EnigmaMachine(int argc, char**);
    virtual int encode(int input) { return 1; };
  private: 	
   	std::vector<int> read_file(char *filename);
   	void initialiseIntCharMap();
   	std::map<int,char> intCharMap;
};

#endif /* ENIGMA_H */