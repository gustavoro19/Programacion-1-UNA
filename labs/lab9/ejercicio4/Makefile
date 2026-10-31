# make        -> genera el ejecutable ./calculadora
# make clean  -> borra lo generado
# Si el enlazado falla en macOS (error "tapi ... unknown architecture"):
#   make CXX="g++ -isysroot $(xcrun --show-sdk-path)"
CXX = g++
SRCS = main.cpp Operacion.cpp Suma.cpp Resta.cpp Multiplicacion.cpp Division.cpp
HDRS = Operacion.h Suma.h Resta.h Multiplicacion.h Division.h

calculadora: $(SRCS) $(HDRS)
	$(CXX) -std=c++17 -Wall -Wextra -g -o calculadora $(SRCS)

clean:
	rm -f calculadora
