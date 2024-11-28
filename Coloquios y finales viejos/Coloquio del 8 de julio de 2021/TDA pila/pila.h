#define MAX 100

typedef struct
{
    int numero;
    unsigned int pos;
} TElementoP;
typedef struct
{
    TElementoP V[MAX];
    int N;
} TPila;

int VaciaP(TPila P);
void IniciaP(TPila *P);
TElementoP ConsultaP(TPila P);
void SacaP(TPila *P, TElementoP *x);
void PoneP(TPila *P, TElementoP x);