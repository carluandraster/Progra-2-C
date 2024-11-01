#include <stdio.h>
#define MAX_VERTICES 10

void cargarMatrizAlcance(short int ALC[][MAX_VERTICES],unsigned int *N);
unsigned int contarSi(short int ALC[][MAX_VERTICES],unsigned int N, unsigned int I, unsigned int i, unsigned int j,unsigned int suma1,unsigned int suma2);

int main()
{
    short int ALC[MAX_VERTICES][MAX_VERTICES];
    unsigned int N;
    cargarMatrizAlcance(ALC,&N);
    printf("Cantidad de nodos que, sin tener bucle, son alcanzados y alcanzan la misma cantidad de vertices: %u\n",contarSi(ALC,N,0,0,0,0,0));
    return 0;
}

void cargarMatrizAlcance(short int ALC[][MAX_VERTICES],unsigned int *N){
    unsigned int i,j;
    FILE *archivo;
    archivo = fopen("matriz.txt","rt");
    fscanf(archivo,"%u",N);
    for (i = 0; i < *N; i++)
        for (j = 0; j < *N; j++)
            fscanf(archivo,"%d",&ALC[i][j]);
    fclose(archivo);
}

// Sugerencia: 3 vectores recorriendo una sola vez la matriz en forma recursiva
// Un vector que diga si un vertice tiene bucle
// Otro vector que tenga la cantidad de vertices que alcanzan a los vertices
// Otro vector que tenga la cantidad de vertices alcanzables desde los vertices
/*
unsigned int contarSi(short int ALC[][MAX_VERTICES],unsigned int N, unsigned int I, unsigned int i, unsigned int j,unsigned int suma1,unsigned int suma2){
    if (I < N)
        if (ALC[I][I]) // Tiene ciclo
            return contarSi(ALC,N,I+1,I,0,0,0);
        else
            if (i == I)
                if (j == N)
                    return contarSi(ALC,N,I,0,I,suma1,suma2);
                else
                    return contarSi(ALC,N,I,i,j+1,suma1+ALC[i][j],suma2);
            else // j == I
                if (i == N)
                    return (suma1 == suma2) + contarSi(ALC,N,I+1,I+1,0,0,0);
                else
                    return contarSi(ALC,N,I,i+1,j,suma1,suma2+ALC[i][j]);
    else
        return 0;
}*/