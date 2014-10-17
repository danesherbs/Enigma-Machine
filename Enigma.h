#ifndef ENIGMA_H
#define ENIGMA_H

#include "Configurable.h"
#include "Constants.h"
#include <fstream> // for read_file
#include <vector>  // for read_file
#include <map>

class EnigmaMachine : public Configurable
{
  public:
    EnigmaMachine(char**);
    std::map<int,char> mapIntToChar; // TODO: abstract to constants and make static const
  protected:
  	virtual void configure(char**);
  private: 	
   	void initialiseMapping();
   	std::vector<int> read_file(char *filename);
};

#endif /* ENIGMA_H */