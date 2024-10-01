typedef struct
{
    unsigned horas, minutos, segundos;
} THora;

THora crearHora(unsigned horas, unsigned minutos, unsigned segundos);
THora deSegundosAHoras(unsigned seg);
THora sumar(THora hora1, THora hora2);
THora suma(THora hora, unsigned segundos);
unsigned short obtenerHora(THora hora);
unsigned short obtenerMinuto(THora hora);
unsigned short obtenerSegundo(THora hora);