#include <stdio.h>
#include <stdlib.h>

typedef int TElementoA;
typedef struct nodo
{
    TElementoA dato;
    struct nodo *izq, *der;
} nodo;
typedef nodo *arbol;

void addnodo(arbol *A, TElementoA e);
void cargarArbol(arbol *A);
unsigned int grado(arbol A);
short int cumple(arbol A, unsigned int grado);
short int determina(arbol A);

int main()
{
    arbol A;
    cargarArbol(&A);
    printf(determina(A) ? "Todos los arboles son del mismo grado que su raiz.\n" : "Existen arboles que no son del mismo grado que su raiz.\n");
    return 0;
}

void addnodo(arbol *A, TElementoA e)
{
    *A = (arbol)malloc(sizeof(nodo));
    (*A)->dato = e;
    (*A)->izq = (*A)->der = NULL;
}

void cargarArbol(arbol *A)
{
    addnodo(A, 23);
    addnodo(&(*A)->izq, 4);
    addnodo(&(*A)->izq->izq, 1);
    addnodo(&(*A)->izq->der, 5);
    addnodo(&(*A)->izq->der->der, 6);
    addnodo(&(*A)->izq->der->der->izq, 7);
    addnodo(&(*A)->izq->der->der->izq->der, 2);
    addnodo(&(*A)->der, 33);
    addnodo(&(*A)->der->izq, 40);
    addnodo(&(*A)->der->izq->der, 44);
    addnodo(&(*A)->der->izq->der->izq, 46);
    addnodo(&(*A)->der->izq->der->izq->izq, 50);
    addnodo(&(*A)->der->izq->der->izq->izq->der, 60);
    addnodo(&(*A)->der->der, 72);
    addnodo(&(*A)->der->der->izq, 9);
    addnodo(&(*A)->der->der->izq->der, 19);
    addnodo(&(*A)->der->der->izq->der->der, 29);
    addnodo(&(*A)->der->der->izq->der->der->izq, 26);
    addnodo(&(*A)->der->der->izq->der->der->izq->der, 27);
    addnodo(&(*A)->der->der->izq->der->der->izq->der->der, 28);
    // addnodo(&(*A)->der->der->izq->der->der->izq->der->der->der, 28);
}

unsigned int grado(arbol A)
{
    unsigned int contador = 0;

    A = A->izq;
    while (A != NULL)
    {
        contador++;
        A = A->der;
    }

    return contador;
}

short int cumple(arbol A, unsigned int grad)
{
    if (A == NULL)
        return 1;
    else if (grado(A) <= grad)
        return cumple(A->izq, grad) && cumple(A->der, grad);
    else
        return 0;
}

short int determina(arbol A)
{
    short int cumpleCondicion = 1;
    while (A != NULL && cumpleCondicion)
    {
        cumpleCondicion = cumpleCondicion && cumple(A->izq, grado(A));
        A = A->der;
    }
    return cumpleCondicion;
}