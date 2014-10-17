# edit this makefile so that running make compiles your enigma program

enigma: Main.o Enigma.o Reflector.o Plugboard.o
	g++ -o enigma Main.o Enigma.o Reflector.o Plugboard.o

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

clean:
	rm -rf enigma *.o

.PHONY: clean
