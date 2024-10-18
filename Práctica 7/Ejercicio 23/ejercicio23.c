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
void gradoDelArbol(arbol a, unsigned int *grado);

int main()
{
    arbol a;
    unsigned int grado = 0;

    cargarArbol(&a);
    gradoDelArbol(a, &grado);
    printf("Grado del arbol: %u\n", grado);

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

void gradoDelArbol(arbol a, unsigned int *grado)
{
    arbol aux;
    unsigned int contador = 0;

    if (a == NULL)
        *grado = 0;
    else
    {
        aux = a->izq;
        while (aux != NULL)
        {
            contador++;
            gradoDelArbol(aux, grado);
            aux = aux->der;
        }
        if (contador > *grado)
            *grado = contador;
    }
}