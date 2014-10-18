#ifndef ROTOR_H
#define ROTOR_H

#include "Configurable.h"
#include "Encode.h"
#include "Decode.h"
#include <vector>

class Rotor : public Configurable, public Encode, public Decode
{
  public:
    Rotor(std::vector<int> configSettings);
    virtual void configure(std::vector<int> configSettings) {};
    virtual int encode(int input) { return 1; };
    virtual int decode(int input) { return 1; };
  private:
    std::map<int,int> mapping;
};

#endif /* ROTOR_H */