#include <stdio.h>
#define MAX_VERTICES 10

void cargarMatrizAlcance(short int ALC[][MAX_VERTICES], unsigned int *N);
void inicializarVector(unsigned int V[], unsigned int N);
void recorrerMatriz(short int ALC[][MAX_VERTICES], unsigned int N, unsigned int i, unsigned int j, short int BUCLES[], unsigned int ALCANZANTES[], unsigned int ALCANZABLES[]);
unsigned int contarSi(short int BUCLES[], unsigned int ALCANZANTES[], unsigned int ALCANZABLES[], unsigned int N);

int main()
{
    short int ALC[MAX_VERTICES][MAX_VERTICES], BUCLES[MAX_VERTICES];
    unsigned int ALCANZANTES[MAX_VERTICES], ALCANZABLES[MAX_VERTICES], N;

    // Inicializaciones
    cargarMatrizAlcance(ALC, &N);
    inicializarVector(ALCANZABLES, N);
    inicializarVector(ALCANZANTES, N);

    // Contar nodos
    recorrerMatriz(ALC, N, 0, 0, BUCLES, ALCANZANTES, ALCANZABLES);
    printf("Cantidad de nodos que, sin tener bucle, son alcanzados y alcanzan la misma cantidad de vertices: %u\n", contarSi(BUCLES, ALCANZANTES, ALCANZABLES, N));

    return 0;
}

void cargarMatrizAlcance(short int ALC[][MAX_VERTICES], unsigned int *N)
{
    unsigned int i, j;
    FILE *archivo;
    archivo = fopen("matriz.txt", "rt");
    fscanf(archivo, "%u", N);
    for (i = 0; i < *N; i++)
        for (j = 0; j < *N; j++)
            fscanf(archivo, "%d", &ALC[i][j]);
    fclose(archivo);
}

void inicializarVector(unsigned int V[], unsigned int N)
{
    unsigned int i;
    for (i = 0; i < N; i++)
        V[i] = 0;
}

// Sugerencia: 3 vectores recorriendo una sola vez la matriz en forma recursiva
// Un vector que diga si un vertice tiene bucle
// Otro vector que tenga la cantidad de vertices que alcanzan a los vertices (Alcanzantes)
// Otro vector que tenga la cantidad de vertices alcanzables desde los vertices (Alcanzables)

void recorrerMatriz(short int ALC[][MAX_VERTICES], unsigned int N, unsigned int i, unsigned int j, short int BUCLES[], unsigned int ALCANZANTES[], unsigned int ALCANZABLES[])
{
    if (i < N)
        if (i == j)
        {
            BUCLES[i] = ALC[i][j];
            recorrerMatriz(ALC, N, i, j + 1, BUCLES, ALCANZANTES, ALCANZABLES);
        }
        else if (j == N)
            recorrerMatriz(ALC, N, i + 1, 0, BUCLES, ALCANZANTES, ALCANZABLES);
        else
        {
            ALCANZANTES[j] += ALC[i][j];
            ALCANZABLES[i] += ALC[i][j];
            recorrerMatriz(ALC, N, i, j + 1, BUCLES, ALCANZANTES, ALCANZABLES);
        }
}

unsigned int contarSi(short int BUCLES[], unsigned int ALCANZANTES[], unsigned int ALCANZABLES[], unsigned int N)
{
    unsigned int i, contador = 0;
    for (i = 0; i < N; i++)
        contador += !BUCLES[i] && ALCANZANTES[i] == ALCANZABLES[i];
    return contador;
}