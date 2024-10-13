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
void borrar(arbol *p, arbol aux);
void elimina(arbol *a, TElementoA x);
unsigned profundidad(arbol a);
short esAVL(arbol a);

int main()
{
    arbol a = NULL;
    unsigned i;
    int elim[4] = {7, 24, 8, 10};
    cargarArbol(&a);
    // Eliminar 7, 24, 8, 10
    for (i = 0; i < 4; i++)
    {
        elimina(&a, elim[i]);
        printf(esAVL(a) ? "El arbol es AVL.\n" : "El arbol no es AVL.\n");
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
    {
        insertar(a, e);
        printf(esAVL(*a) ? "El arbol es AVL.\n" : "El arbol no es AVL.\n");
    }
    fclose(archivo);
}

void borrar(arbol *p, arbol aux)
{
    if (((*p)->der != NULL))
        borrar(&(*p)->der, aux);
    else
    {
        aux->dato = (*p)->dato;
        aux = *p;
        *p = (*p)->izq;
        free(aux);
    }
}

void elimina(arbol *a, TElementoA x)
{
    arbol aux;
    if (*a != NULL)
        if (x < (*a)->dato)
            elimina(&(*a)->izq, x);
        else if (x > (*a)->dato)
            elimina(&(*a)->der, x);
        else
        {
            aux = *a;
            if (aux->der == NULL)
            {
                *a = aux->izq;
                free(aux);
            }
            else if (aux->izq == NULL)
            {
                *a = aux->der;
                free(aux);
            }
            else
                borrar(&(aux->izq), aux);
        }
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

short esAVL(arbol a)
{
    unsigned profIzq, profDer;
    int FE;
    if (a != NULL)
    {
        profIzq = profundidad(a->izq);
        profDer = profundidad(a->der);
        FE = profIzq - profDer;
        if (-1 <= FE && FE <= 1)
            return esAVL(a->izq) && esAVL(a->der);
        else
            return 0;
    }
    else
        return 1;
}