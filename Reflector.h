#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "Constants.h"

class Reflector
{
    public:
    	Reflector(); //  need initialisation list since const can only be defined once
        char reflect(char chr);
};

#endif /* REFLECTOR_H */