#include "cola.h"

void IniciaC(TCola *C)
{
    (*C).pri = -1;
    (*C).ult = -1;
}

int VaciaC(TCola C)
{
    return C.pri == -1;
}

void poneC(TCola *C, TElementoC x)
{
    if (!((*C).ult == MAX - 1 && (*C).pri == 0 || (*C).ult + 1 == (*C).pri)) // Cola no llena
    {
        if ((*C).pri == -1) // Cola vacía
            (*C).pri = (*C).ult = 0;
        else if ((*C).ult == MAX - 1)
            (*C).ult = 0;
        else
            (*C).ult += 1;
        (*C).datos[(*C).ult] = x;
    }
}

void sacaC(TCola *C, TElementoC *x)
{
    if ((*C).pri != -1)
    {
        *x = (*C).datos[(*C).pri];
        if ((*C).pri == (*C).ult) // Cola vacía
            IniciaC(C);
        else if ((*C).pri == MAX - 1)
            (*C).pri = 0;
        else
            (*C).pri += 1;
    }
}

TElementoC consultaC(TCola C)
{
    if (C.pri != -1)
        return C.datos[C.pri];
}