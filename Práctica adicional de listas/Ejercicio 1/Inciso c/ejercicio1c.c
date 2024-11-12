#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;

void cargarLista(int V[], TLista *L, int N);
void mostrarLista(TLista L);
void eliminar(TLista *L1, TLista L2);

int main()
{
    int V1[] = {-4, -2, 2, 25, 36, 46, 49}, V2[] = {2, 3, 5, 6};
    TLista L1, L2, L;

    L1 = L2 = L = NULL;
    cargarLista(V1, &L1, 7);
    cargarLista(V2, &L2, 4);
    eliminar(&L1, L2);
    mostrarLista(L1);

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

void mostrarLista(TLista L)
{
    TLista aux = L;
    while (aux != NULL)
    {
        printf("%d ", aux->dato);
        aux = aux->sig;
    }
}

void eliminar(TLista *L1, TLista L2)
{
    TLista aux = L2, act = *L1, ant = NULL, elim;
    int i = 1;
    while (aux != NULL && act != NULL)
    {
        while (act != NULL && i < aux->dato)
        {
            ant = act;
            act = act->sig;
            i++;
        }
        if (act != NULL)
        {
            if (ant == NULL)
                *L1 = act->sig;
            else
            {
                elim = act;
                act = ant->sig = act->sig;
                i++;
            }
            free(elim);
            aux = aux->sig;
        }
    }
}