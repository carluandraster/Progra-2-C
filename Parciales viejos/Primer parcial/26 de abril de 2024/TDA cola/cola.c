#include "cola.h"

// Inicializa la cola
void IniciaC(TCola *C)
{
    C->pri = C->ult = -1;
}

// Verifica si la cola esta vacia
int VaciaC(TCola C)
{
    return C.pri == -1;
}

// Devuelve el primer elemento de la cola
TElementoC ConsultaC(TCola C)
{
    if (!VaciaC(C))
        return C.dato[C.pri];
}

// Saca un elemento de la cola
void SacaC(TCola *C, TElementoC *x)
{
    if (!VaciaC(*C))
    {
        *x = ConsultaC(*C);
        if (C->pri == C->ult)
            IniciaC(C);
        else
            C->pri += 1;
    }
}

// Pone un elemento en la cola
void PoneC(TCola *C, TElementoC x)
{
    if (C->ult < MAX - 1)
    { // Cola no llena
        if (C->pri == -1)
            C->pri = 0;
        C->ult++;
        C->dato[C->ult] = x;
    }
}