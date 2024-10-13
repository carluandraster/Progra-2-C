#include <stdio.h>
#include <stdlib.h>
#define MAXCAR 20

typedef char TElementoA;
typedef struct nodo
{
    TElementoA dato;
    struct nodo *izq, *der;
} nodo;
typedef nodo *arbol;

void addnodo(arbol *a, TElementoA e);
void cargarArbol(arbol *a);
void generarTexto(arbol a, char texto[MAXCAR], unsigned *N);

int main()
{
    arbol a;
    char texto[MAXCAR];
    unsigned N = 0;

    cargarArbol(&a);
    generarTexto(a, texto, &N);
    texto[N] = '\0';
    printf("%s", texto);

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
    addnodo(a, 'M');
    addnodo(&(*a)->izq, 'C');
    addnodo(&(*a)->izq->izq, 'A');
    addnodo(&(*a)->izq->der, 'E');
    addnodo(&(*a)->der, 'R');
    addnodo(&(*a)->der->izq, 'P');
    addnodo(&(*a)->der->der, 'T');
}

void generarTexto(arbol a, char texto[MAXCAR], unsigned *N)
{
    if (a != NULL)
    {
        generarTexto(a->der, texto, N);
        texto[*N] = a->dato;
        ++*N;
        generarTexto(a->izq, texto, N);
    }
}