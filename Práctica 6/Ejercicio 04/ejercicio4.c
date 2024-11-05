#include <stdio.h>
#include <stdlib.h>
#define N 4

typedef struct NODO
{
    int n;
    struct NODO *sig;
} NODO;
typedef NODO *TLISTA;

void addnodo(TLISTA *lista, int e);
void cargarLista(TLISTA *lista);
void muestra(TLISTA lista);

void main()
{
    int i, arr[N] = {4, 8, 9, 60};
    TLISTA lista = NULL, act, ant, nuevo;

    cargarLista(&lista);
    printf("Lista Original\n");
    muestra(lista);
    act = lista;
    ant = NULL;
    for (i = 0; i < N; i++)
    {
        while (act != NULL && arr[i] > act->n)
        {
            ant = act;
            act = act->sig;
        }
        nuevo = (TLISTA)malloc(sizeof(NODO));
        nuevo->n = arr[i];
        if (ant == NULL)
        {
            nuevo->sig = lista;
            lista = nuevo;
        }
        else
        {
            nuevo->sig = ant->sig;
            ant->sig = nuevo;
        }
        act = nuevo;
    }
    printf("\nLista Resultado\n");
    muestra(lista);
}

// Agrega un nodo al final de la lista
void addnodo(TLISTA *lista, int e)
{
    TLISTA aux, ant, nuevo = NULL;
    nuevo = (TLISTA)malloc(sizeof(NODO));
    nuevo->n = e;
    nuevo->sig = NULL;
    if (*lista == NULL)
        *lista = nuevo;
    else
    {
        aux = *lista;
        while (aux != NULL)
        {
            ant = aux;
            aux = aux->sig;
        }
        ant->sig = nuevo;
    }
}

void cargarLista(TLISTA *lista)
{
    int elementos[] = {-56, -45, -34, 0, 12, 23, 67, 78, 89, 90}, M = 10, i;
    for (i = 0; i < M; i++)
        addnodo(lista, elementos[i]);
}

void muestra(TLISTA lista)
{
    TLISTA aux = lista;
    while (aux != NULL)
    {
        printf("%d ", aux->n);
        aux = aux->sig;
    }
}