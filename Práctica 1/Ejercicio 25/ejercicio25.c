// Preprocesador
#include <stdio.h>
#define MAXELEM 255

// Definición de tipos
typedef unsigned short int byte;
typedef struct
{
    char nombre[30];
    byte edad;
} persona;

// Prototipos
void leerPersonas (persona PERSONAS[MAXELEM], byte *N);
void quienesSuperan (byte x, persona PERSONAS[MAXELEM], byte N);
float porcentaje (persona PERSONAS[MAXELEM], byte N);

// Funciones

byte main(){
    // Declaración de variables
    persona PERSONAS[MAXELEM];
    byte N,x;

    // Ingresar vector
    leerPersonas(PERSONAS,&N);

    // Inciso a
    do
    {
        printf("Ingrese una edad: ");
        scanf("%hu",&x);
    } while (x>120);
    quienesSuperan(x,PERSONAS,N);

    // Inciso b
    printf("Porcentaje de personas mayores de edad: %.2f %%",porcentaje(PERSONAS,N));

    return 0;
}

void leerPersonas (persona PERSONAS[MAXELEM], byte *N){
    byte i;

    do
    {
        printf("Cuantos datos va a ingresar?\n");
        scanf("%hu",N);
    } while (*N>MAXELEM);
    
    for (i = 0; i < *N; i++)
    {
        printf("Nombre %hu: ",i+1);
        scanf(" %s",PERSONAS[i].nombre);
        do
        {
            printf("Edad %hu: ",i+1);
            scanf(" %hu",&PERSONAS[i].edad);
        } while (PERSONAS[i].edad>120);
    }
}

void quienesSuperan (byte x, persona PERSONAS[MAXELEM], byte N){
    byte i;
    printf("Personas mayores de %hu:\n",x);
    for (i = 0; i < N; i++)
        if (PERSONAS[i].edad>x)
            printf("%s\n",PERSONAS[i].nombre);
}

float porcentaje (persona PERSONAS[MAXELEM], byte N){
    byte i, contador = 0;
    for (i = 0; i < N; i++)
        if (PERSONAS[i].edad>=18)
            contador++;
    return (float) contador/N*100;
}