#include <stdio.h>
#include <stdlib.h>
#include "TDA pila/pila.h"

typedef struct nodo
{
    int nro;
    struct nodo *sig;
} nodo;
typedef nodo *TListaC;

void cargarLista(TListaC *LC, int numeros[], int N);
void eliminarDesordenados(TListaC *LC, TPila *P);
void mostrarLista(TListaC LC);
void mostrarPila(TPila P);

int main()
{
    TListaC LC = NULL;
    TPila P;
    IniciaP(&P);
    int numeros[] = {2,7,10,14,14,2,0,19};

    cargarLista(&LC, numeros,8);
    eliminarDesordenados(&LC,&P);
    printf("Elementos que quedaron en la lista: ");
    mostrarLista(LC);
    printf("Elementos almacenados en la pila: \n");
    mostrarPila(P);

    return 0;
}

// Carga lista circular a partir de un vector
void cargarLista(TListaC *LC,int numeros[], int N){
    int i;
    TListaC pri,nuevo;

    nuevo = (TListaC)malloc(sizeof(nodo));
    nuevo->nro = numeros[0];
    *LC = pri = nuevo;
    for (i = 1; i < N; i++)
    {
        nuevo = (TListaC)malloc(sizeof(nodo));
        nuevo->nro = numeros[i];
        (*LC)->sig = nuevo;
        *LC = nuevo;
    }
    (*LC)->sig = pri;
}

// Elimina nodos de la lista para que quede ordenada de forma estrictamente ascendente
void eliminarDesordenados(TListaC *LC, TPila *P){
    TListaC aux = (*LC)->sig, ant;
    unsigned int pos = 1;
    TElementoP x;
    ant = aux;
    while (aux != *LC)
    {
        aux = aux->sig;
        pos++;
        if (aux->nro <= ant->nro)
        {
            ant->sig = aux->sig;
            if (*LC == aux)
                *LC = ant;
            x.numero = aux->nro;
            x.pos = pos;
            PoneP(P,x);
            free(aux);
            aux = ant;
        }
        ant = aux;
    }
}

// Muestra el contenido de la lista
void mostrarLista(TListaC LC){
    TListaC aux = LC;
    do
    {
        aux = aux->sig;
        printf("%d ",aux->nro);
    } while (aux != LC);
    printf("\n");
}

// Muestra contenido de la pila
void mostrarPila(TPila P){
    TElementoP x;
    printf("Posicion\tNumero\n");
    while (!VaciaP(P))
    {
        SacaP(&P,&x);
        printf("%u\t%d\n",x.pos,x.numero);
    }
}