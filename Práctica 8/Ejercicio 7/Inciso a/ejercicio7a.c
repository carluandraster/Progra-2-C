#include <stdio.h>
#define MAX_VERTICES 10

typedef unsigned short int byte;

void cargarGrafo(byte A[][MAX_VERTICES],byte *N);
byte grado(byte A[][MAX_VERTICES],byte N,byte vertice);

int main()
{
    byte A[MAX_VERTICES][MAX_VERTICES],N,vertice;

    cargarGrafo(A,&N);
    do
    {
        printf("Ingrese un vertice: ");
        scanf("%hu",&vertice);
    } while (vertice >= N);
    printf("Grado del vertice: %hu",grado(A,N,vertice));
    
    return 0;
}

void cargarGrafo(byte A[MAX_VERTICES][MAX_VERTICES], byte *N)
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

byte grado(byte A[MAX_VERTICES][MAX_VERTICES],byte N,byte vertice){
    byte i,contador = 0;
    for (i = 0; i < N; i++)
        if (i == vertice)
            contador += A[i][i];
        else
            contador += A[i][vertice]+A[vertice][i];
    return contador;
}