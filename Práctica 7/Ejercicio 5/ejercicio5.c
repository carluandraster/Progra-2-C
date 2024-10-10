#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *TElementoA;
typedef struct nodo
{
    TElementoA dato;
    struct nodo *izq, *der;
} nodo;
typedef nodo *arbol;

void addnodo(arbol *a, TElementoA cadena);
void cargarArbol(arbol *a);
unsigned profundidad(arbol a);
unsigned short maxLong(arbol a);
unsigned contHijosDer(arbol a);

int main()
{
    arbol a;

    cargarArbol(&a);
    printf("Profundidad: %u\n", profundidad(a));
    printf("Logitud de la cadena mas larga: %hu\n", maxLong(a));
    printf("Cantidad de hijos derechos: %u\n", contHijosDer(a));

    return 0;
}

void addnodo(arbol *a, TElementoA cadena)
{
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = cadena;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void cargarArbol(arbol *a)
{
    addnodo(a, "Casa");
    addnodo(&(*a)->izq, "La");
    addnodo(&(*a)->der, "linda");
    addnodo(&(*a)->izq->izq, "gato");
    addnodo(&(*a)->izq->der, "Manzana");
    addnodo(&(*a)->der->izq, "Mate");
}

unsigned profundidad(arbol a)
{
    unsigned profIzq, profDer;
    if (a == NULL)
        return 0;
    else
    {
        profIzq = profundidad(a->izq);
        profDer = profundidad(a->der);
        return profIzq > profDer ? 1 + profIzq : 1 + profDer;
    }
}

unsigned short maxLong(arbol a)
{
    unsigned maxIzq, maxDer, longitud;
    if (a != NULL)
    {
        maxIzq = maxLong(a->izq);
        maxDer = maxLong(a->der);
        longitud = strlen(a->dato);
        if (longitud >= maxIzq && longitud >= maxDer)
            return longitud;
        else if (maxIzq >= longitud && maxIzq >= maxDer)
            return maxIzq;
        else
            return maxDer;
    }
    else
        return 0;
}

unsigned contHijosDer(arbol a)
{
    if (a != NULL)
        return (a->der != NULL) + contHijosDer(a->izq) + contHijosDer(a->der);
    else
        return 0;
}