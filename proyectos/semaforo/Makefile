# Compila los dos .cpp juntos.
#   make         -> genera el ejecutable ./semaforo
#   make clean   -> borra lo generado

semaforo: main.cpp Semaforo.cpp Semaforo.h
	g++ -std=c++17 -Wall -Wextra -g -o semaforo main.cpp Semaforo.cpp

clean:
	rm -f semaforo
