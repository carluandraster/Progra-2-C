#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct nodo
{
    int dato;
    struct nodo *ant, *sig;
} nodo;
typedef struct
{
    nodo *pri, *ult;
} TListaD;

void insertarMedia(TListaD *D, int X);
nodo *buscar(TListaD D, int X);
void eliminarSiguiente(TListaD *D, nodo *pos);
void eliminarOcurrecnias(TListaD *D, int X);
void mostrarLista(TListaD D);

int main()
{
    TListaD D;
    nodo *pos;
    int X;
    char res;

    // Inicializar D
    D.pri = D.ult = NULL;

    // Cargar D
    do
    {
        printf("Ingrese un numero: ");
        scanf("%d", &X);
        insertarMedia(&D, X);
        mostrarLista(D);
        do
        {
            printf("Desea ingresar otro numero? (S o N)\n");
            scanf(" %c", &res);
            res = toupper(res);
        } while (res != 'S' && res != 'N');
    } while (res == 'S');

    // Eliminar un elemento
    do
    {
        printf("Ingrese un elemento de la lista: ");
        scanf("%d", &X);
        pos = buscar(D, X);
    } while (pos == NULL);
    eliminarSiguiente(&D, pos);
    mostrarLista(D);

    // Eliminar ocurrencias de un elemento X
    printf("Ingrese numero a eliminar en la lista: ");
    scanf("%d", &X);
    eliminarOcurrecnias(&D, X);
    mostrarLista(D);

    return 0;
}

// Inserta X en el medio de D
void insertarMedia(TListaD *D, int X)
{
    nodo *izq, *der, *nuevo;
    nuevo = (nodo *)malloc(sizeof(nodo));
    nuevo->dato = X;
    if ((*D).pri == NULL)
    {
        (*D).pri = (*D).ult = nuevo;
        nuevo->sig = nuevo->ant = NULL;
    }
    else
    {
        izq = (*D).pri;
        der = (*D).ult;
        while (izq->sig != der && izq != der)
        {
            izq = izq->sig;
            der = der->ant;
        }
        nuevo->sig = izq->sig;
        nuevo->ant = izq;
        if (izq->sig == NULL)
            (*D).ult = nuevo;
        else
            izq->sig->ant = nuevo;
        izq->sig = nuevo;
    }
}

// Dado un numero, devuelve un puntero a la primera ocurrencia
nodo *buscar(TListaD D, int X)
{
    nodo *aux;
    aux = D.pri;
    while (aux != NULL && aux->dato != X)
        aux = aux->sig;
    return aux;
}

void eliminarSiguiente(TListaD *D, nodo *pos)
{
    nodo *elim;
    if (D->pri != NULL)
        if (pos == NULL)
        {
            elim = D->pri;
            D->pri = elim->sig;
            D->pri->ant = NULL;
            free(elim);
        }
        else if (pos->sig != NULL)
        {
            elim = pos->sig;
            pos->sig = elim->sig;
            if (elim->sig == NULL)
                D->ult = pos;
            else
                elim->sig->ant = pos;
            free(elim);
        }
}

void eliminarOcurrecnias(TListaD *D, int X)
{
    nodo *aux;
    aux = D->pri;
    while (aux != NULL)
    {
        if (aux->dato == X)
            eliminarSiguiente(D, aux->ant);
        aux = aux->sig;
    }
}

void mostrarLista(TListaD D)
{
    nodo *aux;
    aux = D.pri;
    while (aux != NULL)
    {
        printf("%d ", aux->dato);
        aux = aux->sig;
    }
    printf("\n");
}