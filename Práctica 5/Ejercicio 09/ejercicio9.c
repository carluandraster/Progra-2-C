#include <stdio.h>
#include "pilaDinamica.h"
#define MAXELEM 100

void ingresarNumero(TPila *A);
// A + B = C
void suma(TPila A, TPila B, TPila *C);
void mostrarPila(TPila C);

int main()
{
    TPila A, B, C;
    IniciaP(&A);
    IniciaP(&B);
    IniciaP(&C);
    ingresarNumero(&A);
    ingresarNumero(&B);
    suma(A, B, &C);
    mostrarPila(C);
    return 0;
}

void ingresarNumero(TPila *A)
{
    char numStr[MAXELEM];
    unsigned i = 0;
    printf("Ingrese un numero: ");
    scanf("%s", numStr);
    while (numStr[i] != '\0')
    {
        poneP(A, numStr[i]);
        i++;
    }
}

void suma(TPila A, TPila B, TPila *C)
{
    while (!VaciaP(A) && !VaciaP(B))
    {
        /* code */
    }
    while (!VaciaP(A))
    {
        /* code */
    }
    while (!VaciaP(B))
    {
        /* code */
    }
}