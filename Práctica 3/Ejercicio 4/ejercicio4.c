#include <stdio.h>
#define MAXELEM 20

void ingresarMatriz(float[MAXELEM][MAXELEM], unsigned *, unsigned *);
int veces(float, float[MAXELEM][MAXELEM], unsigned, unsigned, unsigned);
void contar(float, float[MAXELEM][MAXELEM], unsigned, unsigned, unsigned, unsigned *);

short main()
{
    float A[MAXELEM][MAXELEM], X;
    unsigned N, M, contador;

    ingresarMatriz(A, &N, &M);
    printf("Ingrese un numero: ");
    scanf("%f", &X);
    contar(X, A, N, M, M - 1, &contador);
    printf("Version void: %u\n", contador);
    printf("Version int: %d\n", veces(X, A, N, M, M - 1));

    return 0;
}

void ingresarMatriz(float A[MAXELEM][MAXELEM], unsigned *N, unsigned *M)
{
    FILE *archivo;
    unsigned i, j;
    archivo = fopen("matriz.txt", "rt");
    fscanf(archivo, "%u %u", N, M);
    for (i = 0; i < *N; i++)
        for (j = 0; j < *M; j++)
            fscanf(archivo, "%f", &A[i][j]);
    fclose(archivo);
}