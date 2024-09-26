#include <stdio.h>
#include "../pilaDinamica.h"

void cargarPila(TPila *P);
void mostrarVotantes(TPila *P,unsigned N);

int main(){
    TPila P;
    unsigned N;
    IniciaP(&P);
    cargarPila(&P);
    printf("Ingrese numero: ");
    scanf("%u",&N);
    mostrarVotantes(&P,N);
    return 0;
}

void cargarPila(TPila *P){
    TElementoP x;
    FILE *archivo;
    archivo = fopen("../dnis.txt","rt");
    while (fscanf(archivo,"%s",x.DNI)==1)
        poneP(P,x);
    fclose(archivo);
}

void mostrarVotantes(TPila *P,unsigned N){
    TElementoP x;
    TPila aux;
    unsigned i = 0;
    while (i<N && !VaciaP(*P))
    {
        sacaP(P,&x);
        poneP(&aux,x);
        i++;
    }
    if (i<N)
        printf("El numero que ingreso excede a la cantidad total de votantes.\n");
    while (!VaciaP(aux))
    {
        sacaP(&aux,&x);
        printf("%s\n",x.DNI);
    }
}