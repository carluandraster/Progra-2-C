typedef struct
{
    unsigned horas, minutos, segundos;
} tiempo;

tiempo crearHora(unsigned horas, unsigned minutos, unsigned segundos);
tiempo deSegundosAHoras(unsigned seg);
tiempo sumar(tiempo hora1, tiempo hora2);
tiempo sumar(tiempo hora, unsigned segundos);