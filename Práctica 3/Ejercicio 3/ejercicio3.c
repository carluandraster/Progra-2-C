#include <stdio.h>
#define MAXELEM 100

void cargarVector(int[MAXELEM], unsigned *);
int suma(int[MAXELEM], unsigned);

short main()
{
    int A[MAXELEM];
    unsigned N;
    cargarVector(A, &N);
    printf("Promedio: %5.2f\n", (float)suma(A, N) / N);
    return 0;
}

void cargarVector(int A[MAXELEM], unsigned *N)
{
    FILE *archivo;
    *N = 0;
    archivo = fopen("vector.txt", "rt");
    while (fscanf(archivo, "%d ", &A[*N]) == 1)
        ++*N;
    fclose(archivo);
}

int suma(int A[MAXELEM], unsigned N)
{
    return N == 1 ? A[0] : A[N - 1] + suma(A, N - 1);
}