#include <stdio.h>
#define MAX_VERTICES 10

void cargarGrafos(int G[][MAX_VERTICES], int *N);
int subgrafoDeG_prima(int G[][MAX_VERTICES], int N);
int subgrafoDeG(int G[][MAX_VERTICES], int N);

int main()
{
    int G[MAX_VERTICES][MAX_VERTICES], N;
    cargarGrafos(G, &N);
    printf(subgrafoDeG_prima(G, N) ? "G es subgrafo de G'.\n" : "G no es subgrafo de G'.\n");
    printf(subgrafoDeG(G, N) ? "G' es subgrafo de G.\n" : "G' no es subgrafo de G.\n");
    return 0;
}

// Inicializa G y G' en una misma matriz
void cargarGrafos(int G[][MAX_VERTICES], int *N)
{
    int i, j;
    FILE *archivo;
    archivo = fopen("matriz.txt", "rt");
    fscanf(archivo, "%d", N);
    for (i = 0; i < *N; i++)
        for (j = 0; j < *N; j++)
            fscanf(archivo, "%d", &G[i][j]);
    fclose(archivo);
}

// Verifica si G es subgrafo de G'
int subgrafoDeG_prima(int G[][MAX_VERTICES], int N)
{
    int i = 1, j = 0;

    // Recorrer triangulo inferior (donde se encuentra G)
    while (i < N && (!G[i][j] || G[j][i])) // p => q <=> -p v q
    {
        while (j < i && (!G[i][j] || G[j][i]))
            j++;
        if (j == i)
        {
            j = 0;
            i++;
        }
    }

    return i == N;
}

// Verifica si G' es subgrafo de G
int subgrafoDeG(int G[][MAX_VERTICES], int N)
{
    int i = 0, j = 1;

    // Recorrer triangulo superior (donde esta G')
    while (i < N - 1 && (!G[i][j] || G[j][i])) // En la fila N-ésima, ya hoa hay nada que hacer
    {
        while (j < N && (!G[i][j] || G[j][i]))
            j++;
        if (j == N)
        {
            i++;
            j = i + 1;
        }
    }

    return i == N - 1;
}