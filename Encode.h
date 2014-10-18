#ifndef ENCODE_H
#define ENCODE_H

class Encode
{
  public:
  	virtual int encode(int input) = 0;
  protected:
  	static const char ASCII_A = 65;
  	static const int LETTERS_IN_ALPHABET = 26;
};

#endif // ENCODE_H