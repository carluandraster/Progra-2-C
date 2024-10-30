#include <stdio.h>
#define MAX_VERTICES 10
#define INFINITO 64999

void cargarDigrafo(unsigned int[][MAX_VERTICES], unsigned int *);
unsigned int min(unsigned int, unsigned int);
unsigned int posMinVal(unsigned int[], unsigned int, unsigned short int[]);
short int todosVisitados(unsigned short int[], unsigned int);
void Dijkstra(unsigned int[][MAX_VERTICES], unsigned int, unsigned int, unsigned int D[], unsigned int P[]);

int main()
{
    unsigned int DG[MAX_VERTICES][MAX_VERTICES], N, D[MAX_VERTICES], P[MAX_VERTICES], i, j;
    cargarDigrafo(DG, &N);
    for (i = 0; i < N; i++)
    {
        Dijkstra(DG, N, i, D, P);
        for (j = 0; j < N; j++)
            printf("%u ", P[j]);
        printf("\n");
    }
    return 0;
}

void cargarDigrafo(unsigned int DG[MAX_VERTICES][MAX_VERTICES], unsigned int *N)
{
    unsigned int i, j;
    FILE *archivo;
    archivo = fopen("../matriz.txt", "rt");
    fscanf(archivo, "%u", N);
    for (i = 0; i < *N; i++)
        for (j = 0; j < *N; j++)
            fscanf(archivo, "%u", &DG[i][j]);
    fclose(archivo);
}

unsigned int min(unsigned int a, unsigned int b)
{
    return a < b ? a : b;
}

unsigned int posMinVal(unsigned int D[], unsigned int N, unsigned short int VV[])
{
    unsigned int minAux = INFINITO, i, iMin;
    for (i = 0; i < N; i++)
        if (D[i] < minAux && !VV[i])
        {
            minAux = D[i];
            iMin = i;
        }

    return iMin;
}

short int todosVisitados(unsigned short int VV[], unsigned int N)
{
    unsigned int i = 0;
    while (i < N && VV[i])
        i++;
    return i == N;
}

void Dijkstra(unsigned int DG[][MAX_VERTICES], unsigned int N, unsigned int origen, unsigned int D[], unsigned int P[])
{
    unsigned short int VV[N];
    unsigned int i, k, d;

    // Inicialización
    for (i = 0; i < N; i++)
    {
        VV[i] = 0;
        if (DG[origen][i] > 0)
        {
            D[i] = DG[origen][i];
            P[i] = 0;
        }
        else
            P[i] = D[i] = INFINITO;
    }
    VV[origen] = 1;
    P[origen] = D[origen] = 0;

    while (!todosVisitados(VV, N))
    {
        k = posMinVal(D, N, VV);
        VV[k] = 1;
        for (i = 0; i < N; i++)
            if (!VV[i] && DG[k][i] != 0)
            {
                d = D[i];
                D[i] = min(D[i], D[k] + DG[k][i]);
                if (d != D[i])
                    P[i] = k + 1;
            }
    }
}