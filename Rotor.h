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
    void rotate_clockwise();

  protected:

    virtual void configure(std::vector<int> configSettings);

  private:

    // void printRotorConfig(); // TEMP
    std::vector<int> clone(std::vector<int> configSettings); // TEMP

    std::vector<int> forward, backward;
};

#endif /* ROTOR_H */