#include <stdio.h>
#include <stdlib.h>
#define MAXELEM 20

void ingresarMatriz(int [MAXELEM][MAXELEM], unsigned *);
short esSimetrica(int [MAXELEM][MAXELEM],unsigned,unsigned,unsigned);

short main(){
    int MATRIZ[MAXELEM][MAXELEM];
    unsigned N;

    ingresarMatriz(MATRIZ,&N);
    printf(esSimetrica(MATRIZ,N,N-2,N-1) ? "La matriz es simetrica.\n" : "La matriz no es simetrica.\n");
    
    return 0;
}

void ingresarMatriz(int MATRIZ[MAXELEM][MAXELEM], unsigned *N){
    FILE *archivo;
    unsigned i,j;
    archivo = fopen("matriz.txt","rt");
    if (archivo == NULL)
        printf("No se pudo abrir el archivo correctamente.\n");
    else
    {
        fscanf(archivo,"%u",N);
        for (i = 0; i < *N; i++)
            for (j = 0; j < *N; j++)
                fscanf(archivo,"%d",&MATRIZ[i][j]);
        fclose(archivo);
    }
}

short esSimetrica(int MATRIZ[MAXELEM][MAXELEM],unsigned N,unsigned i,unsigned j){
    if (i == 0 && j == 0)
        return 1;
    else 
        if (i == j)
            return esSimetrica(MATRIZ,N,i-1,N-1);
        else
            if (MATRIZ[i][j] == MATRIZ[j][i])
                return esSimetrica(MATRIZ,N,i,j-1);
            else
                return 0;
}