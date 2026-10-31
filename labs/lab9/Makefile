# Compila los cuatro ejercicios del laboratorio 9.
#   make        -> ejercicio1, ejercicio2, ejercicio3 y ejercicio4/calculadora
#   make clean  -> borra los ejecutables
# Si el enlazado falla en macOS (error "tapi ... unknown architecture"):
#   make CXX="g++ -isysroot $(xcrun --show-sdk-path)"
CXX = g++
FLAGS = -std=c++17 -Wall -Wextra

all: ejercicio1 ejercicio2 ejercicio3 calculadora

ejercicio1: ejercicio1.cpp
	$(CXX) $(FLAGS) -o ejercicio1 ejercicio1.cpp

ejercicio2: ejercicio2.cpp
	$(CXX) $(FLAGS) -o ejercicio2 ejercicio2.cpp

ejercicio3: ejercicio3.cpp
	$(CXX) $(FLAGS) -o ejercicio3 ejercicio3.cpp

calculadora:
	$(MAKE) -C ejercicio4 CXX="$(CXX)"

clean:
	rm -f ejercicio1 ejercicio2 ejercicio3
	$(MAKE) -C ejercicio4 clean

.PHONY: all calculadora clean
