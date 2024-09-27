#include <stdio.h>
#include "../Ejercicio 01/Inciso d/colaDinamica.h"

void leerCola(TCola *c);

int main() {
    TCola cola;
    TElementoC n;
    int suma;
    IniciaC(&cola);
    leerCola(&cola);
    suma = 0;
    while(!VaciaC(cola)) {
        sacaC(&cola, &n);
        suma += n;
    }
    printf("%d", suma);
    return 0;
}

void leerCola(TCola *c) {
    TElementoC n;
    IniciaC(c);
    while(scanf("%d", &n) == 1)
        poneC(c, n);
} 