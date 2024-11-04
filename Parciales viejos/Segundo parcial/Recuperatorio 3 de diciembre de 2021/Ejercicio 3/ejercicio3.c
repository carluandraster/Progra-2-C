#include <stdio.h>
#define MAX_VERTICES 20

typedef struct
{
    int vertice;
    float promedio;
} TRegistro;

void cargarGrafo(int DG[][MAX_VERTICES], int *N);
void generarArreglo(int DG[][MAX_VERTICES], int N, TRegistro V[], int *M);
void mostrarArreglo(TRegistro V[], int M);

int main()
{
    int DG[MAX_VERTICES][MAX_VERTICES], N, M = 0;
    TRegistro V[MAX_VERTICES];
    cargarGrafo(DG, &N);
    generarArreglo(DG, N, V, &M);
    mostrarArreglo(V, M);
    return 0;
}

// Carga el digrafo DG desde archivo
void cargarGrafo(int DG[][MAX_VERTICES], int *N)
{
    int i, j;
    FILE *archivo;
    archivo = fopen("matriz.txt", "rt");
    fscanf(archivo, "%d", N);
    for (i = 0; i < *N; i++)
        for (j = 0; j < *N; j++)
            fscanf(archivo, "%d", &DG[i][j]);
    fclose(archivo);
}

void generarArreglo(int DG[][MAX_VERTICES], int N, TRegistro V[], int *M)
{
    int GR_SALIDAS[N], GR_ENTRADAS[N], i, j;

    // Inicializar vectores
    for (i = 0; i < N; i++)
        GR_ENTRADAS[i] = GR_SALIDAS[i] = 0;

    // Recorrer matriz
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            GR_SALIDAS[i] += DG[i][j];
            GR_ENTRADAS[j] += DG[i][j];
        }

    // Generar arreglo
    for (i = 0; i < N; i++)
        if (GR_SALIDAS[i] < GR_ENTRADAS[i])
        {
            V[*M].vertice = 65 + i;
            V[*M].promedio = (GR_SALIDAS[i] + GR_ENTRADAS[i]) / 2.0;
            ++*M;
        }
}

void mostrarArreglo(TRegistro V[], int M)
{
    int i;
    printf("Vertice Promedio\n");
    for (i = 0; i < M; i++)
        printf("%c \t %5.2f\n", V[i].vertice, V[i].promedio);
}