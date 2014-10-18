#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "Configurable.h"
#include "Encode.h"
#include "Decode.h"
#include <map>
#include <iostream>
#include <assert.h>

class Plugboard : public Configurable, public Encode, public Decode
{
  public:
  	Plugboard(std::vector<int> configSettings);
    virtual int encode(int input);
    virtual int decode(int input) { return encode(input); };
  protected:
  	virtual void configure(std::vector<int> configSettings);
  private:
  	std::map<int,int> mapping;
  	void initialiseMapping();
};

#endif // PLUGBOARD_H