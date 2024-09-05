#include <stdio.h>
#define MAXELEM 255

// Prototipos
void cargarVector (int [MAXELEM], unsigned int *);
int maximo (int [MAXELEM], unsigned int);

short int main(){
    int VECTOR [MAXELEM];
    unsigned int N;
    cargarVector(VECTOR,&N);
    printf("Valor maximo del vector: %d",maximo(VECTOR,N));
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

int maximo (int VECTOR[MAXELEM], unsigned int N){
    if (N == 1 || VECTOR[N-1]>maximo(VECTOR,N-1))
        return VECTOR[N-1];
    else
        return maximo(VECTOR,N-1);
}