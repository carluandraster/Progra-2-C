#include <stdio.h>
#include "../../Ejercicio 01/Inciso d/colaDinamica.h"

void cargarCola(TCola *C);
void mostrarCola(TCola *C);

int main(){
    TCola C;
    IniciaC(&C);
    cargarCola(&C);
    mostrarCola(&C);
    return 0;
}

void cargarCola(TCola *C){
    FILE *archivo;
    TElementoC x;
    archivo = fopen("../numeros_enteros.txt","rt");
    while (fscanf(archivo,"%d",&x)==1)
        poneC(C,x);
    fclose(archivo);
}

void mostrarCola(TCola *C){
    TCola aux;
    TElementoC x;
    IniciaC(&aux);
    while (!VaciaC(*C))
    {
        sacaC(C,&x);
        poneC(&aux,x);
        printf("%d\n",x);
    } 
    while (!VaciaC(aux))
    {
        sacaC(&aux,&x);
        poneC(C,x);
    }
}