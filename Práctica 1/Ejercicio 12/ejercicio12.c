#include <stdio.h>

int main(){
    unsigned int nro, suma=0;
    printf("Ingrese un numero: ");
    scanf("%u",&nro);
    while (nro!=0)
    {
        suma+=nro;
        printf("Ingrese un numero: ");
        scanf("%u",&nro);
    }
    printf("Sumatoria de todos los numeros: %d",suma);
}