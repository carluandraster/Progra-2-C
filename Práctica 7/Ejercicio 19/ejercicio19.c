#include <stdio.h>
#include <stdlib.h>

typedef char TElementoA;
typedef struct nodo
{
    TElementoA dato;
    struct nodo *izq, *der;
} nodo;
typedef nodo *arbol;

void addnodo(arbol *a, TElementoA e);
void cargarArbol(arbol *a);
unsigned int cantidadArboles(arbol a);

int main()
{
    arbol a;

    cargarArbol(&a);
    printf("Cantidad de arboles que componia el bosque: %u\n", cantidadArboles(a));

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
    addnodo(a, 'A');
    addnodo(&(*a)->der, 'B');
    addnodo(&(*a)->der->izq, 'C');
    addnodo(&(*a)->der->izq->der, 'D');
    addnodo(&(*a)->der->izq->der->izq, 'E');
    addnodo(&(*a)->der->izq->der->izq->der, 'F');
    addnodo(&(*a)->der->izq->der->izq->der->der, 'G');
    addnodo(&(*a)->der->izq->der->izq->der->der->der, 'H');
    addnodo(&(*a)->der->izq->der->izq->der->izq, 'I');
    addnodo(&(*a)->der->izq->der->izq->der->izq->der, 'J');
    addnodo(&(*a)->der->izq->der->izq->der->izq->der->der, 'K');
    addnodo(&(*a)->der->der, 'L');
    addnodo(&(*a)->der->der->izq, 'M');
    addnodo(&(*a)->der->der->izq->der, 'N');
    addnodo(&(*a)->der->der->izq->der->izq, 'O');
}

unsigned int cantidadArboles(arbol a)
{
    unsigned int contador = 0;
    while (a != NULL)
    {
        contador++;
        a = a->der;
    }
    return contador;
}