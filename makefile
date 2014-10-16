# edit this makefile so that running make compiles your enigma program

enigma: Main.o Enigma.o Reflector.o
	g++ -o enigma Main.o Enigma.o Reflector.o

Main.o: Main.cpp
	g++ -c Main.cpp

Enigma.o: Enigma.cpp
	g++ -c Enigma.cpp

Reflector.o: Reflector.cpp
	g++ -c Reflector.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
