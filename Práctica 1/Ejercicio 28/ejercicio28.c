#include <stdio.h>

typedef unsigned int natural;

short int main(){
    natural suma = 0,numero;
    FILE *archivo;
    archivo = fopen("numeros.txt","rt");
    if (archivo == NULL)
    {
        printf("No se pudo leer el archivo correctamente");
    }
    else{
        while (! feof(archivo))
        {
            fscanf(archivo,"%u",&numero);
            suma+=numero;
        }
        fclose(archivo);
        printf("Sumatoria de todos los numeros del archivo: %u",suma);
    }
    return 0;
}

/* Da lo mismo si los numeros estan puestos en la misma linea o no porque C cuando lee
un numero de un archivo, le da lo mismo si los numeros estan separados por espacios o
por saltos de linea sino que cada vez que tiene que leer un numero avanza hasta encontrar uno*/