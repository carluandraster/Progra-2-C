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
void generarVector (TR [MAXELEM*MAXELEM], unsigned int *);
void mostrarVector (TR [MAXELEM*MAXELEM], unsigned int);

byte main(){
    // Declaracion de variables
    int MATRIZ[MAXELEM][MAXELEM], N,M;
    TR VECTOR [MAXELEM*MAXELEM];
    unsigned int K;

    // Seccion ejecutable
    ingresarMatriz(MATRIZ,&N,&M);
    generarVector(VECTOR,&K);
    mostrarVector(VECTOR,K);

    return 0;
}

void ingresarMatriz (int MATRIZ[MAXELEM][MAXELEM], byte *N, byte *M){
    byte i,j;
    
}