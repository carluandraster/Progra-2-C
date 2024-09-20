#include <stdio.h>
#include "texto.h"
#define MAXELEM 1000

int main(){
    texto T,prefijo,sufijo,T2,T3;
    unsigned num;
    char A[MAXELEM];
    FILE *archivo;
    printf("Ingrese un texto: \n");
    scanf(" %s",A);
    T = crear(A);
    printf("Tamanio del texto: %u\n",tamanio(T));
    imprimir(T);
    archivo = fopen("archivo.txt","wt");
    imprimirArch(T,archivo);
    fclose(archivo);
    printf("\nIngrese una posicion: ");
    scanf("%u",&num);
    printf("%c\n",caracterEn(T,num));
    printf("Ingrese otro texto: \n");
    scanf(" %s",A);
    T2 = crear(A);
    T3 = concatenar(T,T2);
    imprimir(T3);
    printf("%s\n",reemplazar(T,'A','O'));
    printf("%s\n",subTexto(T,3,7));
    printf("Ingrese prefijo: \n");
    scanf(" %s",A);
    prefijo = crear(A);
    printf("%d\n",comienzaCon(T,prefijo));
    printf("Ingrese sufijo: \n");
    scanf(" %s",A);
    sufijo = crear(A);
    printf("%d\n",terminaCon(T,sufijo));
    destruir(T);
    destruir(prefijo);
    destruir(sufijo);
    destruir(T2);
    destruir(T3);
    return 0;
}