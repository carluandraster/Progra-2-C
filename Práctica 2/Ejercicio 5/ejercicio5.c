// Preprocesador
#include <stdio.h>
#include <stdlib.h>
#define MAXELEM 100

// Prototipos
void cargarArreglo(int *VECTOR[MAXELEM], unsigned *N);
void mostrarPositivos(int *VECTOR[MAXELEM], unsigned N);
void liberarMemoria(int *VECTOR[MAXELEM], unsigned N);

short main()
{
    int *VECTOR[MAXELEM];
    unsigned N;

    cargarArreglo(VECTOR, &N);
    mostrarPositivos(VECTOR, N);
    liberarMemoria(VECTOR, N);

    return 0;
}

void cargarArreglo(int *VECTOR[MAXELEM], unsigned *N)
{
    FILE *archivo;
    int num;
    *N = 0;
    archivo = fopen("enteros.txt", "rt");
    if (archivo == NULL)
        printf("Ocurrio un error en la apertura del archivo.");
    else
        while (fscanf(archivo, "%d", &num) == 1)
        {
            VECTOR[*N] = (int *)malloc(sizeof(int));
            *VECTOR[*N] = num;
            ++*N;
        }
}

void mostrarPositivos(int *VECTOR[MAXELEM], unsigned N)
{
    unsigned i;
    printf("Numeros positivos: ");
    for (i = 0; i < N; i++)
        if (*VECTOR[i] > 0)
            printf("%d ", *VECTOR[i]);
}

void liberarMemoria(int *VECTOR[MAXELEM], unsigned N)
{
    unsigned i;
    for (i = 0; i < N; i++)
        free(VECTOR[i]);
}