// Preprocesador
#include <stdio.h>
#define MAXELEM 20

// Definicion de tipos
typedef unsigned short int byte;
typedef struct
{
    byte fila,columna;
    int valor;
} TR;

// Prototipos
void ingresarMatriz (int [MAXELEM][MAXELEM], byte *, byte *);
void generarVector (int [MAXELEM][MAXELEM], byte , byte ,TR [MAXELEM*MAXELEM], unsigned int *);
void mostrarVector (TR [MAXELEM*MAXELEM], unsigned int);

byte main(){
    // Declaracion de variables
    int MATRIZ[MAXELEM][MAXELEM];
    TR VECTOR [MAXELEM*MAXELEM];
    unsigned int K;
    byte N,M;

    // Seccion ejecutable
    ingresarMatriz(MATRIZ,&N,&M);
    generarVector(MATRIZ,N,M,VECTOR,&K);
    mostrarVector(VECTOR,K);

    return 0;
}

void ingresarMatriz (int MATRIZ[MAXELEM][MAXELEM], byte *N, byte *M){
    byte i,j;
    FILE *archivo;
    archivo = fopen("matriz.txt","rt");
    if (archivo == NULL)
        printf("Error al abrir el archivo matriz.txt");
    else{
        fscanf(archivo,"%hu %hu",N,M);
        for (i = 0; i < *N; i++)
            for (j = 0; j < *M; j++)
                fscanf(archivo,"%d",&MATRIZ[i][j]);
        fclose(archivo);
    }
}

void generarVector (int MATRIZ[MAXELEM][MAXELEM], byte N, byte M,TR VECTOR[MAXELEM*MAXELEM], unsigned int *K){
    byte i,j;
    *K=0;
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            if (MATRIZ[i][j]%(N+M) == 0)
            {
                VECTOR[*K].fila = i;
                VECTOR[*K].columna = j;
                VECTOR[*K].valor = MATRIZ[i][j];
                ++*K;
            }
}

void mostrarVector (TR VECTOR[MAXELEM*MAXELEM], unsigned int K){
    byte i;
    printf("Fila \t Columna \t Valor\n");
    for (i = 0; i < K; i++)
        printf(" %hu \t    %hu \t\t   %d\n",VECTOR[i].fila+1,VECTOR[i].columna+1,VECTOR[i].valor);
}