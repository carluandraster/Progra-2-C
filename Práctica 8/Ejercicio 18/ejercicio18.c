#include <stdio.h>
#define MAX_VERTICES 10
#define INFINITO 64999

void cargarDigrafo(unsigned int DG[][MAX_VERTICES], unsigned int *N);
void Floyd(unsigned int DG[][MAX_VERTICES], unsigned int N, unsigned int A[][MAX_VERTICES]);
void generarR(unsigned int A[][MAX_VERTICES], unsigned int N, unsigned short int R[][MAX_VERTICES]);
void imprimirMatriz(unsigned short int R[][MAX_VERTICES], unsigned int N);

int main()
{
    unsigned int DG[MAX_VERTICES][MAX_VERTICES], A[MAX_VERTICES][MAX_VERTICES], N;
    unsigned int short R[MAX_VERTICES][MAX_VERTICES];
    cargarDigrafo(DG, &N);
    Floyd(DG, N, A);
    generarR(A, N, R);
    imprimirMatriz(R, N);
    return 0;
}

void cargarDigrafo(unsigned int DG[][MAX_VERTICES], unsigned int *N)
{
    unsigned int i, j;
    FILE *archivo;
    archivo = fopen("matriz.txt", "rt");
    fscanf(archivo, "%u", N);
    for (i = 0; i < *N; i++)
        for (j = 0; j < *N; j++)
            fscanf(archivo, "%u", &DG[i][j]);
    fclose(archivo);
}

void Floyd(unsigned int DG[][MAX_VERTICES], unsigned int N, unsigned int A[][MAX_VERTICES])
{
    unsigned int i, j, k;

    // Inicializar A
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (i == j)
                A[i][j] = 0;
            else if (DG[i][j] > 0)
                A[i][j] = DG[i][j];
            else
                A[i][j] = INFINITO;

    // Algoritmo de Floyd
    for (k = 0; k < N; k++)
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                if (A[i][k] + A[k][j] < A[i][j])
                    A[i][j] = A[i][k] + A[k][j];
}

void generarR(unsigned int A[][MAX_VERTICES], unsigned int N, unsigned short int R[][MAX_VERTICES])
{
    unsigned int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            R[i][j] = A[i][j] != INFINITO;
}

void imprimirMatriz(unsigned short int R[][MAX_VERTICES], unsigned int N)
{
    unsigned int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%hu ", R[i][j]);
        printf("\n");
    }
}