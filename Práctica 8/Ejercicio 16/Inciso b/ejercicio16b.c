#include <stdio.h>
#define MAX_VERTICES 10
#define INFINITO 64999

void cargarDigrafo(unsigned int DG[][MAX_VERTICES], unsigned int *N);
void Floyd(unsigned int DG[][MAX_VERTICES], unsigned int N, unsigned int P[][MAX_VERTICES]);
void imprimirMatriz(unsigned int P[][MAX_VERTICES], unsigned int N);

int main()
{
    unsigned int DG[MAX_VERTICES][MAX_VERTICES], N, P[MAX_VERTICES][MAX_VERTICES];
    cargarDigrafo(DG, &N);
    Floyd(DG, N, P);
    imprimirMatriz(P, N);
    return 0;
}

void cargarDigrafo(unsigned int DG[MAX_VERTICES][MAX_VERTICES], unsigned int *N)
{
    unsigned int i, j;
    FILE *archivo;
    archivo = fopen("../matriz.txt", "rt");
    fscanf(archivo, "%u", N);
    for (i = 0; i < *N; i++)
        for (j = 0; j < *N; j++)
            fscanf(archivo, "%u", &DG[i][j]);
    fclose(archivo);
}

void Floyd(unsigned int DG[][MAX_VERTICES], unsigned int N, unsigned int P[][MAX_VERTICES])
{
    unsigned int i, j, k, A[MAX_VERTICES][MAX_VERTICES];

    // Inicializar matriz A
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (i == j)
                A[i][j] = P[i][j] = 0;
            else if (DG[i][j] != 0) // (i,j) es una arista
            {
                A[i][j] = DG[i][j];
                P[i][j] = 0;
            }
            else
                A[i][j] = P[i][j] = INFINITO;

    // Algoritmo de Floyd
    for (k = 0; k < N; k++)
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                if (A[i][k] + A[k][j] < A[i][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                    P[i][j] = k + 1;
                }
}

void imprimirMatriz(unsigned int P[][MAX_VERTICES], unsigned int N)
{
    unsigned int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%u ", P[i][j]);
        printf("\n");
    }
}