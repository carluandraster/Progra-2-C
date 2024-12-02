#include "cola.h"

void IniciaC(TCola *C)
{
    C->pri = C->ult = -1;
}

int VaciaC(TCola C)
{
    return C.pri == -1;
}

TElementoC ConsultaC(TCola C)
{
    if (C.pri != -1)
        return C.V[C.pri];
}

void SacaC(TCola *C, TElementoC *x)
{
    if (C->pri != -1)
    {
        *x = C->V[C->pri];
        if (C->pri == C->ult)
            C->pri = C->ult = -1;
        else if (C->pri == MAX - 1)
            C->pri = 0;
        else
            C->pri++;
    }
}

void PoneC(TCola *C, TElementoC x)
{
    if (!(C->ult == MAX - 1 && C->pri == 0 || C->ult + 1 == C->pri))
    {
        if (C->ult == -1)
            C->pri = C->ult = 0;
        else if (C->ult == MAX - 1)
            C->ult = 0;
        else
            C->ult++;
        C->V[C->ult] = x;
    }
}