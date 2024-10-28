#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 20

typedef char TElementoG;
typedef struct TVertice
{
    TElementoG id;
    struct TVertice *sig;
} TVertice;

void agregarRelacion(TVertice G[MAX_VERTICES], unsigned int N, TElementoG vertice, TElementoG e);
void cargarGrafo(TVertice G[MAX_VERTICES], unsigned int *N);
TElementoG maxGradoEntrada(TVertice G[MAX_VERTICES], unsigned int N);

int main()
{
    TVertice G[MAX_VERTICES];
    unsigned int N;

    cargarGrafo(G, &N);
    printf("Vertice con el mayor grado de entrada: %c\n", maxGradoEntrada(G, N));
    return 0;
}

void agregarRelacion(TVertice G[MAX_VERTICES], unsigned int N, TElementoG vertice, TElementoG e)
{
    unsigned i = 0;
    TVertice *aux, *ant;

    while (i < N && G[i].id != vertice)
        i++;
    if (i < N)
    {
        aux = (TVertice *)malloc(sizeof(TVertice));
        aux->id = e;
        aux->sig = NULL;
        ant = &G[i];
        while (ant->sig != NULL)
            ant = ant->sig;
        ant->sig = aux;
    }
}

void cargarGrafo(TVertice G[MAX_VERTICES], unsigned int *N)
{
    unsigned i;
    TElementoG VERTICES[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    *N = 7;

    for (i = 0; i < *N; i++)
    {
        G[i].id = VERTICES[i];
        G[i].sig = NULL;
    }

    agregarRelacion(G, *N, 'A', 'D');
    agregarRelacion(G, *N, 'A', 'F');
    agregarRelacion(G, *N, 'B', 'C');
    agregarRelacion(G, *N, 'C', 'A');
    agregarRelacion(G, *N, 'C', 'F');
    agregarRelacion(G, *N, 'D', 'B');
    agregarRelacion(G, *N, 'D', 'F');
    agregarRelacion(G, *N, 'E', 'D');
    agregarRelacion(G, *N, 'F', 'D');
    agregarRelacion(G, *N, 'F', 'G');
    agregarRelacion(G, *N, 'G', 'D');
    agregarRelacion(G, *N, 'G', 'E');
}

TElementoG maxGradoEntrada(TVertice G[MAX_VERTICES], unsigned int N)
{
    unsigned int CONTADORES[N], i, max = 0;
    TVertice *aux;
    TElementoG maxAux;

    for (i = 0; i < N; i++)
        CONTADORES[i] = 0;
    for (i = 0; i < N; i++)
    {
        aux = G[i].sig;
        while (aux != NULL)
        {
            CONTADORES[aux->id - 65]++;
            aux = aux->sig;
        }
    }
    for (i = 0; i < N; i++)
        if (CONTADORES[i] > max)
        {
            max = CONTADORES[i];
            maxAux = i + 65;
        }

    return maxAux;
}