#include <stdio.h>
#include "TDA Cola/cola.h"
#define N 3

void grados(unsigned int T[][N], TCola *C, unsigned int *costo, unsigned int i, unsigned int j, unsigned int grado);
void mostrarCola(TCola *C);

int main()
{
    unsigned int T[N][N] = {{0, 1, 2},
                            {1, 0, 0},
                            {2, 0, 0}};
    TCola C;
    unsigned int costo = 0;
    IniciaC(&C);
    grados(T, &C, &costo, 0, 0, 0);
    printf("Costo total del AAM: %u\n", costo);
    mostrarCola(&C);
    return 0;
}

void grados(unsigned int T[][N], TCola *C, unsigned int *costo, unsigned int i, unsigned int j, unsigned int grado)
{
    TElementoC x;
    if (i < N)
    {
        if (j == N)
        {
            if (grado)
            {
                x.grado = grado;
                x.vertice = i;
                PoneC(C, x);
            }
            grados(T, C, costo, i + 1, 0, 0);
        }
        else
        {
            if (i > j)
                *costo += T[i][j];
            grados(T, C, costo, i, j + 1, grado + (T[i][j] != 0));
        }
    }
}

void mostrarCola(TCola *C)
{
    TElementoC x;
    printf("Vertice\tGrado\n");
    while (!VaciaC(*C))
    {
        SacaC(C, &x);
        printf("%c\t%u\n", x.vertice + 65, x.grado);
    }
}