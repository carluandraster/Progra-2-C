#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCAR 32
#define MAXELEM 27

typedef struct TLibro
{
    char titulo[MAXCAR],autor[MAXCAR];
    int anio;
    struct TLibro *sig;
} TLibro;
typedef struct TAutor
{
    char nombre[MAXCAR];
    struct TLibro *libros;
    struct TAutor *sig;
} TAutor;
typedef TAutor *TListaA;
typedef struct TSocio
{
    char nombre[MAXCAR];
    struct TLibro *libros;
    struct TSocio *sig;
} TSocio;
typedef TSocio *TListaS;

void agregarAutor(TListaA *A,char e[MAXCAR], TListaA *ult);
void agregarSocio(TListaS *S,TSocio e, TListaS *ult);
void agregarLibro(TLibro **L,char e[MAXCAR],char autor[MAXCAR],int anio, TLibro **ult);
void cargarBiblioteca(TListaA AUTORES[MAXELEM]);
void cargarSocios(TListaS *S);
void registrarPrestamo(TListaA AUTORES[MAXELEM], TListaS S, char socio[MAXCAR],char autor[MAXCAR],char libro[MAXCAR]);
void registrarDevoluciones(TListaA AUTORES[MAXELEM], TListaS S, char socio[MAXCAR],char autor[MAXCAR],char libro[MAXCAR]);
void mostrarAutores(TListaA AUTORES[MAXELEM]);
void mostrarSocios(TListaS S);

int main()
{
    TListaA AUTORES[MAXELEM];
    TListaS Socios = NULL;

    cargarBiblioteca(AUTORES);
    cargarSocios(&Socios);
    registrarPrestamo(AUTORES,Socios,"Andres_Efstratiadis","Brian_Kernighan","El_lenguaje_de_programacion_C");
    registrarPrestamo(AUTORES,Socios,"Andres_Efstratiadis","Nikolai_Piskunov","Calculo_Diferencial_e_Integral");
    registrarDevoluciones(AUTORES,Socios,"Laureano_Ahmad","Adam_Smith","La_riqueza_de_las_naciones");
    mostrarAutores(AUTORES);
    mostrarSocios(Socios);

    return 0;
}

// Agrega un autor a una lista de autores
void agregarAutor(TListaA *A,char e[MAXCAR], TListaA *ult){
    TListaA aux = *ult, nuevo;
    nuevo = (TListaA)malloc(sizeof(TAutor));
    strcpy(nuevo->nombre,e);
    nuevo->sig = nuevo->libros = NULL;
    if (*A == NULL)
        *A = *ult = nuevo;
    else
    {
        (*ult)->sig = nuevo;
        *ult = (*ult)->sig;
    }
}

// Agrega un socio a la lista de socios
void agregarSocio(TListaS *S,TSocio e, TListaS *ult){
    TListaS aux = *ult, ant, nuevo;
    nuevo = (TListaS)malloc(sizeof(TSocio));
    *nuevo = e;
    nuevo->sig = NULL;
    if (*S == NULL)
        *S = *ult = nuevo;
    else
    {
        (*ult)->sig = nuevo;
        *ult = (*ult)->sig;
    }
}

// Agrega un libro a una sublista de libros
void agregarLibro(TLibro **L,char e[MAXCAR],char autor[MAXCAR],int anio, TLibro **ult){
    TLibro *aux, *nuevo;
    aux = *L;
    nuevo = (TLibro *)malloc(sizeof(TLibro));
    strcpy(nuevo->titulo, e);
    strcpy(nuevo->autor,autor);
    nuevo->anio = anio;
    nuevo->sig = NULL;
    if (aux == NULL)
        *L = *ult = nuevo;
    else
    {
        (*ult)->sig = nuevo;
        *ult = (*ult)->sig;
    }
}

// Carga la biblioteca
void cargarBiblioteca(TListaA AUTORES[MAXELEM]){
    int i,anio;
    FILE *archivo;
    char nombreAutor[MAXCAR],nombre;
    TListaA ult;
    TLibro *Ult;

    for (i = 0; i < MAXELEM; i++)
        AUTORES[i] = NULL;
    archivo = fopen("autores.txt","rt");
    while (fscanf(archivo,"%s",nombreAutor))
    {
        agregarAutor(&AUTORES[nombreAutor[0]-65],nombreAutor,&ult);
        while (fscanf(archivo,"%s %d",nombre,&anio))
            agregarLibro(ult->libros,nombre,nombreAutor,anio,Ult);
    }
    fclose(archivo);
}

void cargarSocios(TListaS *S){

}