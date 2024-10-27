#include <stdio.h>
#define MAX_VERTICES 10

typedef unsigned short int byte;
typedef struct
{
    byte grado, vertice;
} TRegistro;

void cargarGrafo(byte G[][MAX_VERTICES], byte *N);
byte grado(byte G[][MAX_VERTICES], byte N, byte vertice);
void generarArreglo(byte G[][MAX_VERTICES], byte N, byte vertice, TRegistro REGISTROS[MAX_VERTICES], byte *M);
void imprimirArreglo(TRegistro REGISTROS[MAX_VERTICES], byte M);

int main()
{
    byte G[MAX_VERTICES][MAX_VERTICES], N, M = 0;
    TRegistro REGISTROS[MAX_VERTICES];

    cargarGrafo(G, &N);
    generarArreglo(G, N, 0, REGISTROS, &M);
    imprimirArreglo(REGISTROS, M);

    return 0;
}

void cargarGrafo(byte A[MAX_VERTICES][MAX_VERTICES], byte *N)
{
    byte i, j;
    FILE *archivo;

    archivo = fopen("../matriz.txt", "rt");
    fscanf(archivo, "%hu", N);
    for (i = 0; i < *N; i++)
        for (j = 0; j < *N; j++)
            fscanf(archivo, "%hu", &A[i][j]);
    fclose(archivo);
}

byte grado(byte G[][MAX_VERTICES], byte N, byte vertice)
{
    if (N == 0)
        return 0;
    else if (N - 1 == vertice)
        return G[N - 1][N - 1] + grado(G, N - 1, vertice);
    else
        return G[N - 1][vertice] + G[vertice][N - 1] + grado(G, N - 1, vertice);
}

void generarArreglo(byte G[][MAX_VERTICES], byte N, byte Vertice, TRegistro REGISTROS[MAX_VERTICES], byte *M)
{
    byte gradoAux;
    if (Vertice < N)
    {
        gradoAux = grado(G, N, Vertice);
        if (gradoAux > 3)
        {
            REGISTROS[*M].grado = gradoAux;
            REGISTROS[*M].vertice = Vertice;
            ++*M;
        }
        generarArreglo(G, N, Vertice + 1, REGISTROS, M);
    }
}

void imprimirArreglo(TRegistro REGISTROS[MAX_VERTICES], byte M)
{
    byte i;

    printf("Vertice Grado\n");
    for (i = 0; i < M; i++)
        printf("   %c      %hu\n", REGISTROS[i].vertice + 65, REGISTROS[i].grado);
}