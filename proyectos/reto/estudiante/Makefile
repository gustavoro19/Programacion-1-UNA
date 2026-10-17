# Compila los dos .cpp juntos.
#   make         -> genera el ejecutable ./estudiante
#   make clean   -> borra lo generado

estudiante: main.cpp Estudiante.cpp Estudiante.h
	g++ -std=c++17 -Wall -Wextra -g -o estudiante main.cpp Estudiante.cpp

clean:
	rm -f estudiante
	rm -rf estudiante.dSYM
