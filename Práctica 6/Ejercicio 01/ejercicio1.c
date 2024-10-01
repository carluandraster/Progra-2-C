#include <stdio.h>
#include <stdlib.h>

#define MAXELEM 100

typedef struct nodo
{
    char dato;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;

void cargarLista(TLista *L);
void imprimirLista(TLista L);
unsigned cantVocales(TLista L);
short listaOrdenada(TLista L);
void eliminar(TLista *L, unsigned P);

int main()
{
    TLista lista = NULL;
    unsigned P;
    cargarLista(&lista);
    imprimirLista(lista);
    printf("Cantidad de vocales: %u\n", cantVocales(lista));
    printf(listaOrdenada(lista) ? "La lista esta ordenada.\n" : "La lista no esta ordenada.\n");
    printf("Ingrese una posicion: ");
    scanf("%u", &P);
    eliminar(&lista, P);
    imprimirLista(lista);
    return 0;
}

void cargarLista(TLista *L)
{
    char cadena[MAXELEM];
    nodo *act, *prev = NULL;
    unsigned i = 0;

    printf("Ingrese una cadena de texto.\n");
    fgets(cadena, MAXELEM, stdin); // Leer una cadena completa con espacios

    while (cadena[i] != '\0' && cadena[i] != '\n') // Evitar el salto de línea al final
    {
        act = (nodo *)malloc(sizeof(nodo)); // Asignar memoria para nuevo nodo
        act->dato = cadena[i];
        act->sig = NULL; // El siguiente nodo será NULL inicialmente

        if (*L == NULL) // Si es el primer nodo, asignarlo como cabeza de la lista
            *L = act;
        else
            prev->sig = act; // Enlazar el nodo anterior con el actual

        prev = act; // Mover `prev` al nodo actual
        i++;
    }
}

// Función para imprimir la lista
void imprimirLista(TLista L)
{
    TLista aux = L;
    while (aux != NULL)
    {
        printf("%c", aux->dato);
        aux = aux->sig;
    }
    printf("\n");
}

unsigned cantVocales(TLista L)
{
    unsigned aux = 0;
    TLista auxiliar;
    auxiliar = L;
    while (auxiliar != NULL)
    {
        aux += auxiliar->dato == 'A' || auxiliar->dato == 'a' || auxiliar->dato == 'E' || auxiliar->dato == 'e' || auxiliar->dato == 'I' || auxiliar->dato == 'i' || auxiliar->dato == 'O' || auxiliar->dato == 'o' || auxiliar->dato == 'U' || auxiliar->dato == 'u';
        auxiliar = auxiliar->sig;
    }
    return aux;
}

short listaOrdenada(TLista L)
{
    TLista act, ant;
    ant = L;
    act = ant->sig;
    while (act != NULL && ant->dato <= act->dato)
    {
        ant = act;
        act = act->sig;
    }
    return act == NULL;
}

void eliminar(TLista *L, unsigned P)
{
    TLista ant, elim = *L, act = elim->sig;
    unsigned i;
    if (P == 1)
        *L = act;
    else
    {
        for (i = 1; i < P; i++)
        {
            ant = elim;
            elim = elim->sig;
            act = act->sig;
        }
        ant->sig = act;
    }
    free(elim);
}