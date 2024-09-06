#include <stdio.h>
#define MAXELEM 200

void cargarArreglo (float [MAXELEM],unsigned *);
int buscar (float,float [MAXELEM],unsigned);

short main(){
    float VECTOR[MAXELEM],X;
    unsigned int N;
    int busqueda;
    cargarArreglo(VECTOR,&N);
    printf("Buscar un numero: ");
    scanf("%f",&X);
    busqueda = buscar(X,VECTOR,N);
    if (busqueda == -1)
        printf("No se encontro %5.2f en el arreglo.",X);
    else
        printf("%5.2f se encuentra en la posicion %u",X,busqueda+1);
    return 0;
}

void cargarArreglo (float VECTOR[MAXELEM],unsigned *N){
    FILE *archivo;
    archivo = fopen("./../vector.txt","rt");
    *N = 0;
    if (archivo == NULL)
        printf("Ocurrio un error al abrir el archivo.\n");
    else
    {
        while (fscanf(archivo,"%f",&VECTOR[*N]) == 1)
            ++*N;
        fclose(archivo);
    }
}

int buscar (float X,float VECTOR[MAXELEM],unsigned N){
    return N == 0 || VECTOR[N-1] == X ? N-1 : buscar(X,VECTOR,N-1);
}