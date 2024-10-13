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
unsigned contar(arbol a, int A, int B);

int main()
{
    arbol a;
    int A, B;

    cargarArbol(&a);
    printf("Ingrese A: ");
    scanf("%d", &A);
    printf("Ingrese B: ");
    scanf("%d", &B);
    printf("Cantidad de elementos mayores a %d y menores a %d: %u", A, B, contar(a, A, B));

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

unsigned contar(arbol a, int A, int B)
{
    if (a == NULL)
        return 0;
    else if (a->dato >= B)
        return contar(a->izq, A, B);
    else if (a->dato <= A)
        return contar(a->der, A, B);
    else
        return 1 + contar(a->izq, A, B) + contar(a->der, A, B);
}