#include <stdio.h>
#define MAXVERTICES 20

typedef unsigned short int byte;

void cargarMatriz(byte A[MAXVERTICES][MAXVERTICES], byte *N);
byte gradoEntrada(byte vertice, byte A[MAXVERTICES][MAXVERTICES], byte N);
byte gradoSalida(byte vertice, byte A[MAXVERTICES][MAXVERTICES], byte N);
byte grado(byte vertice, byte A[MAXVERTICES][MAXVERTICES], byte N);

int main()
{
    byte A[MAXVERTICES][MAXVERTICES], N, vertice;

    cargarMatriz(A, &N);
    do
    {
        printf("Ingrese un vertice: ");
        scanf("%hu", &vertice);
    } while (vertice >= N);
    printf("Grado de entrada: %hu\n", gradoEntrada(vertice, A, N));
    printf("Grado de salida: %hu\n", gradoSalida(vertice, A, N));
    printf("Grado del vertice: %hu\n", grado(vertice, A, N));

    return 0;
}

void cargarMatriz(byte A[MAXVERTICES][MAXVERTICES], byte *N)
{
    byte i, j;
    FILE *archivo;

    archivo = fopen("matriz.txt", "rt");
    fscanf(archivo, "%hu", N);
    for (i = 0; i < *N; i++)
        for (j = 0; j < *N; j++)
            fscanf(archivo, "%hu", &A[i][j]);
    fclose(archivo);
}

byte gradoEntrada(byte vertice, byte A[MAXVERTICES][MAXVERTICES], byte N)
{
    byte i, contador = 0;
    for (i = 0; i < N; i++)
        contador += A[i][vertice] != 0;
    return contador;
}

byte gradoSalida(byte vertice, byte A[MAXVERTICES][MAXVERTICES], byte N)
{
    byte i, contador = 0;
    for (i = 0; i < N; i++)
        contador += A[vertice][i] != 0;
    return contador;
}

byte grado(byte vertice, byte A[MAXVERTICES][MAXVERTICES], byte N)
{
    return gradoEntrada(vertice, A, N) + gradoSalida(vertice, A, N) - (A[vertice][vertice] != 0);
}