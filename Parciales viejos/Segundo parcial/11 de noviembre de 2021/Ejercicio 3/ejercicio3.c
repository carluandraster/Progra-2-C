#include <stdio.h>
#define MAX_VERTICES 10
#define INFINITO 29999

void cargarGrafo(int G[][MAX_VERTICES], int *N);
void minVertice(int G[][MAX_VERTICES], int N, int *vertice, int *error);

int main()
{
    int G[MAX_VERTICES][MAX_VERTICES], N, vertice, error;
    cargarGrafo(G, &N);
    minVertice(G, N, &vertice, &error);
    if (error)
        printf("Ningun vertice tiene bucle y grado par.\n");
    else
        printf("Vertice con bucle de menor grado par: %c", vertice + 65);

    return 0;
}

void cargarGrafo(int G[][MAX_VERTICES], int *N)
{
    int i, j;
    FILE *archivo;
    archivo = fopen("matriz.txt", "rt");
    fscanf(archivo, "%d", N);
    for (i = 0; i < *N; i++)
        for (j = 0; j <= i; j++)
            fscanf(archivo, "%d", &G[i][j]);
    fclose(archivo);
}

void minVertice(int G[][MAX_VERTICES], int N, int *vertice, int *error)
{
    int GRADOS[N], BUCLES[N], i, j, minAux = INFINITO;

    for (i = 0; i < N; i++)
    {
        GRADOS[i] = 0;
        for (j = 0; j < i; j++)
        {
            GRADOS[i] += G[i][j];
            GRADOS[j] += G[i][j];
        }
        BUCLES[i] = G[i][i];
    }
    for (i = 0; i < N; i++)
        if (BUCLES[i] && GRADOS[i] % 2 == 0 && GRADOS[i] < minAux)
        {
            minAux = GRADOS[i];
            *vertice = i;
        }
    *error = minAux == INFINITO;
}