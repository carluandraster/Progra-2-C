#include <stdio.h>
#include "pilaDinamica.h"

void cargarPila (TPila *P);
void mostrarPila (TPila *P);

int main(){
    TPila P;
    IniciaP(&P);
    cargarPila(&P);
    mostrarPila(&P);
    return 0;
}

void cargarPila (TPila *P){
    TElementoP x;
    FILE *archivo;
    archivo = fopen("./../caracteres.txt","rt");
    while (fscanf(archivo," %c",&x) == 1)
        poneP(P,x);
    fclose(archivo);
}

void mostrarPila (TPila *P){
    TElementoP x;
    while (!VaciaP(*P))
    {
        sacaP(P,&x);
        printf("%c\n",x);
    }   
}