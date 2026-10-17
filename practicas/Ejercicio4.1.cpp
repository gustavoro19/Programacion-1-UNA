#include <iostream>

using namespace std;

int main() {

  int arreglo1[] = {100, 66, 2, 3, 4, -5};
  int max = 0;

  for (int i = 0; i < sizeof(arreglo1) / sizeof(arreglo1[0]); i++) {
    if (arreglo1[i] > max) {
      max = arreglo1[i];
    }
  }

  cout << "El max es: " << max << endl;
}