#include <stdio.h>
#include <stdlib.h>
#define MAXELEM 100

typedef struct nodo
{
    char dato;
    struct nodo *ant, *sig;
} nodo;
typedef struct
{
    nodo *pri, *ult;
} TListaD;

void cargarLista(TListaD *LD);
void imprimirLista(TListaD LD);
int cantNodosVocales(TListaD LD);
int estaOrdenada(TListaD LD);
void eliminar(TListaD *LD, int P);

int main()
{
    TListaD LD;
    int P;

    cargarLista(&LD);

    // Inciso a
    printf("Contenido de la lista: ");
    imprimirLista(LD);
    printf("\n");

    // Inciso b
    printf("Cantidad de nodos que son vocales: %d\n", cantNodosVocales(LD));

    // Inciso c
    printf(estaOrdenada(LD) ? "La lista esta ordenada\n" : "La lista no esta ordenada\n");

    // Inciso d
    do
    {
        printf("Ingrese una posicion P: ");
        scanf("%d", &P);
    } while (P < 0);
    eliminar(&LD, P);
    printf("Lista modificada: ");
    imprimirLista(LD);

    return 0;
}

void cargarLista(TListaD *LD)
{
    char cadena[MAXELEM];
    nodo *act;
    unsigned i = 0;

    (*LD).pri = (*LD).ult = NULL;

    printf("Ingrese una cadena de texto.\n");
    fgets(cadena, MAXELEM, stdin); // Leer una cadena completa con espacios

    while (cadena[i] != '\0' && cadena[i] != '\n') // Evitar el salto de línea al final
    {
        act = (nodo *)malloc(sizeof(nodo)); // Asignar memoria para nuevo nodo
        act->dato = cadena[i];
        act->ant = (*LD).ult;
        act->sig = NULL; // El siguiente nodo será NULL inicialmente

        if ((*LD).pri == NULL) // Si es el primer nodo, asignarlo como cabeza de la lista
            (*LD).pri = (*LD).ult = act;
        else
            (*LD).ult->sig = act; // Enlazar el nodo anterior con el actual

        (*LD).ult = act; // Mover `ult` al nodo actual
        i++;
    }
}

void imprimirLista(TListaD LD)
{
    nodo *aux;
    aux = LD.pri;
    while (aux != NULL)
    {
        printf("%c", aux->dato);
        aux = aux->sig;
    }
}

int cantNodosVocales(TListaD LD)
{
    nodo *aux;
    int contador = 0;
    aux = LD.pri;
    while (aux != NULL)
    {
        contador += aux->dato == 'A' || aux->dato == 'a' || aux->dato == 'E' || aux->dato == 'e' || aux->dato == 'I' || aux->dato == 'i' || aux->dato == 'O' || aux->dato == 'o' || aux->dato == 'U' || aux->dato == 'u';
        aux = aux->sig;
    }
    return contador;
}

int estaOrdenada(TListaD LD)
{
    nodo *aux;
    aux = LD.pri;
    if (aux == NULL)
        return 1;
    else
    {
        do
        {
            aux = aux->sig;
        } while (aux != NULL && aux->ant->dato < aux->dato);
        return aux == NULL;
    }
}

void eliminar(TListaD *LD, int P)
{
    int i = 1;
    nodo *aux;
    aux = LD->pri;
    if (P == 1)
    {
        LD->pri = aux->sig;
        if (aux->sig != NULL)
            aux->sig->ant = NULL;
    }
    else
    {
        while (aux != NULL && i < P)
        {
            aux = aux->sig;
            i++;
        }
        if (LD->ult == aux)
        {
            LD->ult = aux->ant;
            aux->ant->sig = NULL;
        }
        else
        {
            aux->ant->sig = aux->sig;
            aux->sig->ant = aux->ant;
        }
    }
    free(aux);
}