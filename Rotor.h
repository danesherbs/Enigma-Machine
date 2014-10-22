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

    Rotor(char*);
    virtual int encode(int input);
    virtual int decode(int input);
    void rotate();
    bool should_rotate_next();

  protected:

    virtual void configure(std::vector<int> configSettings);

  private:
    
    std::vector<int> forward, backward;
    int rotation_count;
    void move_head_to_tail(std::vector<int> &mapping);
};

#endif /* ROTOR_H */