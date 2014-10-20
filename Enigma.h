#ifndef ENIGMA_H
#define ENIGMA_H

#include <fstream> // for read_file
#include <vector>  // for read_file
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
   	std::map<int,char> intCharMap;
   	std::vector<int> rotationCount;
   	
   	// Initialisaiton
   	void initialiseIntCharMap();
  	void initialiseRotors(int argc, char** configFiles);
  	void initialisePlugboard(int argc, char** configFiles);

    // Helpers
  	int charToInt(char);
   	void update_rotors();
  	int push_forward(int input);
  	int push_backward(int input);

  	// Getters and setters
  	void set_plugboard(Plugboard plugboard);
  	Plugboard get_plugboard();
};

#endif /* ENIGMA_H */