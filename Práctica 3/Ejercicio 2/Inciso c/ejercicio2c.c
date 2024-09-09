#include <stdio.h>
#define MAXELEM 20

void cargarMatriz(int[MAXELEM][MAXELEM], unsigned *);
int minimo(int[MAXELEM][MAXELEM], unsigned, unsigned, unsigned);

short main()
{
    int MATRIZ[MAXELEM][MAXELEM], N;
    cargarMatriz(MATRIZ, &N);
    printf("El minimo de la matriz es %d", minimo(MATRIZ, N, N - 1, N - 1));
    return 0;
}

void cargarMatriz(int MATRIZ[MAXELEM][MAXELEM], unsigned *N)
{
    FILE *archivo;
    unsigned i, j;
    archivo = fopen("matriz.txt", "rt");
    fscanf(archivo, "%u", N);
    for (i = 0; i < *N; i++)
        for (j = 0; j < *N; j++)
            fscanf(archivo, "%d", &MATRIZ[i][j]);
    fclose(archivo);
}

int minimo(int MATRIZ[MAXELEM][MAXELEM], unsigned N, unsigned i, unsigned j)
{
    int minAux;
    if (i == 0 && j == 0)
        return MATRIZ[0][0];
    else
    {
        minAux = j == 0 ? minimo(MATRIZ, N, i - 1, N - 1) : minimo(MATRIZ, N, i, j - 1);
        return MATRIZ[i][j] < minAux ? MATRIZ[i][j] : minAux;
    }
}