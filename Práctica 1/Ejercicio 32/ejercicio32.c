#include <stdio.h>
#include <string.h>
#define LONGITUD 20

typedef unsigned short int byte;
typedef struct
{
    char ciudad[LONGITUD];
    byte dia;
    float tempMaxima, tempMinima;
} TR;

void cargarArchivo();
void listar(char ciudadMin[LONGITUD], byte *minDia);

byte main()
{
    char ciudadMin[LONGITUD];
    byte minDia;
    cargarArchivo();
    listar(ciudadMin, &minDia);
    printf("La ciudad que tuvo la menor temperatura en el mes fue %s en el dia %hu", ciudadMin, minDia);
    return 0;
}

void cargarArchivo()
{
    FILE *archT, *archB;
    TR registro;
    archT = fopen("temperaturas.txt", "rt");
    archB = fopen("temperaturas.dat", "wb");
    if (archT == NULL || archB == NULL)
        printf("Ocurrio un error en la apertura de uno de los archivos");
    else
        while (fscanf(archT, "%s %hu %f %f", registro.ciudad, &registro.dia, &registro.tempMaxima, &registro.tempMinima) == 4)
            fwrite(&registro, sizeof(TR), 1, archB);
    fclose(archT);
    fclose(archB);
}

void listar(char ciudadMin[LONGITUD], byte *minDia)
{
    // Declaracion de variables
    FILE *archB;
    char VC[LONGITUD];
    float tMin, tMax, min;
    TR registro;

    // Lectura y listado
    archB = fopen("temperaturas.dat", "rb");
    if (archB == NULL)
        printf("Ocurrio un error en la lectura del archivo");
    else
    {
        printf("Ciudad\tTemperatura maxima\tTemperatura minima\n");
        fread(&registro, sizeof(TR), 1, archB);
        strcpy(VC, registro.ciudad);
        min = tMin = registro.tempMinima;
        *minDia = registro.dia;
        strcpy(ciudadMin, registro.ciudad);
        tMax = registro.tempMaxima;
        while (!feof(archB))
        {
            if (!strcmp(VC, registro.ciudad)) // si VC = registro.ciudad
            {
                if (registro.tempMaxima > tMax)
                    tMax = registro.tempMaxima;
                if (registro.tempMinima < tMin)
                {
                    tMin = registro.tempMinima;
                    if (registro.tempMinima < min)
                    {
                        min = registro.tempMinima;
                        strcpy(ciudadMin, registro.ciudad);
                        *minDia = registro.dia;
                    }
                }
            }
            else
            {
                /* code */
            }
            fread(&registro, sizeof(TR), 1, archB);
        }
    }
}