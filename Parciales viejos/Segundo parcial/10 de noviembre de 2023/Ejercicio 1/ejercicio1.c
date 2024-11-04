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
int tieneMenos(arbol a, int K1, int K2, int nivel);
int contarSi(arbol a, int K1, int K2);

int main()
{
    arbol a;
    int K1, K2;

    cargarArbol(&a);
    do
    {
        printf("Ingrese un nivel K1: ");
        scanf("%d", &K1);
    } while (K1 <= 0);
    do
    {
        printf("Ingrese un nivel K2: ");
        scanf("%d", &K2);
    } while (K2 <= 0);
    printf("Cantidad de arboles que tienen al menos una clave negativa entre K1 y K2: %d", contarSi(a, K1, K2));

    return 0;
}

// Agrega un nodo al arbol
void addnodo(arbol *a, TElementoA e)
{
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->izq = (*a)->der = NULL;
}

// Inicializa al arbol
void cargarArbol(arbol *a)
{
    // Arbol 1
    addnodo(a, 1);
    addnodo(&(*a)->izq, 2);
    addnodo(&(*a)->izq->der, 3);

    // Arbol 2
    addnodo(&(*a)->der, 4);
    addnodo(&(*a)->der->izq, 5);
    addnodo(&(*a)->der->izq->der, 6);

    // Arbol 3
    addnodo(&(*a)->der->der, 7);
    addnodo(&(*a)->der->der->izq, 8);
    addnodo(&(*a)->der->der->izq->der, -9);
}

int tieneMenos(arbol a, int K1, int K2, int nivel)
{
    if (a == NULL || nivel > K2)
        return 0;
    else if (nivel == 1)
        return K1 == 1 && a->dato < 0 || tieneMenos(a->izq, K1, K2, nivel + 1);
    else if (nivel < K1)
        return tieneMenos(a->izq, K1, K2, nivel + 1) || tieneMenos(a->der, K1, K2, nivel);
    else
        return a->dato < 0 || tieneMenos(a->izq, K1, K2, nivel + 1) || tieneMenos(a->der, K1, K2, nivel);
}

int contarSi(arbol a, int K1, int K2)
{
    int contador = 0;
    while (a != NULL)
    {
        contador += tieneMenos(a, K1, K2, 1);
        a = a->der;
    }
    return contador;
}