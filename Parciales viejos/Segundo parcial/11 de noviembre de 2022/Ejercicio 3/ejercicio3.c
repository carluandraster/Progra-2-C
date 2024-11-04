#include <stdio.h>
#define MAX_VERTICES 20

void cargarGrafos(int Ady[][MAX_VERTICES], int *N);
int esSubgrafo(int Ady[][MAX_VERTICES], int N);

int main()
{
    int Ady[MAX_VERTICES][MAX_VERTICES], N;
    cargarGrafos(Ady, &N);
    printf(esSubgrafo(Ady, N) ? "G' es subgrafo de G.\n" : "G' no es subgrafo de G.\n");
    return 0;
}

void cargarGrafos(int Ady[][MAX_VERTICES], int *N)
{
    unsigned int i, j;
    FILE *archivo;
    archivo = fopen("matriz.txt", "rt");
    fscanf(archivo, "%u", N);
    for (i = 0; i < *N; i++)
        for (j = 0; j < *N; j++)
            fscanf(archivo, "%d", &Ady[i][j]);
    fclose(archivo);
}

int esSubgrafo(int Ady[][MAX_VERTICES], int N)
{
    int i = 0, j = 1;
    while (i < N && (!Ady[i][j] || Ady[j][i])) // p=>q <=> -p v q
    {
        while (j < N && (!Ady[i][j] || Ady[j][i]))
            j++;
        if (j == N)
        {
            i++;
            j = i + 1;
        }
    }
    return i == N;
}