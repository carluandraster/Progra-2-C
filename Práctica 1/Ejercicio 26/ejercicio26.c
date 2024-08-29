#include <stdio.h>

typedef unsigned int word;
typedef struct
{
    char nombre[30];
    word matricula;
    float promedio;
} TRA;

TRA ingresarAlumno ();

short int main(){
    TRA alumno = ingresarAlumno();
    printf("Nombre: %s\nMatricula: %u\nPromedio: %.2f",alumno.nombre,alumno.matricula,alumno.promedio);
    return 0;
}

TRA ingresarAlumno (){
    TRA aux;
    printf("Ingrese nombre: ");
    scanf("%s",aux.nombre);
    printf("Ingrese matricula: ");
    scanf("%u",&aux.matricula);
    do
    {
        printf("Ingrese promedio: ");
        scanf("%f",&aux.promedio);
    } while (aux.promedio<1 || aux.promedio>10);
    return aux;
}