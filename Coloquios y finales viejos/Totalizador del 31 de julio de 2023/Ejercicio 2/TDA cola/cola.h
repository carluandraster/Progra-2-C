#define MAX 100

typedef struct
{
    char texto[5];
} TElementoC;

typedef struct
{
    TElementoC V[MAX];
    int pri, ult;
} TCola;

void IniciaC(TCola *C);
int VaciaC(TCola C);
TElementoC ConsultaC(TCola C);
void PoneC(TCola *C, TElementoC x);
void SacaC(TCola *C, TElementoC *x);