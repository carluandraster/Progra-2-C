#include <stdio.h>

// Prototipos
void generarArchivo ();
void leerArchivo (float *promedio, float *maxima, float *minima);

short int main(){
    float promedio,maxima,minima;
    generarArchivo();
    leerArchivo(&promedio,&maxima,&minima);
    printf("Temperatura promedio: %f°C\nTemperatura maxima: %f°C\n Temperatura minima: %f°C",promedio,maxima,minima);
    return 0;
}

void generarArchivo(){
    FILE *archT, *archB;
    float temperatura;
    archT = fopen("temperatura.txt","rt");
    archB = fopen64("temperatura.dat","wb");
    if (archB == NULL || archT == NULL)
        printf("Error: uno de los archivos no fue abierto correctamente");
    else{
        while (!feof(archT))
        {
            fscanf(archT,"%f",temperatura);
            fprintf(archB,"%f",temperatura);
        }
        fclose(archB);
        fclose(archT);
    }
}