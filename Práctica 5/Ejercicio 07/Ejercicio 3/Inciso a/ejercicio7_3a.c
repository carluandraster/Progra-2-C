#include <stdio.h>
#include "../../../Ejercicio 03/pilaDinamica.h"

void cargarPila(TPila *P);
void mostrarVotantes(TPila *P, unsigned N);

int main()
{
    TPila P;
    unsigned N;
    IniciaP(&P);
    cargarPila(&P);
    printf("Ingrese numero: ");
    scanf("%u", &N);
    mostrarVotantes(&P, N);
    return 0;
}

void cargarPila(TPila *P)
{
    TElementoP x;
    FILE *archivo;
    archivo = fopen("../../../Ejercicio 03/dnis.txt", "rt");
    while (fscanf(archivo, "%s", x.DNI) == 1)
        poneP(P, x);
    fclose(archivo);
}

void mostrarVotantes(TPila *P, unsigned N)
{
    TElementoP x;
    if (N > 0 && !VaciaP(*P))
    {
        sacaP(P, &x);
        printf("%s\n", x.DNI);
        mostrarVotantes(P, N - 1);
    }
    poneP(P, x);
}