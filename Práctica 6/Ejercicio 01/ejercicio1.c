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
void mostrarContenido(TLista L);
unsigned cantVocales(TLista L);
short listaOrdenada(TLista L);
void eliminar(TLista *L, unsigned P);

int main()
{
    TLista L;
    unsigned P;
    cargarLista(&L);
    mostrarContenido(L);
    /*printf("Cantidad de vocales: %u\n", cantVocales(L));
    printf(listaOrdenada(L) ? "La lista esta ordenada.\n" : "La lista no esta ordenada.\n");
    printf("Ingrese una posicion: ");
    scanf("%u", &P);
    eliminar(&L, P);
    mostrarContenido(L);*/
    return 0;
}

void cargarLista(TLista *L)
{
    char cadena[MAXELEM];
    nodo *act;
    unsigned i = 1;
    printf("Ingrese una cadena de texto.\n");
    scanf("%s", cadena);
    act = (nodo *)malloc(sizeof(nodo));
    act->dato = cadena[0];
    act->sig = NULL;
    *L = act;
    while (cadena[i] != '\0')
    {
        act = (nodo *)malloc(sizeof(nodo));
        act->dato = cadena[i];
        act = act->sig;
        i++;
    }
}

void mostrarContenido(TLista L)
{
    while (L != NULL)
    {
        printf("%c", L->dato);
        L = L->sig;
    }
}