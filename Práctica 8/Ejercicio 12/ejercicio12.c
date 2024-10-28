#include <stdio.h>
#include <stdlib.h>
#include "Pila/pilaDinamica.h"
#include "Cola/colaDinamica.h"
#define MAX_VERTICES 10

typedef char TElementoG;
typedef struct TVertice
{
    TElementoG id;
    struct TVertice *sig;
} TVertice;

void agregarRelacion(TVertice G[], unsigned int N, TElementoG vertice, TElementoG e);
void cargarGrafo(TVertice G[], unsigned int *N);
short int todosVisitados(unsigned short VV[], unsigned N);
void profundidad(TVertice G[], unsigned int N);
void amplitud(TVertice G[], unsigned int N, unsigned int *conexas);

int main()
{
    TVertice G[MAX_VERTICES];
    unsigned int N, conexas;

    cargarGrafo(G, &N);
    profundidad(G, N);
    amplitud(G, N, &conexas);
    printf("Cantidad de componentes conexas: %u\n", conexas);

    return 0;
}

void agregarRelacion(TVertice G[], unsigned int N, TElementoG vertice, TElementoG e)
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

void cargarGrafo(TVertice G[], unsigned int *N)
{
    unsigned i;
    TElementoG VERTICES[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    *N = 8;

    for (i = 0; i < *N; i++)
    {
        G[i].id = VERTICES[i];
        G[i].sig = NULL;
    }

    // Componente conexa 1
    agregarRelacion(G, *N, 'A', 'B');
    agregarRelacion(G, *N, 'B', 'A');
    agregarRelacion(G, *N, 'A', 'G');
    agregarRelacion(G, *N, 'G', 'A');

    // Componente conexa 2
    agregarRelacion(G, *N, 'C', 'D');
    agregarRelacion(G, *N, 'D', 'C');
    agregarRelacion(G, *N, 'C', 'F');
    agregarRelacion(G, *N, 'F', 'C');

    // Componente conexa 3
    agregarRelacion(G, *N, 'E', 'H');
    agregarRelacion(G, *N, 'H', 'E');
}

short int todosVisitados(unsigned short VV[], unsigned N)
{
    unsigned i = 0;
    while (i < N && VV[i])
        i++;
    return i == N;
}

void profundidad(TVertice G[], unsigned int N)
{
    unsigned short int VV[N], i;
    TElementoG vertice;
    TPila P;
    TVertice *aux;

    for (i = 0; i < N; i++)
        VV[i] = 0;
    IniciaP(&P);

    printf("Recorrido por profundidad: ");
    while (!todosVisitados(VV, N))
    {
        i = 0;
        while (VV[i])
            i++;
        vertice = i + 65;
        poneP(&P, vertice);
        printf("%c ", vertice);
        VV[i] = 1;
        while (!todosVisitados(VV, N) && !VaciaP(P))
        {
            vertice = consultaP(P);
            i = 0;
            while (G[i].id != vertice)
                i++;
            aux = G[i].sig;
            while (aux != NULL && VV[aux->id - 65])
                aux = aux->sig;
            if (aux == NULL)
                sacaP(&P, &vertice);
            else
            {
                poneP(&P, aux->id);
                printf("%c ", aux->id);
                VV[aux->id - 65] = 1;
            }
        }
    }
    printf("\n");
}

void amplitud(TVertice G[], unsigned int N, unsigned int *conexas)
{
    unsigned short int VV[N], i;
    TCola C;
    TVertice *aux;
    TElementoG vertice;

    *conexas = 0;
    for (i = 0; i < N; i++)
        VV[i] = 0;
    IniciaC(&C);

    printf("Recorrido por amplitud: ");
    while (!todosVisitados(VV, N))
    {
        ++*conexas;
        i = 0;
        while (VV[i])
            i++;
        vertice = i + 65;
        poneC(&C, vertice);
        printf("%c ", vertice);
        VV[i] = 1;
        while (!todosVisitados(VV, N) && !VaciaC(C))
        {
            sacaC(&C, &vertice);
            i = 0;
            while (G[i].id != vertice)
                i++;
            aux = G[i].sig;
            while (aux != NULL)
            {
                if (!VV[aux->id - 65])
                {
                    poneC(&C, aux->id);
                    printf("%c ", aux->id);
                    VV[aux->id - 65] = 1;
                }
                aux = aux->sig;
            }
        }
    }
    printf("\n");
}