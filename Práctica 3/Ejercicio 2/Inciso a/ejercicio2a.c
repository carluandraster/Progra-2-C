// Preprocesador
#include <stdio.h>
#define MAXELEM 255

// Prototipos
void cargarVector (int VECTOR[MAXELEM],unsigned int *N);
int suma (int VECTOR[MAXELEM],unsigned int N);
void mostrarElementos (int VECTOR[MAXELEM],unsigned int N);
void mostrarAlReves (int VECTOR[MAXELEM],unsigned int N);

short int main(){
    int VECTOR[MAXELEM];
    unsigned int N;

    cargarVector(VECTOR,&N);
    printf("Suma de todos los elementos del vector: %d\n",suma(VECTOR,N));
    printf("Elementos del vector: ");
    mostrarElementos(VECTOR,N);
    mostrarAlReves(VECTOR,N);

    return 0;
}

void cargarVector (int VECTOR[MAXELEM], unsigned int *N){
    FILE *archivo;
    archivo = fopen("enteros.txt","rt");
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

int suma (int VECTOR[MAXELEM],unsigned int N){
    return N == 0 ? 0 : VECTOR[N-1]+suma(VECTOR,N-1);
}

void mostrarElementos (int VECTOR[MAXELEM],unsigned int N){

}