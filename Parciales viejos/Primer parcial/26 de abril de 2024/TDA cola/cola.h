#define MAX 100

typedef struct
{
    char texto[8];
} TElementoC;
typedef struct
{
    TElementoC dato[MAX];
    int pri, ult;
} TCola;

void IniciaC(TCola *C);
int VaciaC(TCola C);
TElementoC ConsultaC(TCola C);
void SacaC(TCola *C, TElementoC *x);
void PoneC(TCola *C, TElementoC x);