# Compila los .cpp juntos.
#   make         -> genera el ejecutable ./torreDeHanoi
#   make clean   -> borra lo generado

torreDeHanoi: main.cpp Ficha.cpp Columna.cpp Ficha.h Columna.h
	g++ -std=c++17 -Wall -Wextra -g -o torreDeHanoi main.cpp Ficha.cpp Columna.cpp

clean:
	rm -f torreDeHanoi
	rm -rf torreDeHanoi.dSYM
