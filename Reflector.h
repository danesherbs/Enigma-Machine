#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <assert.h>

#include "Encode.h"

class Reflector : public Encode
{
    public:

    	int encode(int);

    private:
    	
    	static const int SHIFT = 13;
    	static const int LETTERS_IN_ALPHABET = 26;
};

#endif /* REFLECTOR_H */