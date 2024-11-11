#include <stdio.h>
#include <stdlib.h>

typedef int TELEMENTOLC;
typedef struct nodo
{
    TELEMENTOLC dato;
    struct nodo *sig;
} nodo;
typedef nodo *TLISTAC;

void cargarLista(TLISTAC *pult);
void lc_eliminaelem(TLISTAC *pult, TELEMENTOLC elem, int *eliminado);
void mostrarLista(TLISTAC pult);

int main()
{
    TLISTAC pult = NULL;
    TELEMENTOLC elem;
    int eliminado;

    cargarLista(&pult);
    printf("Ingrese un elemento de la lista: ");
    scanf("%d", &elem);
    lc_eliminaelem(&pult, elem, &eliminado);
    if (eliminado)
        mostrarLista(pult);
    else
        printf("No se encontro al elemento en la lista\n");

    return 0;
}

void cargarLista(TLISTAC *pult)
{
    int contenido[5] = {1, 2, 3, 4, 5}, i;
    TLISTAC aux, pri;
    aux = (TLISTAC)malloc(sizeof(nodo));
    aux->dato = contenido[0];
    *pult = pri = aux;
    for (i = 1; i < 5; i++)
    {
        aux = (TLISTAC)malloc(sizeof(nodo));
        aux->dato = contenido[i];
        (*pult)->sig = aux;
        *pult = aux;
    }
    aux->sig = pri;
}

void lc_eliminaelem(TLISTAC *pult, TELEMENTOLC elem, int *eliminado)
{
    TLISTAC ant = *pult, act = (*pult)->sig;
    *eliminado = 0;
    if (pult != NULL)
    {
        while (*pult != act && elem != act->dato)
        {
            ant = act;
            act = act->sig;
        }
        if (elem == act->dato)
        {
            ant->sig = act->sig;
            if (act == *pult)
                *pult = ant;
            free(act);
            *eliminado = 1;
        }
    }
}

void mostrarLista(TLISTAC pult)
{
    TLISTAC aux = pult;
    do
    {
        aux = aux->sig;
        printf("%d ", aux->dato);
    } while (aux != pult);
}