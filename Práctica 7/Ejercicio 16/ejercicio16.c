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
void insertar(arbol *a, TElementoA e);
void cargarArbol(arbol *a);
void imprimirArbol(arbol a, unsigned nivel, unsigned x);

int main()
{
    arbol a = NULL;
    unsigned i;
    cargarArbol(&a);
    for (i = 1; i <= 6; i++)
    {
        imprimirArbol(a, 1, i);
        printf("\n");
    }

    return 0;
}

void addnodo(arbol *a, TElementoA e)
{
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void insertar(arbol *a, TElementoA e)
{
    arbol aux;
    if (*a == NULL)
        addnodo(a, e);
    else
    {
        aux = *a;
        while ((aux->dato < e || aux->izq != NULL) && (aux->dato > e || aux->der != NULL))
        {
            if (e < aux->dato)
                aux = aux->izq;
            else
                aux = aux->der;
        }
        if (e < aux->dato)
            addnodo(&aux->izq, e);
        else
            addnodo(&aux->der, e);
    }
}

void cargarArbol(arbol *a)
{
    FILE *archivo;
    TElementoA e;
    archivo = fopen("numeros.txt", "rt");
    while (fscanf(archivo, "%d", &e) == 1)
        insertar(a, e);
    fclose(archivo);
}

void imprimirArbol(arbol a, unsigned nivel, unsigned x)
{
    if (a != NULL)
    {
        if (nivel == x)
            printf("%d ", a->dato);
        else
        {
            imprimirArbol(a->izq, nivel + 1, x);
            imprimirArbol(a->der, nivel + 1, x);
        }
    }
}