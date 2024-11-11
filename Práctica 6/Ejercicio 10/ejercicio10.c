#include <stdio.h>
#include <stdlib.h>
#define MAXELEM 50

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
int esPalindroma(TListaD LD);

int main()
{
    TListaD LD;
    cargarLista(&LD);
    printf(esPalindroma(LD) ? "La palabra es palindroma.\n" : "La palabra no es palindroma.\n");
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

int esPalindroma(TListaD LD)
{
    nodo *izq, *der;
    izq = LD.pri;
    der = LD.ult;
    while (izq != der && izq->ant != der && izq->dato == der->dato)
    {
        izq = izq->sig;
        der = der->ant;
    }
    return izq == der || izq->ant == der;
}