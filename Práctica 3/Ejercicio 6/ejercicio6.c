#include <stdio.h>
#include <stdlib.h>
#define MAXELEM 20
#define INFINITO 32768

void ingresarMatriz(int [MAXELEM][MAXELEM], unsigned *, unsigned *);
short cumple(int [MAXELEM][MAXELEM], unsigned, unsigned,unsigned, int,int);

short main(){
    int MATRIZ[MAXELEM][MAXELEM];
    unsigned N,M;

    ingresarMatriz(MATRIZ,&N,&M);
    printf(cumple(MATRIZ,N,M,M,INFINITO,0) ? "La matriz cumple con las condiciones.\n" : "La matriz no cumple con las condiciones.\n");

    return 0;
}

void ingresarMatriz(int A[MAXELEM][MAXELEM], unsigned *N, unsigned *M)
{
    FILE *archivo;
    unsigned i, j;
    archivo = fopen("matriz.txt", "rt");
    if (archivo == NULL)
        printf("El archivo no se pudo abrir correctamente\n");
    else
    {
        fscanf(archivo, "%u %u", N, M);
        for (i = 0; i < *N; i++)
            for (j = 0; j < *M; j++)
                fscanf(archivo, "%d", &A[i][j]);
        fclose(archivo);
    }    
}

short cumple(int MATRIZ[MAXELEM][MAXELEM], unsigned N, unsigned M,unsigned j, int sumPos,int sumAnt){
    if (N == 0)
        return sumPos % 2 == 0;
    else if (j == 0)
        return sumPos>sumAnt ? cumple(MATRIZ,N-1,M,M,sumAnt,0) : 0;
    else
        cumple(MATRIZ,N,M,j-1,sumPos,sumAnt+MATRIZ[N-1][j-1]);
}