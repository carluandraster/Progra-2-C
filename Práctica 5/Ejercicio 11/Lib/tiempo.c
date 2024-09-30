#include "tiempo.h"

tiempo crearHora(unsigned horas, unsigned minutos, unsigned segundos)
{
    tiempo aux;
    aux.horas = horas;
    aux.minutos = minutos;
    aux.segundos = segundos;
    return aux;
}

tiempo deSegundosAHoras(unsigned seg)
{
    tiempo aux;
    aux.segundos = seg % 60;
    aux.minutos = seg / 60 % 60;
    aux.horas = seg / 3600;
    return aux;
}

tiempo sumar(tiempo hora1, tiempo hora2)
{
    tiempo aux;
    aux.segundos = hora1.segundos + hora2.segundos;
    aux.minutos = hora1.minutos + hora2.minutos + aux.segundos / 60;
    aux.segundos %= 60;
    aux.horas = hora1.horas + hora2.horas + aux.minutos / 60;
    aux.minutos %= 60;
}

tiempo sumar(tiempo hora, unsigned segundos)
{
    tiempo hora2;
    hora2 = deSegundosAHoras(segundos);
    return sumar(hora, hora2);
}