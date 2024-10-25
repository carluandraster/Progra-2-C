#include <stdio.h>
#define MAX_VERTICES 10

typedef unsigned short int byte;

void cargarGrafo(byte A[][MAX_VERTICES],byte *N);
byte cumple(byte A[][MAX_VERTICES],int i, byte j,byte vertice, byte N, byte x);

int main()
{
    byte A[MAX_VERTICES][MAX_VERTICES],N,X;
    cargarGrafo(A,&N);
    printf("Ingrese un costo X: ");
    scanf("%hu",&X);
    printf(cumple(A,N-1,N-1,N-1,N,X) ? "Todos los vertices del grafo tienen al menos un vertice adyacente con costo mayor a X.\n" : "Existen vertices en el grafo que no tiene vertices adyacentes con costo mayor a X.\n");
    return 0;
}

void cargarGrafo(byte A[][MAX_VERTICES],byte *N){
    byte i,j;
    FILE *archivo;

    archivo = fopen("media_matriz.txt","rt");
    fscanf(archivo,"%hu",N);
    for (i = 0; i < *N; i++)
        for (j = i; j < *N; j++)
            fscanf(archivo,"%hu",&A[i][j]);
    fclose(archivo);
}

byte cumple(byte A[][MAX_VERTICES],int i, byte j,byte vertice, byte N, byte x){
    if (i < 0)
        return 0;
    else
        if (A[i][j] > x)
            if (vertice == 0)
                return 1;
            else
                return cumple(A,vertice-1,N-1,vertice-1,N,x);
        else
            if (vertice == j)
                return cumple(A,i-1,j,vertice,N,x);
            else
                return cumple(A,i,j-1,vertice,N,x);
}