#include <stdio.h>
#define MAX_VERTICES 10

void cargarMatriz(short int R[][MAX_VERTICES],unsigned int *N);
void encontrarMax(short int R[][MAX_VERTICES],unsigned int N,unsigned int i, unsigned int j,unsigned int suma,unsigned int maximo,char *maxVertice);

int main()
{
    short int R[MAX_VERTICES][MAX_VERTICES];
    unsigned int N;
    char maxVertice;

    cargarMatriz(R,&N);
    encontrarMax(R,N,0,0,0,0,&maxVertice);
    printf("Vertice mas alcanzado: %c\n",maxVertice);

    return 0;
}

void cargarMatriz(short int R[][MAX_VERTICES],unsigned int *N){
    unsigned int i, j;
    FILE *archivo;
    archivo = fopen("matriz.txt", "rt");
    fscanf(archivo, "%u", N);
    for (i = 0; i < *N; i++)
        for (j = 0; j < *N; j++)
            fscanf(archivo, "%u", &R[i][j]);
    fclose(archivo);
}

void encontrarMax(short int R[][MAX_VERTICES],unsigned int N,unsigned int i, unsigned int j,unsigned int suma,unsigned int maximo,char *maxVertice){
    if (j<N)
        if (i == N)
        {
            if (suma > maximo)
            {
                maximo = suma;
                *maxVertice = j+65;
            }
            encontrarMax(R,N,0,j+1,0,maximo,maxVertice);
        }
        else
            encontrarMax(R,N,i+1,j,suma + R[i][j],maximo,maxVertice);
}