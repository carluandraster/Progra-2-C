#include <stdio.h>
#define MAX_VERTICES 20
#define INF 255

void cargarDigrafo(unsigned int DG[][MAX_VERTICES], unsigned int *N);
short int todosVisitados(short int VV[], unsigned int N);
void Dijkstra(unsigned int DG[][MAX_VERTICES], unsigned int N, char origen, unsigned int D[], char P[], short int VV[]);
void mostrarD(unsigned int D[], unsigned int N);
void mostrarP(char P[], unsigned int N);

int main()
{
    unsigned int DG[MAX_VERTICES][MAX_VERTICES], N;
    unsigned int D[MAX_VERTICES] = {0, 15, 21, 13, INF};
    char P[MAX_VERTICES] = {0, 0, 'D', 0, INF};
    short int VV[MAX_VERTICES] = {1, 0, 0, 1, 0};

    cargarDigrafo(DG, &N);
    Dijkstra(DG, N, 'A', D, P, VV);
    mostrarD(D, N);
    mostrarP(P, N);

    return 0;
}

void cargarDigrafo(unsigned int DG[][MAX_VERTICES], unsigned int *N)
{
    unsigned int i, j;
    FILE *archivo;
    archivo = fopen("matriz.txt", "rt");
    fscanf(archivo, "%u", N);
    for (i = 0; i < *N; i++)
        for (j = 0; j < *N; j++)
            fscanf(archivo, "%d", &DG[i][j]);
    fclose(archivo);
}

short int todosVisitados(short int VV[], unsigned int N)
{
    unsigned int i = 0;
    while (i < N && VV[i])
        i++;
    return i == N;
}

void Dijkstra(unsigned int DG[][MAX_VERTICES], unsigned int N, char origen, unsigned int D[], char P[], short int VV[])
{
    unsigned int i, k, minAux, suma;
    while (!todosVisitados(VV, N))
    {
        minAux = INF;
        for (i = 0; i < N; i++)
            if (!VV[i] && D[i] < minAux)
            {
                k = i;
                minAux = D[i];
            }
        VV[k] = 1;
        for (i = 0; i < N; i++)
            if (!VV[i] && DG[k][i])
            {
                suma = D[k] + DG[k][i];
                if (suma < D[i])
                {
                    D[i] = suma;
                    P[i] = k + 65;
                }
            }
    }
}

void mostrarD(unsigned int D[], unsigned int N)
{
    unsigned int i;
    printf("Vector D: ");
    for (i = 0; i < N; i++)
        printf("%u ", D[i]);
    printf("\n");
}

void mostrarP(char P[], unsigned int N)
{
    unsigned int i;
    printf("Vector P: ");
    for (i = 0; i < N; i++)
        if (P[i] == 0)
            printf("%d ", P[i]);
        else
            printf("%c ", P[i]);
    printf("\n");
}