#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;

void cargarLista(int V[], TLista *L, int N);
int sonIguales(TLista L1, TLista L2);

int main()
{
    int V1[] = {-4, -2, 2, 25, 36, 46, 49}, V2[] = {-4, -2, 2, 25, 36, 46, 49};
    TLista L1, L2, L;

    L1 = L2 = L = NULL;
    cargarLista(V1, &L1, 7);
    cargarLista(V2, &L2, 7);
    printf(sonIguales(L1, L2) ? "L1 = L2\n" : "L1 != L2\n");

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