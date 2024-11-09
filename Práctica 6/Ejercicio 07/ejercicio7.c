#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCAR 32
#define MAXELEM 27

typedef struct TLibro
{
    char titulo[MAXCAR], autor[MAXCAR];
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

void agregarAutor(TListaA *A, char e[MAXCAR], TListaA *ult);
void agregarSocio(TListaS *S, char e[MAXCAR], TListaS *ult);
void agregarLibro(TLibro **L, char e[MAXCAR], char autor[MAXCAR], int anio, TLibro **ult);
void cargarBiblioteca(TListaA AUTORES[MAXELEM]);
void cargarSocios(TListaS *S);
void buscarAutor(TListaA AUTORES[], char nombre[], TListaA *autor);
void buscarSocio(TListaS Socios, char nombre[], TListaS *socio);
void registrarPrestamo(TListaA AUTORES[MAXELEM], TListaS S, char socio[], char autor[], char libro[]);
void registrarDevoluciones(TListaA AUTORES[MAXELEM], TListaS S, char socio[], char autor[], char libro[]);
void mostrarAutores(TListaA AUTORES[MAXELEM]);
void mostrarSocios(TListaS S);

int main()
{
    TListaA AUTORES[MAXELEM];
    TListaS Socios = NULL;

    cargarBiblioteca(AUTORES);
    cargarSocios(&Socios);
    registrarPrestamo(AUTORES, Socios, "Andres_Efstratiadis", "Brian_Kernighan", "El_lenguaje_de_programacion_C");
    registrarPrestamo(AUTORES, Socios, "Andres_Efstratiadis", "Nikolai_Piskunov", "Calculo_Diferencial_e_Integral");
    registrarDevoluciones(AUTORES, Socios, "Laureano_Ahmad", "Adam_Smith", "La_riqueza_de_las_naciones");
    mostrarAutores(AUTORES);
    mostrarSocios(Socios);

    return 0;
}

// Agrega un autor a una lista de autores
void agregarAutor(TListaA *A, char e[MAXCAR], TListaA *ult)
{
    TListaA aux = *ult, nuevo;
    nuevo = (TListaA)malloc(sizeof(TAutor));
    strcpy(nuevo->nombre, e);
    nuevo->sig = NULL;
    nuevo->libros = NULL;
    if (*A == NULL)
        *A = *ult = nuevo;
    else
    {
        (*ult)->sig = nuevo;
        *ult = (*ult)->sig;
    }
}

// Agrega un socio a la lista de socios
void agregarSocio(TListaS *S, char e[MAXCAR], TListaS *ult)
{
    TListaS aux = *ult, ant, nuevo;
    nuevo = (TListaS)malloc(sizeof(TSocio));
    strcpy(nuevo->nombre, e);
    nuevo->libros = NULL;
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
void agregarLibro(TLibro **L, char e[MAXCAR], char autor[MAXCAR], int anio, TLibro **ult)
{
    TLibro *aux, *nuevo;
    aux = *L;
    nuevo = (TLibro *)malloc(sizeof(TLibro));
    strcpy(nuevo->titulo, e);
    strcpy(nuevo->autor, autor);
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
void cargarBiblioteca(TListaA AUTORES[MAXELEM])
{
    int i, anio;
    FILE *archivo;
    char nombreAutor[MAXCAR], nombre[MAXCAR];
    TListaA ult;
    TLibro *Ult;

    for (i = 0; i < MAXELEM; i++)
        AUTORES[i] = NULL;
    archivo = fopen("autores.txt", "rt");
    while (fscanf(archivo, "%31s\n", nombreAutor))
    {
        agregarAutor(&AUTORES[nombreAutor[0] - 65], nombreAutor, &ult);
        while (fscanf(archivo, "%31s %d\n", nombre, &anio)) // Ciclo infinito
            agregarLibro(&ult->libros, nombre, nombreAutor, anio, &Ult);
    }
    fclose(archivo);
}

// Carga la lista de socios
void cargarSocios(TListaS *S)
{
    int anio;
    FILE *archivo;
    char nombreAutor[MAXCAR], nombreSocio[MAXCAR], nombreLibro[MAXCAR];
    TListaS ult;
    TLibro *Ult;

    archivo = fopen("socios.txt", "rt");
    while (fscanf(archivo, "%s", nombreSocio))
    {
        agregarSocio(S, nombreSocio, &ult);
        while (fscanf(archivo, "%s %s %d", nombreAutor, nombreLibro, &anio))
            agregarLibro(&ult->libros, nombreLibro, nombreAutor, anio, &Ult);
    }
    fclose(archivo);
}

// Dado el nombre de un autor, devuelve un puntero a ese autor (NULL si el autor no existe)
void buscarAutor(TListaA AUTORES[], char nombre[], TListaA *autor)
{
    *autor = AUTORES[nombre[0] - 65];
    while (*autor != NULL && strcmp((*autor)->nombre, nombre) < 0)
        *autor = (*autor)->sig;
    if (strcmp((*autor)->nombre, nombre) > 0)
        *autor = NULL;
}

// Dado el nombre de un socio, devuelve un puntero al socio si existe
void buscarSocio(TListaS Socios, char nombre[], TListaS *socio)
{
    *socio = Socios;
    while (*socio != NULL && strcmp(nombre, (*socio)->nombre))
        *socio = (*socio)->sig;
}

void registrarPrestamo(TListaA AUTORES[MAXELEM], TListaS S, char socio[MAXCAR], char autor[MAXCAR], char libro[MAXCAR])
{
    TListaA act;
    TLibro *Libro, *ant;
    TListaS aux;

    buscarAutor(AUTORES, autor, &act);
    if (act != NULL) // Se encontro al autor
    {
        buscarSocio(S, socio, &aux);
        if (aux != NULL) // Socio encontrado
        {
            // Buscar libro
            Libro = act->libros;
            if (Libro != NULL && !strcmp(Libro->titulo, libro)) // El libro es el primero de la lista
            {
                // Mover libro de biblioteca a socio
                act->libros = Libro->sig;
                Libro->sig = aux->libros;
                aux->libros = Libro;
            }
            else
            {
                // Seguir buscando libro
                while (Libro != NULL && strcmp(Libro->titulo, libro))
                {
                    ant = Libro;
                    Libro = Libro->sig;
                }
                if (Libro != NULL) // Libro encontrado
                {
                    ant->sig = Libro->sig;
                    Libro->sig = aux->libros;
                    aux->libros = Libro;
                }
            }
        }
    }
}

void registrarDevoluciones(TListaA AUTORES[MAXELEM], TListaS S, char socio[MAXCAR], char autor[MAXCAR], char libro[MAXCAR])
{
    TListaA act;
    TLibro *Libro, *ant;
    TListaS aux;

    buscarAutor(AUTORES, autor, &act);
    if (act != NULL)
    {
        buscarSocio(S, socio, &aux);
        if (aux != NULL)
        {
            Libro = aux->libros;
            if (Libro != NULL && !strcmp(Libro->titulo, libro)) // El libro es el primero de la lista
            {
                aux->libros = Libro->sig;
                Libro->sig = act->libros;
                act->libros = Libro;
            }
            else
            {
                while (Libro != NULL && strcmp(Libro->titulo, libro))
                {
                    ant = Libro;
                    Libro = Libro->sig;
                }
                if (Libro != NULL)
                {
                    ant->sig = Libro->sig;
                    Libro->sig = act->libros;
                    act->libros = Libro;
                }
            }
        }
    }
}

void mostrarAutores(TListaA AUTORES[MAXELEM])
{
    int i;
    TListaA aux;
    TLibro *Aux;

    for (i = 0; i < MAXELEM; i++)
        if (AUTORES[i] != NULL)
        {
            aux = AUTORES[i];
            while (aux != NULL)
            {
                printf("%s\n", aux->nombre);
                Aux = aux->libros;
                while (Aux != NULL)
                {
                    printf("%s %d\n", Aux->titulo, Aux->anio);
                    Aux = Aux->sig;
                }
                printf("\n");
                aux = aux->sig;
            }
        }
}

void mostrarSocios(TListaS S)
{
    TListaS aux = S;
    TLibro *Aux;

    while (aux != NULL)
    {
        printf("%s\n", aux->nombre);
        Aux = aux->libros;
        while (Aux != NULL)
        {
            printf("%s %s %d\n", Aux->autor, Aux->titulo, Aux->anio);
            Aux = Aux->sig;
        }
        printf("\n");
        aux = aux->sig;
    }
}