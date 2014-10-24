#ifndef ENIGMA_H
#define ENIGMA_H

#include <vector>
#include <string>

#include "Plugboard.h"
#include "Rotor.h"
#include "Reflector.h"

class EnigmaMachine : public Encode
{
  public:

    EnigmaMachine(int argc, char**);
    virtual int encode(int input);

  private:

  	Plugboard plugboard;
  	Reflector reflector;
  	std::vector<Rotor> rotors;
   	std::vector<int> intCharMap;
   	
  	void initialiseRotors(int argc, char** configFiles);

   	void update_rotors(int);
  	int push_forward(int input);
  	int push_backward(int input);
};

#endif /* ENIGMA_H */