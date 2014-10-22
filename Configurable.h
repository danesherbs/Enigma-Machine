#ifndef CONFIGURABLE_H
#define CONFIGURABLE_H

#include <vector>
#include <fstream>
#include <iostream>

class Configurable
{
  protected:
  	
  	virtual void configure(std::vector<int> configSettings) = 0;
  	std::vector<int> read_file(char*);
};

#endif //CONFIGURABLE_H