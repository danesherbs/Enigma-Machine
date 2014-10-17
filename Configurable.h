#ifndef CONFIGURABLE_H
#define CONFIGURABLE_H

#include <vector>

class Configurable
{
  protected:
  	virtual void configure(std::vector<int> configSettings) = 0;
};

#endif