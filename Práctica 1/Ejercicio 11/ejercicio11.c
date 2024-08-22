#include <stdio.h>
#define MAXIMO(x,y) (x>y ? x : y)
#define ALFABETICO(x) (x>='A' && x<='Z' || x>='a' && x<='z')

int main(){
    // Declaracion de variables
    int a,b;
    char c;

    // Inciso a
    printf("Ingrese 2 numeros: ");
    scanf("%d %d",&a,&b);
    printf("Maximo entre %d y %d: %d\n",a,b,MAXIMO(a,b));

    // Inciso b
    printf("Ingrese un caracter: ");
    scanf(" %c",&c);
    printf(ALFABETICO(c) ? "El caracter es alfabetico" : "El caracter no es alfabetico");
}