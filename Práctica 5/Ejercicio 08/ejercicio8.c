#include <stdio.h>
#include "../Ejercicio 01/Inciso b/pilaDinamica.h"

void cargarPila(TPila *P);
void cambiarSigno(TPila *P);
void mostrarPila(TPila *P);

int main()
{
    TPila P;
    IniciaP(&P);
    cargarPila(&P);
    cambiarSigno(&P);
    mostrarPila(&P);
    return 0;
}

void cargarPila(TPila *P)
{
    TElementoP x;
    FILE *archivo;
    archivo = fopen("numeros_enteros.txt", "rt");
    if (archivo == NULL)
        printf("Hubo un problema al abrir el archivo.\n");
    else
    {
        while (fscanf(archivo, " %d", &x) == 1)
            poneP(P, x);
        fclose(archivo);
    }
}

void cambiarSigno(TPila *P)
{
    TElementoP x;
    if (!VaciaP(*P))
    {
        sacaP(P, &x);
        cambiarSigno(P);
        poneP(P, -x);
    }
}

void mostrarPila(TPila *P)
{
    TElementoP x;
    while (!VaciaP(*P))
    {
        sacaP(P, &x);
        printf("%d\n", x);
    }
}