/*Desarrollar un subprograma que muestre un cuadrado con bordes de N numerales (N es
parámetro de entrada).*/

#include <stdio.h>

void cuadrado(unsigned short int N);

int main()
{
    unsigned short int N;
    printf("Ingrese dimension del cuadrado: ");
    scanf(" %d", &N);
    cuadrado(N);
    return 0;
}

void cuadrado(unsigned short int N)
{
    int i, j;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
            printf(i == 1 || j == 1 || i == N || j == N ? "#" : " ");
        printf("\n");
    }
}