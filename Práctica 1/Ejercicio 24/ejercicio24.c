// Librerías, constantes y tipos
#include <stdio.h>
#define MAXELEM 20
typedef unsigned short int byte;

// Prototipos
void leerMatriz(int[MAXELEM][MAXELEM], byte *, byte *);
void buscar(int, int[MAXELEM][MAXELEM], byte, byte, byte *, byte *);
void promedioColumnas(int[MAXELEM][MAXELEM], byte, byte, float[MAXELEM]);
float promedioTotal(float[MAXELEM], byte);
byte tieneCero(int[MAXELEM][MAXELEM], byte, byte);
void superanPromedio(int[MAXELEM][MAXELEM], byte, byte, float);

byte main()
{
    // Declaración de variables
    int MATRIZ[MAXELEM][MAXELEM], x;
    byte N, M, SUPERAN[MAXELEM], O, i, j;
    float PROMEDIOS[MAXELEM], promedio;

    // Entrada
    leerMatriz(MATRIZ, &N, &M);

    // Inciso a
    printf("Busque un numero: ");
    scanf("%d", &x);
    buscar(x, MATRIZ, N, M, &i, &j);
    i > N ? printf("No se encontro %d en la matriz\n", x) : printf("Fila: %d\nColumna: %d\n", i + 1, j + 1);

    // Inciso b
    printf("Promedios de cada columna:\t");
    promedioColumnas(MATRIZ, N, M, PROMEDIOS);

    // Inciso c
    promedio = promedioTotal(PROMEDIOS, M);
    superanPromedio(MATRIZ, N, M, promedio);

    return 0;
}

void leerMatriz(int MATRIZ[MAXELEM][MAXELEM], byte *N, byte *M)
{
    byte i, j;

    do
    {
        printf("Ingrese dimensiones de la matriz: ");
        scanf("%hu %hu", N, M);
    } while (*N > MAXELEM || *M > MAXELEM || *N == 0 || *M == 0);

    for (i = 0; i < *N; i++)
        for (j = 0; j < *M; j++)
        {
            printf("Ingrese fila %hu columna %hu: ", i + 1, j + 1);
            scanf("%d", &MATRIZ[i][j]);
        }
}

void buscar(int x, int MATRIZ[MAXELEM][MAXELEM], byte N, byte M, byte *i, byte *j)
{
    *i = 0;
    *j = 0;
    while (*i < N && MATRIZ[*i][*j] != x)
    {
        while (*j < M && MATRIZ[*i][*j] != x)
            ++*j;
        if (*j == M)
        {
            *j = 0;
            ++*i;
        }
    }
}

void promedioColumnas(int MATRIZ[MAXELEM][MAXELEM], byte N, byte M, float PROMEDIOS[])
{
    byte i, j;
    int acumulador;
    for (j = 0; j < M; j++)
    {
        acumulador = 0;
        for (i = 0; i < N; i++)
            acumulador += MATRIZ[i][j];
        PROMEDIOS[j] = (float)acumulador / N;
        printf("%f\t", PROMEDIOS[j]);
    }
    printf("\n");
}

float promedioTotal(float PROMEDIOS[MAXELEM], byte M)
{
    byte i;
    float acumulador = 0;
    for (i = 0; i < M; i++)
        acumulador += PROMEDIOS[i];
    return acumulador / M;
}

byte tieneCero(int MATRIZ[MAXELEM][MAXELEM], byte FILA, byte M)
{
    byte i = 0;
    while (i < M && MATRIZ[FILA][i] != 0)
        i++;
    return i < M;
}

void superanPromedio(int MATRIZ[MAXELEM][MAXELEM], byte N, byte M, float promedio)
{
    byte i, j, contador;
    for (i = 0; i < N; i++)
        if (tieneCero(MATRIZ, i, M))
        {
            contador = 0;
            for (j = 0; j < M; j++)
                if (MATRIZ[i][j] > promedio)
                    contador++;
            printf("La fila %hu tiene %hu numeros que superan el promedio de la matriz.\n", i + 1, contador);
        }
}