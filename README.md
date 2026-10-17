# Programación I (EIF201) — Universidad Nacional

Código del curso **EIF201 Programación I**, Escuela de Informática, UNA.
Autor: Gustavo Rojas Porras.

## Estructura

```
.
├── labs/                Laboratorios del curso
│   ├── lab1/            Entrada/salida básica y funciones
│   ├── lab2/            Condicionales y argumentos de main (argc/argv)
│   │   └── borradores/  Versiones anteriores de los ejercicios del lab 2
│   ├── lab3/            Arreglos (arrays) con ciclos for: suma, promedio, máximo
│   └── lab4/            Ciclos (for, while, do-while) y menús
├── clases/              Ejemplos vistos en clase, por fecha
│   ├── 2026-09-18/      punteros/referencias, rectangulo, vectores
│   ├── 2026-09-25/      torreDeHanoi
│   └── 2026-10-02/      practica
├── proyectos/           Programas con clases (.h + .cpp + Makefile)
│   ├── encuesta/        Sistema de encuestas con herencia y menú
│   ├── semaforo/
│   ├── student/
│   └── reto/            estudiante, printer
├── juegos/              Lotería, Escudo o Corona, Gato
├── tarea/               Tarea: día de la semana y tipos de datos
├── quices/
└── practicas/
```

## Cómo compilar

**Programas de un solo archivo** (labs, juegos, quices):

```bash
g++ -std=c++17 -Wall -o programa archivo.cpp
./programa
```

**Proyectos con Makefile** (`proyectos/*`, `clases/2026-09-18/rectangulo`,
`clases/2026-09-25/torreDeHanoi`):

```bash
cd proyectos/encuesta
make          # compila
./encuesta    # ejecuta
make clean    # borra el ejecutable
```

### macOS: error `tapi error: malformed file ... unknown architecture`

Pasa cuando las Command Line Tools no coinciden con la versión de macOS.
Se puede compilar usando el SDK de Xcode:

```bash
make CXX="g++ -isysroot $(xcrun --show-sdk-path)"
```

(Solo el Makefile de `proyectos/encuesta` acepta `CXX`; en los demás, o con
`g++` directo, se agrega `-isysroot $(xcrun --show-sdk-path)` al comando.)
