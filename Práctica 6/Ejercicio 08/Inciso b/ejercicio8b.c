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
int listaOrdenada(TListaC LC);
void eliminar(TListaC *LC, int P);

int main()
{
    TListaC LC;
    int P;

    cargarLista(&LC);

    // Inciso a
    printf("Contenido de la lista: ");
    imprimirLista(LC);
    printf("\n");

    // Inciso b
    printf("Cantidad de nodos que son vocales: %d\n", cantNodosVocales(LC));

    // Inciso c
    printf(estaOrdenada(LC) ? "La lista esta ordenada\n" : "La lista no esta ordenada\n");

    // Inciso d
    do
    {
        printf("Ingrese una posicion P: ");
        scanf("%d", &P);
    } while (P < 0);
    eliminar(&LC, P);
    printf("Lista modificada: ");
    imprimirLista(LC);

    return 0;
}
