#define MAXELEM 1000

typedef int TElementoP;
typedef struct
{
    TElementoP V[MAXELEM];
    unsigned N;
} TPila;

void IniciaP(TPila *P);
void poneP(TPila *P, TElementoP x);
void sacaP(TPila *P, TElementoP *x);
TElementoP consultaP(TPila P);
int VaciaP(TPila P);