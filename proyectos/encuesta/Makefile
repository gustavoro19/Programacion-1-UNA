# Compila todos los .cpp juntos.
#   make         -> genera el ejecutable ./encuesta
#   make clean   -> borra lo generado
# Si el enlazado falla en macOS (error "tapi ... unknown architecture"):
#   make CXX="g++ -isysroot $(xcrun --show-sdk-path)"

CXX = g++
SRCS = main.cpp Participante.cpp Encuesta.cpp Respuesta.cpp Pregunta.cpp \
       PreguntaAbierta.cpp PreguntaOpcionMultiple.cpp PreguntaEscala.cpp Opcion.cpp
HDRS = Participante.h Encuesta.h Respuesta.h Pregunta.h \
       PreguntaAbierta.h PreguntaOpcionMultiple.h PreguntaEscala.h Opcion.h

# Los .h van como dependencias (recompila si cambian), no se le pasan a g++.
encuesta: $(SRCS) $(HDRS)
	$(CXX) -std=c++17 -Wall -Wextra -g -o encuesta $(SRCS)

clean:
	rm -f encuesta
