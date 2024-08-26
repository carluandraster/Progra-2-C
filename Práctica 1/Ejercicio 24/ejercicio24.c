// Librerías, constantes y tipos
#include <stdio.h>
#define MAXELEM 20
typedef unsigned short int byte;

// Prototipos
void leerMatriz(int[][], byte *, byte *);
void buscar(int, int[][], byte, byte, byte *, byte *);
void promedioColumnas(int[][], byte, byte, float[]);
float promedioTotal(float[], byte);
byte tieneCero(int[][], byte, byte);
void superanPromedio(int[][], byte, byte);

byte main()
{
    // Declaración de variables
    int MATRIZ[MAXELEM][MAXELEM], x;
    byte N, M, SUPERAN[MAXELEM], O, i, j;
    float PROMEDIOS[MAXELEM], promedio;

    // Entrada
    leerMatriz(int MATRIZ, N *, M *);

    // Inciso a
    printf("Busque un numero: ");
    scanf("%d", &x);
    buscar(x, MATRIZ, N, M, &i, &j);
    i > N ? printf("No se encontro %d en la matriz\n", x) : printf("Fila: %d\nColumna: %d\n", i, j);

    // Inciso b
    printf("Promedios de cada columna:\t");
    promedioColumnas(MATRIZ, N, M, PROMEDIOS);

    // Inciso c
    promedio = promedioTotal(PROMEDIOS, M);
    superanPromedio(MATRIZ, N, M);

    return 0;
}

void leerMatriz(int MATRIZ[][], byte *N, byte *M)
{
    byte i, j;

    do
    {
        printf('Ingrese dimensiones de la matriz: ');
        scanf("%hu %hu", N, M);
    } while (*N > MAXELEM || *M > MAXELEM || *N == 0 || *M == 0);

    for (i = 0; i < *N; i++)
        for (j = 0; j < *M; j++)
        {
            printf("Ingrese fila %hu columna %hu", i, j);
            scanf("%d", MATRIZ[i][j]);
        }
}

void buscar(int x, int MATRIZ[][], byte N, byte M, byte *i, byte *j)
{
    *i = 1;
    *j = 1;
    while (*i <= N && MATRIZ[*i][*j] != x)
    {
        while (*j <= M && MATRIZ[*i][*j] != x)
            ++*j;
        if (*j > M)
        {
            *j = 1;
            ++*i;
        }
    }
}

void promedioColumnas(int MATRIZ[][], byte N, byte M, float PROMEDIOS[])
{
    byte i, j;
    int acumulador;
    for (j = 1; j <= M; j++)
    {
        acumulador = 0;
        for (i = 1; i <= N; i++)
            acumulador += MATRIZ[i][j];
        PROMEDIOS[j] : = (float)acumulador / N;
        printf("%f\t", PROMEDIOS[j]);
    }
}

float promedioTotal(float PROMEDIOS[], byte M)
{
    byte i;
    float acumulador = 0;
    for (i = 0; i < M; i++)
        acumulador += PROMEDIOS[i];
    return acumulador / M;
}

byte tieneCero(int[][], byte, byte) {}