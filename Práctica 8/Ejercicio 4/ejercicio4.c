#include <stdio.h>
#define MAXELEM 20

void cargarMatriz(unsigned short int A[MAXELEM][MAXELEM], unsigned short int *N);
void grafoSubyacente(unsigned short int A[MAXELEM][MAXELEM], unsigned short int N);
void imprimirMatriz(unsigned short int A[MAXELEM][MAXELEM], unsigned short int N);

int main()
{
    unsigned short int A[MAXELEM][MAXELEM], N;
    cargarMatriz(A, &N);
    grafoSubyacente(A, N);
    imprimirMatriz(A, N);
    return 0;
}

void cargarMatriz(unsigned short int A[MAXELEM][MAXELEM], unsigned short int *N)
{
    unsigned short int i, j;
    FILE *archivo;

    archivo = fopen("matriz.txt", "rt");
    fscanf(archivo, "%hu", N);
    for (i = 0; i < *N; i++)
        for (j = 0; j < *N; j++)
            fscanf(archivo, "%hu", &A[i][j]);
    fclose(archivo);
}

void grafoSubyacente(unsigned short int A[MAXELEM][MAXELEM], unsigned short int N)
{
    unsigned short int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            A[i][j] = A[j][i] || A[i][j];
}

void imprimirMatriz(unsigned short int A[MAXELEM][MAXELEM], unsigned short int N)
{
    unsigned short int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%hu\t", A[i][j]);
        printf("\n");
    }
}