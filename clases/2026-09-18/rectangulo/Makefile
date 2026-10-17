# Compila los dos .cpp juntos.
#   make         -> genera el ejecutable ./rectangulo
#   make clean   -> borra lo generado

rectangulo: main.cpp Rectangulo.cpp Rectangulo.h
	g++ -std=c++17 -Wall -Wextra -g -o rectangulo main.cpp Rectangulo.cpp

clean:
	rm -f rectangulo
