#include <stdio.h>
#include <stdlib.h>
#define MAXELEM 100

typedef struct nodo
{
    char dato;
    struct nodo *sig;
} nodo;
typedef nodo *TListaC;

void cargarLista(TListaC *LC);
void mostrarContenido(TListaC LC);
int cantNodosVocales(TListaC LC);
int listaOrdenada(TListaC LC);
void eliminar(TListaC *LC, int P);

int main()
{
    TListaC LC = NULL;
    int P;

    cargarLista(&LC);

    // Inciso a
    printf("Contenido de la lista: ");
    mostrarContenido(LC);
    printf("\n");

    // Inciso b
    printf("Cantidad de nodos que son vocales: %d\n", cantNodosVocales(LC));

    // Inciso c
    printf(listaOrdenada(LC) ? "La lista esta ordenada\n" : "La lista no esta ordenada\n");

    // Inciso d
    do
    {
        printf("Ingrese una posicion P: ");
        scanf("%d", &P);
    } while (P < 0);
    eliminar(&LC, P);
    printf("Lista modificada: ");
    mostrarContenido(LC);

    return 0;
}

void cargarLista(TListaC *LC)
{
    char cadena[MAXELEM];
    nodo *act, *pri;
    unsigned i = 0;

    printf("Ingrese una cadena de texto.\n");
    fgets(cadena, MAXELEM, stdin); // Leer una cadena completa con espacios

    while (cadena[i] != '\0' && cadena[i] != '\n') // Evitar el salto de línea al final
    {

        act = (nodo *)malloc(sizeof(nodo)); // Asignar memoria para nuevo nodo
        act->dato = cadena[i];

        if (*LC == NULL)
        { // Si es el primer nodo, asignarlo como cabeza de la lista

            *LC = pri = act;
        }
        else
        {
            (*LC)->sig = act; // Enlazar el nodo anterior con el actual
            *LC = act;
        }
        i++;
    }
    act->sig = pri;
}

void mostrarContenido(TListaC LC)
{
    nodo *aux;
    aux = LC;
    do
    {
        aux = aux->sig;
        printf("%c", aux->dato);
    } while (aux != LC);
}

int cantNodosVocales(TListaC LC)
{
    int contador = 0;
    nodo *aux;

    aux = LC;
    do
    {
        aux = aux->sig;
        contador += aux->dato == 'A' || aux->dato == 'a' || aux->dato == 'E' || aux->dato == 'e' || aux->dato == 'I' || aux->dato == 'i' || aux->dato == 'O' || aux->dato == 'o' || aux->dato == 'U' || aux->dato == 'u';
    } while (aux != LC);

    return contador;
}

int listaOrdenada(TListaC LC)
{
    nodo *aux, *ant;
    ant = LC;
    aux = LC->sig;
    do
    {
        ant = aux;
        aux = aux->sig;
    } while (ant != LC && ant->dato < aux->dato);
    return ant == LC;
}

void eliminar(TListaC *LC, int P)
{
    int i;
    nodo *aux, *ant;

    aux = *LC;
    for (i = 0; i < P; i++)
    {
        ant = aux;
        aux = aux->sig;
    }
    ant->sig = aux->sig;
    free(aux);
}