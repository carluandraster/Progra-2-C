#include <stdio.h>

typedef struct
{
    char apellido[10], nombre[10], nacionalidad[12];
    unsigned int puntaje;
} TR;

void cargarArchivo();
void buscar(unsigned short int posicion);

short int main()
{
    unsigned int posicion;
    cargarArchivo();
    printf("Busque a un jugador por su posicion en el archivo: ");
    scanf("%u", &posicion);
    buscar(posicion);
    return 0;
}

void cargarArchivo()
{
    // Declaracion de variables
    FILE *archT, *archB;
    TR registro;

    // Abrir archivos
    archT = fopen("jugadores.txt", "rt");
    archB = fopen("jugadores.dat", "wb");

    // Leer de archT para escribir en archB
    if (archB == NULL || archT == NULL)
        printf("Error: alguno de los archivos no se abrio correctamente");
    else
        while (fscanf(archT, "%9s %9s %11s %u", registro.apellido, registro.nombre, registro.nacionalidad, &registro.puntaje) == 4)
            fwrite(&registro, sizeof(TR), 1, archB);
    // Cerrar archivos
    fclose(archT);
    fclose(archB);
}

void buscar(unsigned short int posicion)
{
    FILE *archB;
    TR registro;
    archB = fopen("jugadores.dat", "rb");
    if (archB == NULL)
        printf("No se pudo abrir el archivo");
    else
    {
        fseek(archB, posicion * sizeof(TR), 0);
        fread(&registro, sizeof(TR), 1, archB);
        printf("Nombre: %s %s\nNacionalidad: %s\nPuntaje: %u", registro.nombre, registro.apellido, registro.nacionalidad, registro.puntaje);
    }
    fclose(archB);
}