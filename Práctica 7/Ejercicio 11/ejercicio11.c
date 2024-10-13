#include <stdio.h>
#include <stdlib.h>

typedef int TElementoA;
typedef struct nodo
{
    TElementoA dato;
    struct nodo *izq, *der;
} nodo;
typedef nodo *arbol;

void addnodo(arbol *a, TElementoA e);
void cargarArbol(arbol *a);
TElementoA minimo(arbol a);

int main()
{
    arbol a;
    cargarArbol(&a);
    printf("Elemento minimo: %d\n", minimo(a));
    return 0;
}

void addnodo(arbol *a, TElementoA e)
{
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
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

TElementoA minimo(arbol a)
{
    return a->izq == NULL ? a->dato : minimo(a->izq);
}