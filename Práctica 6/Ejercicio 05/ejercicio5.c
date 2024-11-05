#include <stdio.h>
#include "TDA Cola/cola.h"
#include "TDA Pila/pila.h"

typedef TCola TElementoL;
typedef struct nodo
{
    TElementoL dato;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;

void crearCola(TCola *C, int V[], int N);
void addnodo(TLista *L, TElementoL e);
void cargarLista(TLista *L);
TElementoC maximo(TCola C);
void generarPila(TLista L, TPila *P);
void mostrarPila(TPila P);

int main()
{
    TLista L = NULL;
    TPila P;
    cargarLista(&L);
    printf("Hola");
    IniciaP(&P);
    generarPila(L, &P);
    printf("Maximos de cada cola: ");
    mostrarPila(P);
    return 0;
}

void crearCola(TCola *C, int V[], int N)
{
    int i;
    IniciaC(C);
    for (i = 0; i < N; i++)
        poneC(C, V[i]);
}

void addnodo(TLista *L, TElementoL e)
{
    TLista aux, ant = NULL, nuevo;
    TElementoC x;
    nuevo = (TLista)malloc(sizeof(nodo));
    while (!VaciaC(e))
    {
        sacaC(&e, &x);
        poneC(&nuevo->dato, x);
    }
    nuevo->sig = NULL;
    if (*L == NULL)
        *L = nuevo;
    else
    {
        aux = *L;
        while (aux != NULL)
        {
            ant = aux;
            aux = aux->sig;
        }
        ant->sig = nuevo;
    }
}

void cargarLista(TLista *L)
{
    TCola C;
    int V[MAX], i, N;
    FILE *archivo;
    archivo = fopen("numeros.txt", "rt");
    while (fscanf(archivo, "%d", &N))
    {
        for (i = 0; i < N; i++)
            fscanf(archivo, "%d", &V[i]);
        crearCola(&C, V, N);
        addnodo(L, C);
    }
    fclose(archivo);
}

TElementoC maximo(TCola C)
{
    TCola aux;
    TElementoC maxAux, x;
    IniciaC(&aux);
    sacaC(&C, &maxAux);
    poneC(&aux, maxAux);
    while (!VaciaC(C))
    {
        sacaC(&C, &x);
        poneC(&aux, x);
        if (x > maxAux)
            maxAux = x;
    }
}

void generarPila(TLista L, TPila *P)
{
    TLista aux;
    IniciaP(P);
    aux = L;
    while (aux != NULL)
    {
        poneP(P, maximo(aux->dato));
        aux = aux->sig;
    }
}

void mostrarPila(TPila P)
{
    TElementoP x;
    if (VaciaP(P))
    {
        sacaP(&P, &x);
        mostrarPila(P);
    }
    poneP(&P, x);
    printf("%d ", x);
}