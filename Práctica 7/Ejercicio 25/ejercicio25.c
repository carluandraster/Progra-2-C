#include <stdio.h>
#include <stdlib.h>
#define MAXELEM 20

typedef unsigned int TElementoA;
typedef struct nodo
{
    TElementoA dato;
    struct nodo *izq, *der;
} nodo;
typedef nodo *arbol;

void addnodo(arbol *a, TElementoA e);
void cargarArbol(arbol *a);
TElementoA claveMayor(arbol a);
void clavesMayores(arbol a, TElementoA CLAVES_MAYORES[MAXELEM], unsigned int *N);

int main()
{
    arbol a;
    unsigned int i = 0, N;
    TElementoA CLAVES_MAYORES[MAXELEM];

    cargarArbol(&a);
    clavesMayores(a, CLAVES_MAYORES, &N);
    printf("Claves mayores de los arboles:\t");
    for (i = 0; i < N; i++)
        printf("%u\t", CLAVES_MAYORES[i]);

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
    addnodo(a, 23);
    addnodo(&(*a)->izq, 4);
    addnodo(&(*a)->izq->izq, 1);
    addnodo(&(*a)->izq->der, 5);
    addnodo(&(*a)->izq->der->der, 6);
    addnodo(&(*a)->izq->der->der->izq, 7);
    addnodo(&(*a)->izq->der->der->izq->der, 2);
    addnodo(&(*a)->der, 33);
    addnodo(&(*a)->der->izq, 40);
    addnodo(&(*a)->der->izq->der, 44);
    addnodo(&(*a)->der->izq->der->izq, 46);
    addnodo(&(*a)->der->izq->der->izq->izq, 50);
    addnodo(&(*a)->der->izq->der->izq->izq->der, 60);
    addnodo(&(*a)->der->der, 72);
    addnodo(&(*a)->der->der->izq, 9);
    addnodo(&(*a)->der->der->izq->der, 19);
    addnodo(&(*a)->der->der->izq->der->der, 29);
    addnodo(&(*a)->der->der->izq->der->der->izq, 26);
    addnodo(&(*a)->der->der->izq->der->der->izq->der, 27);
    addnodo(&(*a)->der->der->izq->der->der->izq->der->der, 28);
}

TElementoA claveMayor(arbol a)
{
    TElementoA maxIzq, maxDer;
    if (a == NULL)
        return 0;
    else
    {
        maxIzq = claveMayor(a->izq);
        maxDer = claveMayor(a->der);
        if (a->dato > maxIzq && a->dato > maxDer) // El mayor es la raíz
            return a->dato;
        else if (maxIzq > a->dato && maxIzq > maxDer) // El mayor es el máximo del subarbol izquierdo
            return maxIzq;
        else // El mayor es el máximo del subarbol derecho
            return maxDer;
    }
}

void clavesMayores(arbol a, TElementoA CLAVES_MAYORES[MAXELEM], unsigned int *N)
{
    TElementoA maxClave;
    *N = 0;
    while (a != NULL)
    {
        maxClave = claveMayor(a->izq);
        CLAVES_MAYORES[*N] = maxClave > a->dato ? maxClave : a->dato;
        a = a->der;
        ++*N;
    }
}