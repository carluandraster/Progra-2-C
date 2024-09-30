#include <stdio.h>
#include "colaDinamica.h"
#define MAXELEM 100
#define CENTINELA '.'

void ingresarExpresion(TCola *A);
void chequearParentesis(TCola *A);
void chequearCorchetes(TCola *A);
void chequearLlaves(TCola *A);

int main()
{
    TCola A;
    IniciaC(&A);
    ingresarExpresion(&A);
    // Inciso a
    chequearParentesis(&A);
    // Inciso b
    chequearCorchetes(&A);
    chequearLlaves(&A);
    return 0;
}

void ingresarExpresion(TCola *A)
{
    char expresion[MAXELEM];
    unsigned short i = 0;
    printf("Ingrese una expresion: ");
    scanf("%s", expresion);
    while (expresion[i] != '\0')
    {
        poneC(A, expresion[i]);
        i++;
    }
}

void chequearParentesis(TCola *A)
{
    TElementoC x;
    unsigned short contaAbre = 0, contaCierra = 0;
    short faltaIzq = 0;
    while (x != CENTINELA)
    {
        sacaC(A, &x);
        poneC(A, x);
        contaAbre += x == '(';
        contaCierra += x == ')';
        if (contaCierra > contaAbre)
        {
            faltaIzq = 1;
        }
    }
    if (faltaIzq)
        printf("Falta abrir parentesis.\n");

    if (contaAbre > contaCierra)
        printf("Falta cerrar parentesis.\n");
}

void chequearCorchetes(TCola *A)
{
    TCola aux;
    TElementoC x;
    unsigned short contaAbre = 0, contaCierra = 0;
    short faltaIzq;
    while (!VaciaC(*A))
    {
        sacaC(A, &x);
        contaAbre += x == '(';
        contaCierra += x == ')';
        if (contaCierra > contaAbre)
        {
            faltaIzq = 1;
        }
    }
    if (faltaIzq)
        printf("Falta abrir parentesis.\n");

    if (contaAbre > contaCierra)
        printf("Falta cerrar parentesis.\n");
}