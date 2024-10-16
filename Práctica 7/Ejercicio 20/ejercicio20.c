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
unsigned int cantNodosNivImpares(arbol a);

int main()
{
    arbol a;
    cargarArbol(&a);
    printf("Cantidad de nodos que habia en niveles impares: %u\n", cantNodosNivImpares(a));
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
    addnodo(a, 17);
    addnodo(&(*a)->izq, 3);
    addnodo(&(*a)->izq->izq, 1);
    addnodo(&(*a)->izq->izq->der, 2);
    addnodo(&(*a)->izq->izq->der->izq, 8);
    addnodo(&(*a)->izq->izq->der->izq->der, 24);
    addnodo(&(*a)->izq->der, 10);
    addnodo(&(*a)->izq->der->der, 23);
    addnodo(&(*a)->izq->der->der->izq, 5);
    addnodo(&(*a)->izq->der->der->izq->der, 22);
    addnodo(&(*a)->izq->der->der->der, 15);
    addnodo(&(*a)->izq->der->der->der->izq, 7);
    addnodo(&(*a)->izq->der->der->der->izq->der, 34);
    addnodo(&(*a)->izq->der->der->der->izq->der->izq, 21);
    addnodo(&(*a)->izq->der->der->der->izq->der->der, 40);
}