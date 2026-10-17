# Compila los dos .cpp juntos.
#   make         -> genera el ejecutable ./student
#   make clean   -> borra lo generado

student: main.cpp Student.cpp Student.h
	g++ -std=c++17 -Wall -Wextra -g -o student main.cpp Student.cpp

clean:
	rm -f student
