#include <stdio.h>
#include <stdlib.h>
#define MAXELEM 10

typedef struct nodo
{
    int dato;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;

void cargarInvertido(TLista *L, int elementos[MAXELEM]);
void cargarDerecho(TLista *L, int elementos[MAXELEM]);
void cargarOrdenada(TLista *L, int elementos[MAXELEM]);
void imprimirLista(TLista L);
void eliminarLista(TLista *L);

int main()
{
    TLista L = NULL;
    int elementos[MAXELEM] = {12, -45, 67, 89, 0, 23, -56, 78, 90, -34};

    cargarInvertido(&L, elementos);
    imprimirLista(L);
    eliminarLista(&L);
    cargarDerecho(&L, elementos);
    imprimirLista(L);
    eliminarLista(&L);
    cargarOrdenada(&L, elementos);
    imprimirLista(L);
    eliminarLista(&L);
    return 0;
}

void cargarInvertido(TLista *L, int elementos[MAXELEM])
{
    TLista act, ant = NULL;
    unsigned i;
    for (i = 0; i < MAXELEM; i++)
    {
        act = (TLista)malloc(sizeof(nodo));
        act->dato = elementos[i];
        act->sig = ant;
        ant = act;
    }
    *L = act;
}

void cargarDerecho(TLista *L, int elementos[MAXELEM])
{
    TLista act, ant;
    unsigned i;

    for (i = 0; i < MAXELEM; i++)
    {
        if (*L == NULL)
            *L = act;
        act = (TLista)malloc(sizeof(nodo));
        act->dato = elementos[i];
        ant->sig = act;
        ant = act;
    }
}

void cargarOrdenada(TLista *L, int elementos[MAXELEM])
{
    TLista ant, act, siguiente;
    unsigned i, j;
    for (i = 0; i < MAXELEM; i++)
    {
        j = 0;
        ant = NULL;
        siguiente = *L;
        while (j < i && siguiente->dato < elementos[i])
        {
            ant = siguiente;
            siguiente = siguiente->sig;
            j++;
        }
        act = (TLista)malloc(sizeof(nodo));
        act->dato = elementos[i];
        act->sig = siguiente;
        if (ant == NULL)
            *L = act;
        else
            ant->sig = act;
    }
}

void imprimirLista(TLista L)
{
    TLista aux = L;
    while (aux != NULL)
    {
        printf("%d ", aux->dato);
        aux = aux->sig;
    }
    printf("\n");
}

void eliminarLista(TLista *L)
{
    TLista aux = *L, ant;
    *L = NULL;
    while (aux != NULL)
    {
        ant = aux;
        aux = aux->sig;
        free(ant);
    }
}