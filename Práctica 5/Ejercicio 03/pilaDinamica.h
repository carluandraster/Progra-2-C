typedef struct
{
    char DNI[9];
}TElementoP;
typedef struct nodop
{
    TElementoP dato;
    struct nodop *sig;
} nodop;
typedef nodop *TPila;

void IniciaP(TPila *P);
void poneP(TPila *P, TElementoP x);
void sacaP(TPila *P, TElementoP *x);
TElementoP consultaP(TPila P);
int VaciaP(TPila P);