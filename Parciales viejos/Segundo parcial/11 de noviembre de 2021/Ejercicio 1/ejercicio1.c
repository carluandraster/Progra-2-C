#include <stdio.h>
#include <stdlib.h>

typedef unsigned int TElementoA;
typedef struct nodo
{
    TElementoA dato;
    struct nodo *izq, *der;
} nodo;
typedef nodo *arbol;

void addnodo(arbol *a, TElementoA e);
void cargarArbol(arbol *a);
void encontrar2(arbol a, arbol *grad2, int *error, int *nivel);
void minClave(arbol a, TElementoA *minimo, int *nivel);
void maxClave(arbol a, TElementoA *maximo, int *nivel);

int main()
{
    arbol a, grad2;
    TElementoA minimo, maximo;
    int nivel = 1, error, nivel2;
    cargarArbol(&a);
    encontrar2(a, &grad2, &error, &nivel);
    nivel2 = nivel;
    if (error)
        printf("No se encontro ningun nodo de grado 2.\n");
    else
    {
        minClave(grad2, &minimo, &nivel);
        printf("La minima clave de grado 2 esta en el nivel %d y es %u\n", nivel, minimo);
        maxClave(grad2, &maximo, &nivel2);
        printf("La maxima clave de grado 2 esta en el nivel %d y es %u\n", nivel2, maximo);
    }

    return 0;
}

// Agrega un nodo al arbol
void addnodo(arbol *a, TElementoA e)
{
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->izq = (*a)->der = NULL;
}

// Inicializa el arbol
void cargarArbol(arbol *a)
{
    addnodo(a, 23);
    addnodo(&(*a)->izq, 16);
    addnodo(&(*a)->izq->izq, 12);
    // addnodo(&(*a)->izq->izq->der, 15);
    addnodo(&(*a)->izq->izq->izq, 3);
    /*addnodo(&(*a)->der, 40);
    addnodo(&(*a)->der->izq, 26);
    addnodo(&(*a)->der->der, 44);*/
}

void encontrar2(arbol a, arbol *grad2, int *error, int *nivel)
{
    if (a == NULL)
        *error = 1;
    else if (a->izq != NULL && a->der != NULL)
    {
        *grad2 = a;
        *error = 0;
    }
    else if (a->izq == NULL)
    {
        ++*nivel;
        encontrar2(a->der, grad2, error, nivel);
    }
    else if (a->der == NULL)
    {
        ++*nivel;
        encontrar2(a->izq, grad2, error, nivel);
    }
    else
        *error = 1;
}

void minClave(arbol a, TElementoA *minimo, int *nivel)
{
    int nivelAux = *nivel;
    while (a != NULL)
    {
        if (a->izq != NULL && a->der != NULL)
        {
            *minimo = a->dato;
            *nivel = nivelAux;
            a = a->izq;
        }
        else if (a->izq == NULL)
            a = a->der;
        else
            a = a->izq;
        nivelAux++;
    }
}

void maxClave(arbol a, TElementoA *maximo, int *nivel)
{
    int nivelAux = *nivel;
    while (a != NULL)
    {
        if (a->izq != NULL && a->der != NULL)
        {
            *maximo = a->dato;
            *nivel = nivelAux;
            a = a->der;
        }
        else if (a->der == NULL)
            a = a->izq;
        else
            a = a->der;
        nivelAux++;
    }
}