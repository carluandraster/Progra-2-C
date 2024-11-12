#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;

void cargarLista(int V[], TLista *L, int N);
void concatenar(TLista *L1, TLista *L2, int *concatenante);
void mostrarLista(TLista L);

int main()
{
    int V2[] = {-4, -2, 2, 25, 36, 46, 49}, V1[] = {2, 3, 5, 6}, concatenante;
    TLista L1, L2;

    L1 = L2 = NULL;
    cargarLista(V1, &L1, 4);
    cargarLista(V2, &L2, 7);
    concatenar(&L1, &L2, &concatenante);
    if (concatenante)
        mostrarLista(L1);
    else
        mostrarLista(L2);

    return 0;
}

// Convierte al vector en una lista
void cargarLista(int V[], TLista *L, int N)
{
    int i;
    TLista ult, nuevo;
    for (i = 0; i < N; i++)
    {
        nuevo = (TLista)malloc(sizeof(nodo));
        nuevo->dato = V[i];
        if (*L == NULL)
            *L = ult = nuevo;
        else
        {
            ult->sig = nuevo;
            ult = nuevo;
        }
    }
    ult->sig = NULL;
}

// Verifica si L1 = L2
int sonIguales(TLista L1, TLista L2)
{
    TLista aux1 = L1, aux2 = L2;
    while (aux1 != NULL && aux2 != NULL && aux1->dato == aux2->dato)
    {
        aux1 = aux1->sig;
        aux2 = aux2->sig;
    }
    return aux1 == NULL && aux2 == NULL;
}

// Une las lista L1 y L2
void concatenar(TLista *L1, TLista *L2, int *concatenante)
{
    TLista ult = *L1, pri = *L2;

    // Buscar ultimo de L1
    while (ult->sig != NULL)
        ult = ult->sig;

    if (pri->dato > ult->dato) // añadir L2 al final de L1, en el caso de que el primer elemento de L2 sea mayor al último de L1.
        *concatenante = 1;
    else
    {
        *concatenante = 0;
        pri = *L1;
        ult = *L2;
        while (ult->sig != NULL)
            ult = ult->sig;
    }
    ult->sig = pri;
}

void mostrarLista(TLista L)
{
    TLista aux = L;
    while (aux != NULL)
    {
        printf("%d ", aux->dato);
        aux = aux->sig;
    }
}