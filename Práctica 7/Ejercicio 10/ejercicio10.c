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
int busca(arbol a, int x);

int main()
{
    arbol a;
    int x;
    cargarArbol(&a);
    printf("Ingrese un numero: ");
    scanf("%d", &x);
    printf(busca(a, x) ? "El numero que ingreso se encuentra en el ABB.\n" : "El numero que ingreso no se encuentra en el ABB.\n");
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

int busca(arbol a, int x)
{
    if (a == NULL)
        return 0;
    else if (x == a->dato)
        return 1;
    else if (x < a->dato)
        return busca(a->izq, x);
    else
        return busca(a->der, x);
}