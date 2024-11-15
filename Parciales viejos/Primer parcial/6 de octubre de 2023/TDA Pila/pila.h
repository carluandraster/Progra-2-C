#include <stdlib.h>

typedef char TElementoP;
typedef struct nodoP
{
    TElementoP dato;
    struct nodoP *sig;
} nodoP;
typedef nodoP *TPila;

void IniciaP(TPila *P);
int VaciaP(TPila P);
TElementoP ConsultaP(TPila P);
void SacaP(TPila *P, TElementoP *x);
void PoneP(TPila *P, TElementoP x);