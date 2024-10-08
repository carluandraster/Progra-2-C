#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef char TElementoA;
typedef struct nodo
{
    TElementoA dato;
    struct nodo *izq, *der;
} nodo;
typedef nodo *arbol;

void addnodo(arbol *a, TElementoA e);
void cargarArbol(arbol *a);
void arrgrado2(arbol a, char v[N], int *dimv);

int main()
{
    arbol a;
    char v[N];
    int dimv = 0;

    cargarArbol(&a);
    arrgrado2(a, v, &dimv);
    v[dimv] = '\0';
    printf("%s\n", v);

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
    addnodo(a, 'H');
    addnodo(&(*a)->izq, 'o');
    addnodo(&(*a)->izq->izq, 't');
    addnodo(&(*a)->izq->der, 'u');
    addnodo(&(*a)->der, 'l');
    addnodo(&(*a)->der->izq, 'a');
    addnodo(&(*a)->der->izq->der, 's');
    addnodo(&(*a)->der->izq->izq, 'v');
    addnodo(&(*a)->der->der, 'k');
}

void arrgrado2(arbol a, char v[N], int *dimv)
{
    if (a != NULL)
    {
        if (a->izq != NULL && a->der != NULL)
        { /* grado 2 */
            v[*dimv] = a->dato;
            (*dimv)++;
        }
        arrgrado2(a->izq, v, dimv);
        arrgrado2(a->der, v, dimv);
    }
}