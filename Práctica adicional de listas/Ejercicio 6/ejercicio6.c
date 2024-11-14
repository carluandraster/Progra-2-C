#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo *sig;
} nodo;
typedef nodo *TListaC;

void insertarDesp(TListaC *LC, TListaC ant, int X);
void insertarAnt(TListaC *LC, TListaC desp, int X);
void eliminar(TListaC *LC, int X);