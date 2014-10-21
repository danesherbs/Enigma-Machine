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
  	std::string input_message(std::string);
    virtual int encode(int input);

  private:

    // Fields
  	Plugboard plugboard;
  	Reflector reflector;
  	std::vector<Rotor> rotors;
   	std::vector<int> read_file(char *filename);
   	std::vector<int> intCharMap;
   	
   	// Initialisaiton
  	void initialiseRotors(int argc, char** configFiles);
  	void initialisePlugboard(int argc, char** configFiles);

    // Helpers
   	void update_rotors(int);
  	int push_forward(int input);
  	int push_backward(int input);
};

#endif /* ENIGMA_H */