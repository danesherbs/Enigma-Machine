#ifndef CONFIGURABLE_H
#define CONFIGURABLE_H

#include <vector>

class Configurable
{
  public:
    std::vector<char*> readFiles(int argc, char **argv);
  protected:
  	virtual void configure(char** configFile) = 0;
};

#endif