#ifndef ENIGMA_H
#define ENIGMA_H

#include <map>
#include "Constants.h"

class EnigmaMachine
{
    public:
    	EnigmaMachine();
        std::map<int,char> mapIntToChar;
    private:
       	void initialiseMapping();    
};

#endif /* ENIGMA_H */