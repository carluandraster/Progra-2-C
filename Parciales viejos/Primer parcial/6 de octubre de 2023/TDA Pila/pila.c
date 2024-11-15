#include "pila.h"

// Inicializa la pila
void IniciaP(TPila *P)
{
    *P = NULL;
}

// Verifica si la pila esta vacia
int VaciaP(TPila P)
{
    return P == NULL;
}

// Devuelve el elemento que esta por encima en la pila
TElementoP ConsultaP(TPila P)
{
    return P->dato;
}

// Saca el elemento mas por encima en la pila
void SacaP(TPila *P, TElementoP *x)
{
    TPila elim;
    *x = (*P)->dato;
    elim = *P;
    *P = (*P)->sig;
    free(elim);
}

// Apila un elemento a la pila
void PoneP(TPila *P, TElementoP x)
{
    TPila nuevo = (TPila)malloc(sizeof(nodoP));
    nuevo->dato = x;
    nuevo->sig = *P;
    *P = nuevo;
}