#include "Rotor.h"

Rotor::Rotor(std::vector<int> configSettings)
{
	configure(configSettings);
}

void configure(std::vector<int> configSettings)
{
  mapping = configSettings;
}