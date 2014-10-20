# edit this makefile so that running make compiles your enigma program

C_FLAGS = g++ -c -std=c++11

enigma: Main.o Enigma.o Reflector.o Plugboard.o Rotor.o
	g++ -std=c++11 Main.o Enigma.o Reflector.o Plugboard.o Rotor.o -o enigma

Main.o: Main.cpp
	$(C_FLAGS) Main.cpp

Enigma.o: Enigma.cpp Enigma.h
	$(C_FLAGS) Enigma.cpp

Reflector.o: Reflector.cpp Reflector.h
	$(C_FLAGS) Reflector.cpp

Plugboard.o: Plugboard.cpp Plugboard.h
	$(C_FLAGS) Plugboard.cpp

Configurable.o: Configurable.cpp Configurable.h
	$(C_FLAGS) Configurable.cpp

Rotor.o: Rotor.cpp Rotor.h
	$(C_FLAGS) Rotor.cpp

clean:
	rm -rf enigma *.o *.h.gch

.PHONY: clean
