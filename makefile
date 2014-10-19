# edit this makefile so that running make compiles your enigma program

enigma: Main.o Enigma.o Reflector.o Plugboard.o Rotor.o
	g++ -o enigma Main.o Enigma.o Reflector.o Plugboard.o Rotor.o

Main.o: Main.cpp
	g++ -c Main.cpp

Enigma.o: Enigma.cpp Enigma.h
	g++ -c Enigma.cpp

Reflector.o: Reflector.cpp Reflector.h
	g++ -c Reflector.cpp

Plugboard.o: Plugboard.cpp Plugboard.h
	g++ -c Plugboard.cpp

Configurable.o: Configurable.cpp Configurable.h
	g++ -c Configurable.cpp

Rotor.o: Rotor.cpp Rotor.h
	g++ -c Rotor.cpp

clean:
	rm -rf enigma *.o *.h.gch

.PHONY: clean
