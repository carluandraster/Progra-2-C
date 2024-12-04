#define MAX 100

typedef struct
{
    int vertice;
    unsigned int grado;
} TElementoC;
typedef struct TCola
{
    TElementoC V[MAX];
    int pri, ult;
} TCola;

void IniciaC(TCola *C);
int VaciaC(TCola C);
TElementoC ConsultaC(TCola C);
void PoneC(TCola *C, TElementoC x);
void SacaC(TCola *C, TElementoC *x);