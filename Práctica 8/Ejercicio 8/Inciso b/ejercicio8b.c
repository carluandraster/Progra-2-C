#include <stdio.h>
#define MAX_VERTICES 10

typedef unsigned short int byte;

void cargarGrafo(byte A[][MAX_VERTICES],byte *N);
byte gradoEntrada(byte A[][MAX_VERTICES],byte N,byte vertice);
byte mayorGradoE(byte A[][MAX_VERTICES],byte N);

int main()
{
    byte A[MAX_VERTICES][MAX_VERTICES],N;
    cargarGrafo(A,&N);
    printf("Vertice de mayor grado de entrada: %c\n",65+mayorGradoE(A,N));
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

byte gradoEntrada(byte A[][MAX_VERTICES],byte N,byte vertice){
    if (N == 0)
        return 0;
    else
        return A[N-1][vertice] + gradoEntrada(A,N-1,vertice);
}

byte mayorGradoE(byte A[][MAX_VERTICES],byte N){
    byte maxGradoAnt,act,ant;
    if (N == 1)
        return gradoEntrada(A,N,0);
    else
    {
        ant = mayorGradoE(A,N-1);
        maxGradoAnt = gradoEntrada(A,N,ant);
        act = gradoEntrada(A,N,N-1);
        return act > maxGradoAnt ? N-1 : maxGradoAnt;
    }
}