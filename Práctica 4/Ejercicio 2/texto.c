#include "texto.h"
#include <stdlib.h>

texto crear(char *c){
    texto aux;
    unsigned i = 0;
    while (c[i] != '\0')
        i++;
    aux.N = i;
    aux.cadena = (char *) malloc(aux.N * sizeof(char));
    for (i = 0; i < aux.N; i++)
        aux.cadena[i] = c[i];
    return aux;
}

void destruir(texto t){
    free(t.cadena);
}

unsigned tamanio (texto t){
    return t.N;
}

void imprimir(texto t){
    unsigned i;
    printf("%u\n",t.N);
    for (i = 0; i < t.N; i++)
        printf("%c",t.cadena[i]);
}

void imprimirArch(texto t,FILE *arch){
    unsigned i;
    for (i = 0; i < t.N; i++)
        fprintf(arch,"%c",t.cadena[i]);
}

char caracterEn(texto t, unsigned posicion){
    return t.cadena[posicion];
}

texto concatenar (texto t1,texto t2){
    texto aux;
    aux.cadena = (char *) malloc (sizeof(char)*(t1.N+t2.N));
    aux.N = t1.N+t2.N;
    unsigned i;
    for (i = 0; i < t1.N; i++)
        aux.cadena[i] = t1.cadena[i];
    for (i = 0; i < t2.N; i++)
        aux.cadena[i+t1.N] = t2.cadena[i];
    return aux;
}

texto reemplazar(texto T, char caracter, char nuevoCaracter){
    unsigned i;
    for (i = 0; i < T.N; i++)
        if (T.cadena[i] == caracter)
            T.cadena[i] = nuevoCaracter;
    return T;
}

texto subTexto(texto T,unsigned desde,unsigned hasta){
    unsigned i;
    texto aux;
    aux.N = hasta - desde;
    for (i = desde; i < hasta; i++)
        aux.cadena[i-desde] = T.cadena[i];
    return aux;
}

short comienzaCon(texto T, texto prefijo){
    unsigned i = 0;
    while (i<prefijo.N && T.cadena[i] == prefijo.cadena[i])
        i++;
    return i == prefijo.N;
}

short terminaCon (texto T,texto sufijo){
    unsigned i = 0;
    while (i<sufijo.N && T.cadena[T.N-i] == sufijo.cadena[sufijo.N-1])
        i++;
    return i == sufijo.N;
}