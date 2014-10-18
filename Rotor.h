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
    virtual int encode(int input) { return 1; };
    virtual int decode(int input) { return 1; };
  protected:
    virtual void configure(std::vector<int> configSettings);
  private:
    std::map<int,int> forward_map;
    std::map<int,int> backward_map;
    void rotate();
};

#endif /* ROTOR_H */