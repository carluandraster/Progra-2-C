// Librerías
#include <stdio.h>
#include <stdlib.h>

// Constantes
#define MAXELEM 100

// Prototipos
void leerVector (int *,unsigned short int *);
void mostrarImpares (unsigned short int, int *);
void generarVector (int,unsigned short int,int *, int *, unsigned short int *);
void mostrarVector(int,int *);
unsigned int buscar (int, int, int*);

int main(){
    // Declaración y asignación de variables
    int *V, *W, x, k;
    unsigned short int N,M,pos;

    leerVector(V,&N);

    // Menu
    do{
        // Inciso a
        printf("Posiciones impares: ");
        mostrarImpares(N,V);

        // Inciso b
        printf("Ingrese un numero k: ");
        scanf("%d",&k);
        generarVector(k,N,V,W,&M);
        mostrarVector(M,W);

        // Inciso c
        printf("Ingrese un numero x: ");
        scanf("%d",&x);
        pos = buscar(x,N,V);
        printf(pos>N ? "No se encontro %d en el vector",x : "Se encuentra en la posicion %d",pos);
    } while (/* condition */);
}

void leerVector (int V[],unsigned short int *N){
    unsigned short int i;

    printf("Cuantos numeros desea ingresar? ");
    scanf("%u",N);

    V = (int *) malloc(sizeof(int)**N);
    for (i = 0; i < *N; i++)
    {
        printf("Ingrese el %d° número: ");
        scanf("%d",&V[i]);
    }
}

void mostrarImpares (unsigned short int N, int V[]){
    unsigned short int i;
    for (i = 1; i <= N; i+=2)
        printf("%d\t",V[i]);
    printf("\n");
}

void generarVector (int k,unsigned short int N,int V[], int W[], unsigned short int *M){
    unsigned short int i;
    *M=0;
    W = (int *) malloc()
    for (i = 0; i < N; i++)
        if (V[i] % k == 0)
        {
            W[*M] = V[i];
            *M++;
        }
}