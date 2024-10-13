#include <stdio.h>
#include <stdlib.h>
#define INFINITO 32000

typedef int TElementoA;
typedef struct nodo
{
    TElementoA dato;
    struct nodo *izq, *der;
} nodo;
typedef nodo *arbol;

void addnodo(arbol *a, TElementoA e);
void cargarArbol(arbol *a);
int esABB(arbol a, int min, int max);

int main()
{
    arbol a;
    cargarArbol(&a);
    printf(esABB(a, -INFINITO, INFINITO) ? "El arbol es binario de busqueda.\n" : "El arbol no es binario de busqueda.\n");
    return 0;
}

void addnodo(arbol *a, TElementoA e)
{
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->izq = (*a)->der = NULL;
}

void cargarArbol(arbol *a)
{
    addnodo(a, 8);
    addnodo(&(*a)->izq, 3);
    addnodo(&(*a)->izq->izq, 1);
    addnodo(&(*a)->izq->der, 5);
    addnodo(&(*a)->der, 14);
    addnodo(&(*a)->der->izq, 10);
    addnodo(&(*a)->der->izq->der, 12);
    addnodo(&(*a)->der->der, 22);
}

int esABB(arbol a, int min, int max)
{
    if (a != NULL)
    {
        if (a->dato <= min || a->dato >= max)
            return 0;
        else
            return esABB(a->izq, min, a->dato) && esABB(a->der, a->dato, max);
    }
    else
        return 1;
}