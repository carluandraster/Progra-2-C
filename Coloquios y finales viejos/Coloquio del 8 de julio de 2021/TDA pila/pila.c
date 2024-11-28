#include "pila.h"

// Indica si la pila esta vacia
int VaciaP(TPila P){
    return P.N == -1;
}

// Inicializa la pila
void IniciaP(TPila *P){
    P->N = -1;
}

// Devuelve el elemento que esta sobre la pila
TElementoP ConsultaP(TPila P){
    if (!VaciaP(P))
        return P.V[P.N];
}

// Saca al elemento que esta sobre la pila y lo almacena en x
void SacaP(TPila *P, TElementoP *x){
    if (!VaciaP(*P))
    {
        *x = ConsultaP(*P);
        P->N -=1;
    }
}

// Agrega un elemento a la pila
void PoneP(TPila *P, TElementoP x){
    if (P->N < MAX-1)
    {
        P->N +=1;
        P->V[P->N] = x;
    }
}