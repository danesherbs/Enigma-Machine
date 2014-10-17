#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "Configurable.h"
#include "Encode.h"

class Plugboard : public Configurable, public Encode
{
  public:
  	Plugboard(char* configFile);
    virtual int encode(int input);
  protected:
  	virtual void configure(char**);
  	
};

#endif // PLUGBOARD_H