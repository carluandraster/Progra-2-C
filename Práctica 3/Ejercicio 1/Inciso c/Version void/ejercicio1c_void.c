#include <stdio.h>
#define MAXELEM 255

// Prototipos
void cargarVector (int [MAXELEM], unsigned int *);
void buscarMaximo (int [MAXELEM], unsigned int, int*);

short int main(){
    int VECTOR [MAXELEM], maximo;
    unsigned int N;
    cargarVector(VECTOR,&N);
    buscarMaximo(VECTOR,N,&maximo);
    printf("Valor maximo del vector: %d",maximo);
    return 0;
}

void cargarVector (int VECTOR[MAXELEM], unsigned int *N){
    FILE *archivo;
    archivo = fopen("./../enteros.txt","rt");
    *N = 0;
    if (archivo == NULL)
        printf("No se ha podido abrir el archivo correctamente\n");
    else
    {
        while (fscanf(archivo,"%d",&VECTOR[*N]) == 1)
            ++ *N;
        fclose(archivo);
    }
}

void buscarMaximo (int VECTOR[MAXELEM], unsigned int N, int *maximo){
    if (N == 1)
        *maximo = VECTOR[0];
    else
    {
        buscarMaximo(VECTOR,N-1,maximo);
        if (VECTOR[N-1]>*maximo)
            *maximo = VECTOR[N-1];
    }
    
}