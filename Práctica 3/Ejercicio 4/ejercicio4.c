#include <stdio.h>
#include <stdlib.h>
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
    if (archivo == NULL)
        printf("El archivo no se pudo abrir correctamente\n");
    else
    {
        fscanf(archivo, "%u %u", N, M);
        for (i = 0; i < *N; i++)
            for (j = 0; j < *M; j++)
                fscanf(archivo, "%f", &A[i][j]);
        fclose(archivo);
    }    
}

int veces(float X, float A[MAXELEM][MAXELEM], unsigned N, unsigned M, unsigned j){
    if (N == 1 && j==0)
        return A[N-1][j] == X;
    else if (j == 0)
        return (A[N-1][j] == X) + veces(X,A,N-1,M,M-1);
    else
        return (A[N-1][j] == X) + veces(X,A,N,M,j-1);
}

void contar(float X, float A[MAXELEM][MAXELEM], unsigned N, unsigned M, unsigned j, unsigned *contador){
    if (N == 1 && j==0)
        *contador = A[N-1][j] == X;
    else if (j == 0)
    {
        contar(X,A,N-1,M,M-1,contador);
        *contador += A[N-1][j] == X;
    }
    else
    {
        contar(X,A,N,M,j-1,contador);
        *contador += A[N-1][j] == X;
    }
}