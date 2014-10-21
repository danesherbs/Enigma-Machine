#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "Configurable.h"
#include "Encode.h"
#include "Decode.h"

#include <vector>
#include <iostream>
#include <assert.h>

class Plugboard : public Configurable, public Encode, public Decode
{
  public:

  	Plugboard() {};
  	Plugboard(char* configSetting);
    virtual int encode(int input) override;
    virtual int decode(int input) { return encode(input); };

  protected:

    virtual void configure(std::vector<int> configSettings);
  
  private:

    // Fields
    std::vector<int> mapping;

    // Getters and setters
    std::vector<int> get_map();
    void set_map(std::vector<int>);
    void set_map_val(int, int);

    // Initialisers
    std::vector<int> init_map();
};

#endif // PLUGBOARD_H