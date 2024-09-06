#include <stdio.h>
#define MAXELEM 200

void cargarArreglo (float [MAXELEM],unsigned *);
int buscar (float,float [MAXELEM],unsigned,unsigned);

short main(){
    float VECTOR[MAXELEM],X;
    unsigned int N;
    int busqueda;
    cargarArreglo(VECTOR,&N);
    printf("Buscar un numero: ");
    scanf("%f",&X);
    busqueda = buscar(X,VECTOR,0,N-1);
    if (busqueda == -1)
        printf("No se encontro %5.2f en el arreglo.",X);
    else
        printf("%5.2f se encuentra en la posicion %u",X,busqueda+1);
    return 0;
}

void cargarArreglo (float VECTOR[MAXELEM],unsigned *N){
    FILE *archivo;
    unsigned i,j;
    float numero;
    archivo = fopen("./../vector.txt","rt");
    *N = 0;
    if (archivo == NULL)
        printf("No se ha podido abrir el archivo correctamente");
    else
    {
        while (fscanf(archivo,"%f",&numero) == 1)
        {
            ++*N;
            i = 0;
            while (i<*N-1 && numero>VECTOR[i])
                i++;
            for (j = *N; j>i; j--)
                VECTOR[j] = VECTOR[j-1];
            VECTOR[i] = numero;
        }
        fclose(archivo);
    }
}

int buscar (float X,float VECTOR[MAXELEM],unsigned limInf, unsigned limSup){
    unsigned promedio;
    if (limInf == limSup-1)
        if (VECTOR[limSup] == X)
            return limSup;
        else
        {
            if (VECTOR[limInf] == X)
                return limInf;
            else
                return -1;
        }
    else
    {
        promedio = (limInf+limSup)/2;
        if (VECTOR[promedio] == X)
            return promedio;
        else
            if (X > VECTOR[promedio])
                return buscar(X,VECTOR,promedio,limSup);
            else
                return buscar(X,VECTOR,limInf,promedio);
    }
}