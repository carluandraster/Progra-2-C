#include "tiempo.h"

THora crearHora(unsigned horas, unsigned minutos, unsigned segundos)
{
    THora aux;
    aux.horas = horas;
    aux.minutos = minutos;
    aux.segundos = segundos;
    return aux;
}

THora deSegundosAHoras(unsigned seg)
{
    THora aux;
    aux.segundos = seg % 60;
    aux.minutos = seg / 60 % 60;
    aux.horas = seg / 3600;
    return aux;
}

THora sumar(THora hora1, THora hora2)
{
    THora aux;
    aux.segundos = hora1.segundos + hora2.segundos;
    aux.minutos = hora1.minutos + hora2.minutos + aux.segundos / 60;
    aux.segundos %= 60;
    aux.horas = hora1.horas + hora2.horas + aux.minutos / 60;
    aux.minutos %= 60;
}

THora suma(THora hora, unsigned segundos)
{
    THora hora2;
    hora2 = deSegundosAHoras(segundos);
    return sumar(hora, hora2);
}

unsigned short obtenerHora(THora hora)
{
    return hora.horas;
}

unsigned short obtenerMinuto(THora hora)
{
    return hora.minutos;
}

unsigned short obtenerSegundo(THora hora)
{
    return hora.segundos;
}