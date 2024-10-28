#include <stdio.h>
#include "Pila/pilaDinamica.h"
#include "Cola/colaDinamica.h"
#define MAX_VERTICES 10

typedef unsigned short int byte;

void cargarGrafo(byte G[][MAX_VERTICES], byte *N);
byte todosVisitados(byte VV[], byte N);
void profundidad(byte G[][MAX_VERTICES], byte N);
void amplitud(byte G[][MAX_VERTICES], byte N, byte *conexas);

int main()
{
    byte G[MAX_VERTICES][MAX_VERTICES], N, conexas;
    cargarGrafo(G, &N);
    profundidad(G, N);
    amplitud(G, N, &conexas);
    printf("Cantidad de componentes conexas: %hu\n", conexas);
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

byte todosVisitados(byte VV[], byte N)
{
    byte i = 0;
    while (i < N && VV[i])
        i++;
    return i == N;
}

void profundidad(byte G[][MAX_VERTICES], byte N)
{
    byte VV[N], i, vertice;
    TPila P;

    // Inicializar variables
    for (i = 0; i < N; i++)
        VV[i] = 0;
    IniciaP(&P);

    printf("Recorrido en profundidad: ");
    while (!todosVisitados(VV, N))
    {
        // Buscar un vertice no visitado
        i = 0;
        while (VV[i])
            i++;
        poneP(&P, i);
        // Visitarlo
        printf("%c ", i + 65);
        VV[i] = 1;
        while (!VaciaP(P) && !todosVisitados(VV, N))
        {
            vertice = consultaP(P);
            // Busco un adyacente no visitado de vertice
            i = 0;
            while (i < N && (!G[vertice][i] || VV[i]))
                i++;
            if (i < N)
            {
                poneP(&P, i);
                printf("%c ", i + 65);
                VV[i] = 1;
            }
            else
                sacaP(&P, &vertice);
        }
    }
    printf("\n");
}

void amplitud(byte G[][MAX_VERTICES], byte N, byte *conexas)
{
    byte VV[N], i, vertice;
    TCola c;

    // Inicializar variables
    for (i = 0; i < N; i++)
        VV[i] = 0;
    IniciaC(&c);
    *conexas = 0;

    printf("Recorrido en amplitud: ");
    while (!todosVisitados(VV, N))
    {
        i = 0;
        while (VV[i])
            i++;
        poneC(&c, i);
        ++*conexas;
        while (!todosVisitados(VV, N) && !VaciaC(c))
        {
            sacaC(&c, &vertice);
            printf("%c ", vertice + 65);
            VV[vertice] = 1;
            for (i = 0; i < N; i++)
                if (!VV[i] && G[vertice][i])
                    poneC(&c, i);
        }
    }
    printf("\n");
}