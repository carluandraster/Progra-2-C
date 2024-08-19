#include <stdio.h>

void convertir(unsigned int segundosTotales, unsigned int *horas, unsigned int *minutos, unsigned int *segundos);

int main()
{
    unsigned int segundosTotales, horas, minutos, segundos;
    printf("Ingrese cantidad total de segundos: ");
    scanf("%u", &segundosTotales);
    convertir(segundosTotales, &horas, &minutos, &segundos);
    printf("%02u:%02u:%02u", horas, minutos, segundos);

    return 0;
}

void convertir(unsigned int segundosTotales, unsigned int *horas, unsigned int *minutos, unsigned int *segundos)
{
    *horas = segundosTotales / 3600;
    segundosTotales %= 3600;
    *minutos = segundosTotales / 60;
    *segundos = segundosTotales % 60;
}