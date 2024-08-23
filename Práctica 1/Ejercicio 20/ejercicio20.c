/*Realizar un programa iterativo que calcule e imprima el equivalente binario de un número
entero positivo dado. */

// Librerías
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    // Declaración de variables
    unsigned int a;
    unsigned short int N;
    short int i;
    short int *V;
    
    // Entrada
    printf("Ingrese un numero: ");
    scanf("%u",&a);

    // Procesamiento
    N = a!=0 ? floor(log2(a)+1): 1;
    V = (short int *) malloc(sizeof(int)*N);
    for (i = N-1; i >= 0; i--)
    {
        V[i] = a%2;
        a/=2;
    }

    // Salida
    printf("Representante binario: ");
    for (i = 0; i < N; i++)
       printf("%d",V[i]);

    free(V);
    return 0;
}