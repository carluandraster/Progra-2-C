#include <stdio.h>
#define MAX_VERTICES 10

typedef struct
{
    unsigned int vertice, grSalida;
} TRegistro;

void cargarDigrafo(unsigned int DG[][MAX_VERTICES], unsigned int *N);
void generarArreglo(unsigned int DG[][MAX_VERTICES], unsigned int N, unsigned int i, unsigned j, TRegistro V[], unsigned int *M);
void mostrarVector(TRegistro V[], unsigned int M);

int main()
{
    unsigned int DG[MAX_VERTICES][MAX_VERTICES], N, M = 0;
    TRegistro V[MAX_VERTICES];

    cargarDigrafo(DG, &N);
    generarArreglo(DG, N, 0, 0, V, &M);
    mostrarVector(V, M);

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

void generarArreglo(unsigned int DG[][MAX_VERTICES], unsigned int N, unsigned int i, unsigned j, TRegistro V[], unsigned int *M)
{
    if (i < N)
    {
        if (j == 0 && DG[i][i])
        {

            ++*M;
            V[*M - 1].vertice = i + 1;
            V[*M - 1].grSalida = DG[i][j];
            generarArreglo(DG, N, i, j + 1, V, M);
        }
        else if (j < N && DG[i][i])
        {
            V[*M - 1].grSalida += DG[i][j];
            generarArreglo(DG, N, i, j + 1, V, M);
        }
        else
            generarArreglo(DG, N, i + 1, 0, V, M);
    }
}

void mostrarVector(TRegistro V[], unsigned int M)
{
    unsigned int i;
    printf("Vertice Grado de salida\n");
    for (i = 0; i < M; i++)
        printf("%u\t\t%u\n", V[i].vertice, V[i].grSalida);
}