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
    suma(A, B, &C); // A+B=C
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
    TElementoP x, y, z, t = 0;
    while (!VaciaP(A) && !VaciaP(B))
    {
        sacaP(&A, &x);
        sacaP(&B, &y);
        x -= '0';
        y -= '0';
        z = x + y + t;
        t = z / 10;
        z %= 10;
        z += '0';
        poneP(C, z);
    }

    while (!VaciaP(A))
    {
        sacaP(&A, &x);
        x -= '0';
        z = x + t;
        t = z / 10;
        z %= 10;
        z += '0';
        poneP(C, z);
    }
    while (!VaciaP(B))
    {
        sacaP(&B, &x);
        x -= '0';
        z = x + t;
        t = z / 10;
        z %= 10;
        z += '0';
        poneP(C, z);
    }
}

void mostrarPila(TPila C)
{
    TElementoP x;
    while (!VaciaP(C))
    {
        sacaP(&C, &x);
        printf("%c", x);
    }
}