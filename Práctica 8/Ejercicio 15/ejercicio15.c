#include <stdio.h>
#define MAX_VERTICES 10
#define INFINITO 255

typedef unsigned short int byte;

void cargarGrafo(byte G[][MAX_VERTICES], byte *N);
byte todoConexo(byte CC[], byte N);
void Kruskal(byte G[][MAX_VERTICES], byte N, byte A[][MAX_VERTICES]);
byte todoVisitado(byte VV[], byte N);
void Prim(byte G[][MAX_VERTICES], byte N, byte A[][MAX_VERTICES]);
void imprimirMatriz(byte A[][MAX_VERTICES], byte N);

int main()
{
    byte G[MAX_VERTICES][MAX_VERTICES], A[MAX_VERTICES][MAX_VERTICES], N, *VV, i, j;
    cargarGrafo(G, &N);

    Kruskal(G, N, A);
    printf("Kruskal: \n");
    imprimirMatriz(A, N);

    Prim(G, N, A);
    printf("Prim: \n");
    imprimirMatriz(A, N);

    return 0;
}

void cargarGrafo(byte G[MAX_VERTICES][MAX_VERTICES], byte *N)
{
    byte i, j;
    FILE *archivo;

    archivo = fopen("matriz.txt", "rt");
    fscanf(archivo, "%hu", N);
    for (i = 0; i < *N; i++)
        for (j = 0; j < *N; j++)
            fscanf(archivo, "%hu", &G[i][j]);
    fclose(archivo);
}

byte todoConexo(byte CC[], byte N)
{
    byte i = 1;
    while (i < N && CC[i] == CC[0])
        i++;
    return i == N;
}

void Kruskal(byte G[][MAX_VERTICES], byte N, byte A[][MAX_VERTICES])
{
    byte CC[N], i, j, iMin, jMin, minAux;

    // Inicializar variables
    for (i = 0; i < N; i++)
    {
        CC[i] = i;
        for (j = 0; j < N; j++)
            A[i][j] = 0;
    }

    while (!todoConexo(CC, N))
    {
        minAux = INFINITO;
        for (i = 0; i < N; i++)
            for (j = i; j < N; j++)
                if (CC[i] != CC[j] && G[i][j] < minAux && G[i][j] > 0)
                {
                    minAux = G[i][j];
                    iMin = i;
                    jMin = j;
                }
        A[iMin][jMin] = A[jMin][iMin] = G[iMin][jMin];
        for (i = 0; i < N; i++)
            if (CC[i] == CC[jMin])
                CC[i] = CC[iMin];
    }
}

byte todoVisitado(byte VV[], byte N)
{
    byte i = 0;
    while (i < N && VV[i])
        i++;
    return i == N;
}

void Prim(byte G[][MAX_VERTICES], byte N, byte A[][MAX_VERTICES])
{
    byte i, j, iMin, jMin, minAux, VV[N];

    // Inicializar variables
    for (i = 0; i < N; i++)
    {
        VV[i] = 0;
        for (j = 0; j < N; j++)
            A[i][j] = 0;
    }
    VV[0] = 1;

    while (!todoVisitado(VV, N))
    {
        minAux = INFINITO;
        for (i = 0; i < N; i++)
            if (VV[i])
                for (j = 0; j < N; j++)
                    if (0 < G[i][j] && G[i][j] < minAux && !VV[j])
                    {
                        iMin = i;
                        jMin = j;
                        minAux = G[i][j];
                    }
        A[iMin][jMin] = A[jMin][iMin] = G[iMin][jMin];
        VV[jMin] = 1;
    }
}

void imprimirMatriz(byte A[][MAX_VERTICES], byte N)
{
    byte i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%hu ", A[i][j]);
        printf("\n");
    }
}