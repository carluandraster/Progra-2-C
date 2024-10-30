#include <stdio.h>
#define MAX_VERTICES 10
#define INFINITO 64999

void cargarDigrafo(unsigned int[][], unsigned int *);
void Dijkstra(unsigned int[][], unsigned int, unsigned int, unsigned int D[], unsigned int P[]);

int main()
{
    unsigned int DG[MAX_VERTICES][MAX_VERTICES], N, D[MAX_VERTICES], P[MAX_VERTICES], i, j;
    cargarDigrafo(DG, &N);
    for (i = 0; i < N; i++)
    {
        Dijkstra(DG, N, i, D, P);
        for (j = 0; j < N; j++)
            printf("%u ", P[j]);
        printf("\n");
    }
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