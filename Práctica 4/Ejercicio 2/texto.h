#include <stdio.h>

// Implementacion estatica
// #define MAXELEM 1000
// typedef struct
// {
//     char cadena[MAXELEM];
//     unsigned N;
// } texto;


// Implementacion dinamica
typedef struct
{
    char *cadena;
    unsigned N;
} texto;

texto crear(char *c);
void destruir(texto t);
unsigned tamanio (texto t);
void imprimir(texto t);
void imprimirArch(texto t,FILE *arch);
char caracterEn(texto t, unsigned posicion);
texto concatenar (texto t1,texto t2);
texto reemplazar(texto T, char caracter, char nuevoCaracter);
texto subTexto(texto T,unsigned desde,unsigned hasta);
short comienzaCon(texto T, texto prefijo);
short terminaCon (texto T,texto sufijo);