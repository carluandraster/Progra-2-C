#include <stdio.h>
#include "../Ejercicio 01/Inciso b/pilaDinamica.h"
#define MASINFINITO 32000
#define MENOSINFINITO -32000

void cargarPila(TPila *P);
unsigned contar0 (TPila P);
float promedio(TPila P);
void extremos(TPila P, TElementoP *minimo, TElementoP *maximo);
void quitarMayores(TPila *P);

int main(){
    TPila P;
    TElementoP minimo,maximo;

    cargarPila(&P);
    printf("Cantidad de 0s que tiene la pila: %u\n",contar0(P));
    printf("Promedio: %5.2f\n",promedio(P));
    extremos(P,&minimo,&maximo);
    printf("Minimo: %d\n",minimo);
    printf("Maximo: %d\n",maximo);
    quitarMayores(&P);

    return 0;
}

void cargarPila(TPila *P){
    TElementoP x;
    FILE *archivo;
    archivo = fopen("numeros_enteros.txt","rt");
    while (fscanf(archivo,"%d",&x)==1)
        poneP(P,x);
    fclose(archivo);
}

unsigned contar0 (TPila P){
    TElementoP x;
    unsigned contador = 0;
    while (!VaciaP(P))
    {
        sacaP(&P,&x);
        contador+=x==0;
    }
    return contador;
}

float promedio(TPila P){
    int acumulador = 0,contador=0;
    TElementoP x;
    while (!VaciaP(P))
    {
        sacaP(&P,&x);
        contador++;
        acumulador+=x;
    }
    return (float) acumulador/contador;
}

void extremos(TPila P, TElementoP *minimo, TElementoP *maximo){
    TElementoP x;
    *minimo = MASINFINITO;
    *maximo = MENOSINFINITO;
    while (!VaciaP(P))
    {
        sacaP(&P,&x);
        if (x<*minimo)
            *minimo = x;
        if (x>*maximo)
            *maximo = x;
    }
}