#include <stdio.h>
#define MAXELEM 20

void cargarMatriz(int[MAXELEM][MAXELEM], unsigned *, unsigned *);
void maximoDeCadaFila(int[MAXELEM][MAXELEM], unsigned, unsigned, unsigned, int[MAXELEM]);
void mostrarElementos(int VECTOR[MAXELEM], unsigned int N);

short main()
{
    int MATRIZ[MAXELEM][MAXELEM], MAXIMOS[MAXELEM];
    unsigned N, M;
    cargarMatriz(MATRIZ, &M, &N);
    maximoDeCadaFila(MATRIZ, M, N, N - 1, MAXIMOS);
    mostrarElementos(MAXIMOS, M);
    return 0;
}

void cargarMatriz(int MATRIZ[MAXELEM][MAXELEM], unsigned *M, unsigned *N)
{
    FILE *archivo;
    unsigned i, j;
    archivo = fopen("matriz.txt", "rt");
    if (archivo == NULL)
        printf("El archivo no se pudo abrir");
    else
    {
        fscanf(archivo, "%u %u", M, N);
        for (i = 0; i < *M; i++)
            for (j = 0; j < *N; j++)
                fscanf(archivo, "%d", &MATRIZ[i][j]);
        fclose(archivo);
    }
}

void maximoDeCadaFila(int MATRIZ[MAXELEM][MAXELEM], unsigned M, unsigned N, unsigned i, int MAXIMOS[MAXELEM])
{
    if (i == N - 1 || MATRIZ[M - 1][i] > MAXIMOS[M - 1])
        MAXIMOS[M - 1] = MATRIZ[M - 1][i];
    if (i == 0)
    {
        if (M > 1)
            maximoDeCadaFila(MATRIZ, M - 1, N, N - 1, MAXIMOS);
    }
    else
        maximoDeCadaFila(MATRIZ, M, N, i - 1, MAXIMOS);
}

void mostrarElementos(int VECTOR[MAXELEM], unsigned int N)
{
    if (N > 1)
        mostrarElementos(VECTOR, N - 1);
    printf("%d ", VECTOR[N - 1]);
}