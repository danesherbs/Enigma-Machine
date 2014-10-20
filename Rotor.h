#ifndef ROTOR_H
#define ROTOR_H

#include "Configurable.h"
#include "Encode.h"
#include "Decode.h"
#include <vector>
#include <map>

class Rotor : public Configurable, public Encode, public Decode
{
  public:
    Rotor(std::vector<int> configSettings);
    virtual int encode(int input);
    virtual int decode(int input);
    void rotate_anticlockwise();

  protected:
    virtual void configure(std::vector<int> configSettings);

  private:
    std::vector<int> forward, backward;
};

#endif /* ROTOR_H */