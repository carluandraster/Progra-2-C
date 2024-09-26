#include "pilaEstatica.h"

void IniciaP(TPila *P){
    P->N = 0;
}

void poneP(TPila *P, TElementoP x){
    P->V[P->N] = x;
    P->N++;
}

void sacaP(TPila *P, TElementoP *x){
    if (P->N >0)
    {
        P->N--;
        *x = P->V[P->N];
    }
}

TElementoP consultaP(TPila P){
    if (P.N >0)
    {
    return P.V[P.N-1];
    }
}

int VaciaP(TPila P){
    return P.N == 0;
}