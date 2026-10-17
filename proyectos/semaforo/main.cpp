#include <iostream>
#include "Semaforo.h"

using namespace std;

int main()
{
   Semaforo semaforo {"\033[31mROJO\033[0m", 2000};
   semaforo.funcionar();

    return 0;
}
