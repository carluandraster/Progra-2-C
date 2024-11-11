#include <stdio.h>
#include <stdlib.h>

// Lista simple y circular
typedef struct nodo
{
    int dato;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;
typedef nodo *TListaC;

// Lista doble
typedef struct nodoD
{
    int dato;
    struct nodoD *ant, *sig;
} nodoD;
typedef struct
{
    nodoD *pri, *ult;
} TListaD;

void cargarLista(TLista *L);
void copiar(TLista L, TListaC *LC, TListaD *LD);
void mostrarC(TListaC LC);
void mostrarD(TListaD LD);

int main()
{
    TLista L = NULL;
    TListaC LC = NULL;
    TListaD LD;

    cargarLista(&L);
    LD.pri = LD.ult = NULL;
    copiar(L, &LC, &LD);
    printf("Lista circular: ");
    mostrarC(LC);
    printf("\nLista doble: ");
    mostrarD(LD);

    return 0;
}

void cargarLista(TLista *L)
{
    int contenido[5] = {1, 2, 3, 4, 5}, i;
    TLista aux, ant;
    aux = (TLista)malloc(sizeof(nodo));
    aux->dato = contenido[0];
    *L = aux;
    for (i = 1; i < 5; i++)
    {
        ant = aux;
        aux = (TLista)malloc(sizeof(nodo));
        aux->dato = contenido[i];
        ant->sig = aux;
    }
    aux->sig = NULL;
}

void copiar(TLista L, TListaC *LC, TListaD *LD)
{
    TLista aux = L;
    TListaC nuevoC, pri;
    nodoD *nuevoD;

    while (aux != NULL)
    {
        nuevoC = (TListaC)malloc(sizeof(nodo));
        nuevoD = (nodoD *)malloc(sizeof(nodoD));
        nuevoC->dato = nuevoD->dato = aux->dato;
        if (*LC == NULL)
        {
            pri = *LC = nuevoC;
            LD->pri = LD->ult = nuevoD;
        }
        else
        {
            (*LC)->sig = nuevoC;
            *LC = nuevoC;
            LD->ult->sig = nuevoD;
            LD->ult = nuevoD;
        }
        aux = aux->sig;
    }
    LD->ult->sig = NULL;
    (*LC)->sig = pri;
}

void mostrarC(TListaC LC)
{
    TListaC aux = LC;
    do
    {
        aux = aux->sig;
        printf("%d ", aux->dato);
    } while (aux != LC);
}

void mostrarD(TListaD LD)
{
    nodoD *aux;
    aux = LD.pri;
    while (aux != NULL)
    {
        printf("%d ", aux->dato);
        aux = aux->sig;
    }
}