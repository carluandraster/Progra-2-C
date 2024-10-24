#include <stdio.h>
#define MAX_VERTICES 10

typedef unsigned short int byte;

void cargarGrafo(byte A[][MAX_VERTICES],byte *N);
byte grado(byte A[][MAX_VERTICES],byte N, byte vertice);
void generarVector(byte A[][MAX_VERTICES],byte N,byte GRADOS[]);
void imprimirVector(byte GRADOS[],byte N);

int main()
{
    byte A[MAX_VERTICES][MAX_VERTICES],N,GRADOS[MAX_VERTICES];

    cargarGrafo(A,&N);
    generarVector(A,N,GRADOS);
    imprimirVector(GRADOS,N);

    return 0;
}

void cargarGrafo(byte A[MAX_VERTICES][MAX_VERTICES], byte *N)
{
    byte i, j;
    FILE *archivo;

    archivo = fopen("../matriz.txt", "rt");
    fscanf(archivo, "%hu", N);
    for (i = 0; i < *N; i++)
        for (j = 0; j < *N; j++)
            fscanf(archivo, "%hu", &A[i][j]);
    fclose(archivo);
}

byte grado(byte A[][MAX_VERTICES],byte N, byte vertice){
    if (N == 0)
        return 0;
    else
        if (N-1 == vertice)
            return A[N-1][N-1]+grado(A,N-1,vertice);
        else
            return A[N-1][vertice]+A[vertice][N-1]+grado(A,N-1,vertice);
}

void generarVector(byte A[][MAX_VERTICES],byte N,byte GRADOS[]){
    if (N>0)
    {
        GRADOS[N-1] = grado(A,N,N-1);
        generarVector(A,N-1,GRADOS);
    }
}

void imprimirVector(byte GRADOS[],byte N){
    byte i;
    for (i = 0; i < N; i++)
        printf("%hu\n",GRADOS[i]);
}