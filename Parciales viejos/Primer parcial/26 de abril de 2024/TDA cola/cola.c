#include "cola.h"

// Inicializa la cola
void IniciaC(TCola *C){
    C->pri = C->ult = -1;
}

// Verifica si la cola esta vacia
int VaciaC(TCola C){
    return C.pri == C.ult +1 || C.pri == -1;
}

// Devuelve el primer elemento de la cola
TElementoC ConsultaC(TCola C){
    if (!VaciaC)
        return C.dominio[C.pri];
}

// Saca un elemento de la cola
void SacaC(TCola *C, TElementoC *x){
    if (!VaciaC(*C))
    {
        *x = ConsultaC(*C);
        C->pri += 1;
    }
}

// Pone un elemento en la cola
void PoneC(TCola *C, TElementoC x){
    if (C->ult < MAX-1){ // Cola no llena
        C->ult += 1;
        if (C->pri == -1)
            C->pri = 0;
        C->dominio[C->ult] = x;
    }
}