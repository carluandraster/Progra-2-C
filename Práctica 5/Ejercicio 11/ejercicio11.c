#include <stdio.h>
#include "Lib/colaDinamica.h"
#include "Lib/tiempo.h"

void ingresarCola(TCola *C);
void mostrarCola(TCola *C, float *promedio, unsigned *maxLegajo);

int main()
{
    TCola C;
    float promedio;
    unsigned maxLegajo;
    IniciaC(&C);
    ingresarCola(&C);
    mostrarCola(&C, &promedio, &maxLegajo);
    printf("Tiempo promedio de espera: %5.2f\n", promedio);
    printf("Lgajo con mayor tiempo de espera: %u", maxLegajo);
    return 0;
}

void ingresarCola(TCola *C)
{
    TElementoC x;
    FILE *archivo;
    archivo = fopen("empleados_microondas.txt", "rt");
    if (archivo == NULL)
        printf("Hubo un problema al abrir el archivo.\n");
    while (fscanf(archivo, "%u %u %u", &x.legajo, &x.arribo, &x.tiempoHorno) == 3)
        poneC(C, x);
    fclose(archivo);
}

void mostrarCola(TCola *C, float *promedio, unsigned *maxLegajo)
{
    TElementoC x;
    unsigned contador, acumulador, tEspera, tInicio, tFin, maxEspera;
    THora horaInicial, horaInicio, horaFin;

    contador = acumulador = maxEspera = tFin = 0;
    horaInicial = crearHora(12, 0, 0);

    printf("Legajo\tHora inicio\tHora final\n");
    while (!VaciaC(*C))
    {
        sacaC(C, &x);
        if (tFin <= x.arribo) // Llegó después de que se liberara el horno
        {
            tInicio = x.arribo;
            tEspera = 0;
        }
        else // Esperó en la cola
        {
            tInicio = tFin;
            tEspera = tInicio - x.arribo;
        }
        if (tEspera > maxEspera)
        {
            maxEspera = tEspera;
            *maxLegajo = x.legajo;
        }
        tFin = tInicio + x.tiempoHorno;
        contador++;
        acumulador += tEspera;
        horaInicio = suma(horaInicial, tInicio);
        horaFin = suma(horaInicio, tFin);
        printf("%u\t %u:%u:%u\t %u:%u:%u\n", x.legajo, obtenerHora(horaInicio), obtenerMinuto(horaInicio), obtenerSegundo(horaInicio), obtenerHora(horaFin), obtenerMinuto(horaFin), obtenerSegundo(horaFin));
    }
}