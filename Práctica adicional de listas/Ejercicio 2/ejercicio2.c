#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;

void cargarLista(TLista *L);
void generarLista(TLista *L, TLista *impares, TLista *pares);
void mostrarLista(TLista L);

int main()
{
    TLista L, impares, pares;
    L = impares = pares = NULL;
    cargarLista(&L);
    generarLista(&L, &impares, &pares);
    printf("Numeros impares: ");
    mostrarLista(impares);
    printf("\nNumeros pares: ");
    mostrarLista(pares);
    return 0;
}

void cargarLista(TLista *L)
{
    int V[] = {-4, -2, 2, 25, 36, 46, 49}, i;
    TLista nuevo, ult;
    for (i = 0; i < 7; i++)
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

void generarLista(TLista *L, TLista *impares, TLista *pares)
{
    TLista aux = *L, ult = *pares, siguiente;
    while (aux != NULL)
    {
        *L = aux->sig;
        if (aux->dato % 2 == 1)
        {
            siguiente = aux->sig;
            aux->sig = *impares;
            *impares = aux;
            aux = siguiente;
        }
        else
        {
            if (ult == NULL)
                *pares = aux;
            else
                ult->sig = aux;
            ult = aux;
            aux = aux->sig;
            ult->sig = NULL;
        }
    }
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