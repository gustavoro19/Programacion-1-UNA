# Compila los dos .cpp juntos.
#   make         -> genera el ejecutable ./printer
#   make clean   -> borra lo generado

printer: main.cpp Printer.cpp Printer.h
	g++ -std=c++17 -Wall -Wextra -g -o printer main.cpp Printer.cpp

clean:
	rm -f printer
	rm -rf printer.dSYM
