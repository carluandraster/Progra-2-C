#include <stdio.h>

// Prototipos
void generarArchivo();
void leerArchivo(float *promedio, float *maxima, float *minima);

short int main()
{
    float promedio, maxima, minima;
    generarArchivo();
    leerArchivo(&promedio, &maxima, &minima);
    printf("Temperatura promedio: %f C\nTemperatura maxima: %f C\nTemperatura minima: %f C", promedio, maxima, minima);
    return 0;
}

void generarArchivo()
{
    FILE *archT, *archB;
    float temperatura;
    archT = fopen("temperatura.txt", "rt");
    archB = fopen("temperatura.dat", "wb");
    if (archB == NULL || archT == NULL)
        printf("Error: uno de los archivos no fue abierto correctamente");
    else
    {
        while (!feof(archT))
        {
            fscanf(archT, "%f", &temperatura);
            fprintf(archB, "%f ", temperatura);
        }
        fclose(archB);
        fclose(archT);
    }
}

void leerArchivo(float *promedio, float *maxima, float *minima)
{
    FILE *archB;
    float numero, acumulador = 0;
    unsigned int contador = 0;
    *maxima = -9999;
    *minima = 9999;
    archB = fopen("temperatura.dat", "rb");
    if (archB == NULL)
        printf("Error: no se pudo leer el archivo");
    else
    {
        while (fscanf(archB, "%f", &numero) == 1)
        {
            contador++;
            acumulador += numero;
            if (numero > *maxima)
                *maxima = numero;
            if (numero < *minima)
                *minima = numero;
        }
        fclose(archB);
    }
    *promedio = acumulador / contador;
}