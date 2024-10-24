#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 20

typedef char TElementoG;
typedef struct Tvertice
{
    TElementoG dato;
    struct Tvertice *sig;
} Tvertice;
typedef Tvertice TGrafo[MAX_VERTICES];

void agregarRelacion(TGrafo G[], unsigned int N, TElementoG vertice, TElementoG e);
void cargarGrafo(TGrafo G[], unsigned int *N);
unsigned int gradoEntrada(TElementoG vertice, TGrafo G[], unsigned int N);
unsigned int gradoSalida(TElementoG vertice, TGrafo G[], unsigned int N);
unsigned int grado(TElementoG vertice, TGrafo G[], unsigned int N);

int main()
{
    TGrafo G[MAX_VERTICES];
    TElementoG vertice;
    unsigned int N;

    cargarGrafo(G, &N);
    do
    {
        printf("Ingrese un vertice: ");
        scanf("%c", &vertice);
    } while (vertice < 65 || vertice > 64 + N);
    printf("Grado de entrada: %u\n", gradoEntrada(vertice, G, N));
    printf("Grado de salida: %u\n", gradoSalida(vertice, G, N));
    printf("Grado del vertice: %u\n", grado(vertice, G, N));

    return 0;
}

void agregarRelacion(TGrafo G[MAX_VERTICES], unsigned int N, TElementoG vertice, TElementoG e)
{
    unsigned int i = 0;
    Tvertice *aux, *ant;

    while (i < N && G[i]->dato != vertice)
        i++;
    if (i < N)
    {
        aux = (Tvertice *)malloc(sizeof(Tvertice));
        aux->dato = e;
        aux->sig = NULL;
        ant = G[i];
        while (ant->sig != NULL)
            ant = ant->sig;
        ant->sig = aux;
    }
}

void cargarGrafo(TGrafo G[MAX_VERTICES], unsigned int *N)
{
    unsigned int i;
    TElementoG VERTICES[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    *N = 7;

    for (i = 0; i < *N; i++)
    {
        G[i]->dato = VERTICES[i];
        G[i]->sig = NULL;
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

unsigned int gradoEntrada(TElementoG vertice, TGrafo G[MAX_VERTICES], unsigned int N)
{
    unsigned int i, contador = 0;
    Tvertice *aux;

    for (i = 0; i < N; i++)
    {
        aux = G[i]->sig;
        while (aux != NULL && aux->dato != vertice)
            aux = aux->sig;
        contador += aux != NULL;
    }

    return contador;
}

unsigned int gradoSalida(TElementoG vertice, TGrafo G[MAX_VERTICES], unsigned int N)
{
    unsigned int i = 0, contador = 0;
    Tvertice *aux;

    while (i < N && G[i]->dato != vertice)
        i++;
    aux = G[i]->sig;
    while (aux != NULL)
    {
        contador++;
        aux = aux->sig;
    }

    return contador;
}

unsigned int grado(TElementoG vertice, TGrafo G[MAX_VERTICES], unsigned int N)
{
    unsigned int i = 0;
    Tvertice *aux;

    while (i < N && G[i]->dato != vertice)
        i++;
    aux = G[i]->sig;
    while (aux != NULL && aux->dato != vertice)
        aux = aux->sig;

    return gradoEntrada(vertice, G, N) + gradoSalida(vertice, G, N) - (aux != NULL);
}