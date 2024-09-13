#include <stdio.h>
#include "../fracciones.h"

void ingresarFraccion (fraccion *f);
void menu(unsigned short *);

short main(){
    fraccion f1,f2,res;
    unsigned short opcion;
    printf("FRACCION 1\n");
    ingresarFraccion(&f1);
    printf("FRACCION 2\n");
    ingresarFraccion(&f2);
    if (iguales(f1,f2))
        printf("Las fracciones son iguales.\n");
    menu(&opcion);
    while (opcion!=5)
    {
        switch (opcion)
        {
        case 1:
            res = sumar(f1,f2);
            printf("Suma: %d/%d\n",numerador(res),denominador(res));
            break;
        
        case 2:
            res = restar(f1,f2);
            printf("Resta: %d/%d\n",numerador(res),denominador(res));
            break;
        
        case 3:
            res = multiplicar(f1,f2);
            printf("Multiplicacion: %d/%d\n",numerador(res),denominador(res));
            break;

        case 4:
            res = dividir(f1,f2);
            printf("Division: %d/%d\n",numerador(res),denominador(res));
            break;
        }
        menu(&opcion);
    }
}

void ingresarFraccion (fraccion *f1){
    int num,den;
    printf("Ingrese numerador: ");
    scanf("%d",&num);
    do
    {
        printf("Ingrese denominador: ");
        scanf("%d",&den);
    } while (den == 0);
}

void menu (unsigned short *opcion){
    printf("Menu de opciones\n");
    printf("1 - Sumar fracciones\n");
    printf("2 - Restar fraccion 2 a fraccion 1\n");
    printf("3 - Multiplicar fracciones\n");
    printf("4 - Dividir fraccion 1 por fraccion 2\n");
    printf("5 - Salir\n");
    scanf("%hu",opcion);
}