#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10

typedef unsigned short int byte;
typedef char TElementoG;
typedef struct TVertice
{
    TElementoG dato;
    struct TVertice *sig;
} TVertice;
typedef TVertice TGrafo[MAX_VERTICES];

void agregarRelacion(TGrafo G[],byte N,TElementoG vertice,TElementoG e);
void cargarGrafo(TGrafo G[], byte *N);
byte grado(TGrafo G[],byte N,TElementoG vertice);

int main()
{
    TGrafo G[MAX_VERTICES];
    byte N;
    TElementoG vertice;

    cargarGrafo(G,&N);
    do
    {
        printf("Ingrese un vertice: ");
        scanf(" %c",&vertice);
    } while (vertice < 65 || vertice > 64+N);
    printf("Grado del vertice: %hu",grado(G,N,vertice));

    return 0;
}

void agregarRelacion(TGrafo G[MAX_VERTICES], byte N, TElementoG vertice, TElementoG e)
{
    byte i = 0;
    TVertice *aux, *ant;

    while (i < N && G[i]->dato != vertice)
        i++;
    if (i < N)
    {
        aux = (TVertice *)malloc(sizeof(TVertice));
        aux->dato = e;
        aux->sig = NULL;
        ant = G[i];
        while (ant->sig != NULL)
            ant = ant->sig;
        ant->sig = aux;
    }
}

void cargarGrafo(TGrafo G[MAX_VERTICES], byte *N)
{
    byte i;
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

byte grado(TGrafo G[MAX_VERTICES],byte N,TElementoG vertice){
    byte i = 0, contador = 0;
    TVertice *aux;

    while (i<N)
    {
        aux = G[i]->sig;
        if (G[i]->dato == vertice)
            while (aux != NULL)
            {
                contador++;
                aux = aux->sig;
            }
        else{
            while (aux != NULL && aux->dato != vertice)
                aux = aux->sig;
            contador += aux != NULL;
        }
        i++;
    }
    
    return contador;
}