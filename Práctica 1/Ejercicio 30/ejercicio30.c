#include <stdio.h>

typedef struct
{
    char patente[6], fecha[8], hora[4];
    float velRegistrada, velMaxima;
} TR;

void leerArchivo(unsigned int *mediciones, unsigned int *registros);

short int main()
{
    unsigned int mediciones, registros;
    leerArchivo(&mediciones, &registros);
    printf("Cantidad de mediciones procesadas: %u\nCantidad de registros generados en el archivo: %u", mediciones, registros);
    return 0;
}

void leerArchivo(unsigned int *mediciones, unsigned int *registros)
{
    FILE *archT, *archB;
    TR registro;
    *mediciones = *registros = 0;
    archB = fopen("radar_vigia.dat", "wb");
    archT = fopen("radar_vigia.txt", "rt");
    if (archT == NULL || archB == NULL)
        printf("Lo sentimos pero ocurrio un error al abrir un archivo");
    else
    {
        while (fscanf(archT, "%6s %f %f %8s %4s\n", registro.patente, &registro.velRegistrada, &registro.velMaxima, registro.fecha, registro.hora) == 5)
        {
            ++*mediciones;
            if (registro.velRegistrada > 1.2 * registro.velMaxima)
            {
                ++*registros;
                fwrite(&registro, sizeof(TR), 1, archB);
            }
        }
        fclose(archB);
        fclose(archT);
    }
}