#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA Cola/cola.h"

typedef struct TCancion
{
    char id[15], titulo[20];
    unsigned int duracion;
    struct TCancion *sig;
} TCancion;
typedef TCancion *TSubLista;

typedef struct TPlaylist
{
    int id;
    TSubLista canciones;
    struct TPlaylist *ant, *sig;
} TPlaylist;
typedef struct
{
    TPlaylist *pri, *ult;
} TListaD;

void cargarLista(TListaD *LP);
void cargarCola(TCola *C);
void deSegundosAHorasyMinutos(unsigned int segundos, unsigned int *horas, unsigned int *minutos);
void recorrerCola(TCola *C, TListaD LP, int X, unsigned int *horas, unsigned int *minutos);
int max(int a, int b);
int min(int a, int b);
void eliminarDeLista(TListaD *LP, char id[5], int X, int Y);

int main()
{
    TListaD LP;
    TCola C;
    unsigned int horas, minutos;
    int X, Y;
    char id[5];

    // Inicializaciones
    LP.pri = LP.ult = NULL;
    IniciaC(&C);

    cargarLista(&LP);
    cargarCola(&C);
    printf("Ingrese una playlist: ");
    scanf("%d", &X);
    recorrerCola(&C, LP, X, &horas, &minutos);
    printf("Duracion de la playlist: %u horas y %u minutos.\n", horas, minutos);
    printf("Ingrese id de un interprete: ");
    scanf(" %s", id);
    printf("Ingrese 2 playlists: ");
    scanf("%d %d", &X, &Y);
    eliminarDeLista(&LP, id, X, Y);
    return 0;
}

void cargarLista(TListaD *LP)
{
    FILE *archivo;
    TPlaylist *nuevo;
    TSubLista nodito;
    int idPlaylist;
    unsigned int i, N;

    archivo = fopen("Archivos/lista.txt", "rt");
    while (fscanf(archivo, "%d %u", &idPlaylist, &N) == 2)
    {
        nuevo = (TPlaylist *)malloc(sizeof(TPlaylist));
        nuevo->id = idPlaylist;
        if (LP->pri == NULL)
        {
            LP->pri = LP->ult = nuevo;
            nuevo->ant = NULL;
        }
        else
        {
            LP->ult->sig = nuevo;
            nuevo->ant = LP->ult;
            LP->ult = nuevo;
        }
        nuevo->sig = NULL;
        nuevo->canciones = NULL;
        for (i = 0; i < N; i++)
        {
            nodito = (TSubLista)malloc(sizeof(TCancion));
            fscanf(archivo, "%s %s %u", nodito->id, nodito->titulo, &nodito->duracion);
            nodito->sig = nuevo->canciones;
            nuevo->canciones = nodito;
        }
    }
    fclose(archivo);
}

void cargarCola(TCola *C)
{
    FILE *archivo;
    TElementoC x;
    int i, N;
    char titulo[20];
    unsigned int duracion;

    archivo = fopen("Archivos/lista.txt", "rt");
    while (fscanf(archivo, "%d %u", &x.idPlaylist, &N) == 2)
        for (i = 0; i < N; i++)
        {
            fscanf(archivo, "%s %s %u", x.idCancion, titulo, &duracion);
            PoneC(C, x);
        }

    fclose(archivo);
}

void deSegundosAHorasyMinutos(unsigned int segundos, unsigned int *horas, unsigned int *minutos)
{
    *horas = segundos / 3600;
    *minutos = segundos / 60 % 60;
}

void recorrerCola(TCola *C, TListaD LP, int X, unsigned int *horas, unsigned int *minutos)
{
    TElementoC vc = ConsultaC(*C), x;
    unsigned int acumulador = 0;
    TPlaylist *aux;
    TSubLista nodito;

    aux = LP.pri;
    do
    {
        SacaC(C, &x);
        if (strncmp(x.idCancion, "DUKI", 4) != 0 || x.idPlaylist != X)
        {
            PoneC(C, x);
            while (aux->id < x.idPlaylist)
                aux = aux->sig;
            nodito = aux->canciones;
            while (strcmp(nodito->id, x.idCancion) != 0)
                nodito = nodito->sig;
            acumulador += nodito->duracion;
        }
        else if (strcmp(x.idCancion, vc.idCancion) == 0 && x.idPlaylist == vc.idPlaylist)
            vc = ConsultaC(*C);
    } while (strcmp(ConsultaC(*C).idCancion, vc.idCancion) != 0 || ConsultaC(*C).idPlaylist != vc.idPlaylist);
    deSegundosAHorasyMinutos(acumulador, horas, minutos);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a > b ? b : a;
}

void eliminarDeLista(TListaD *LP, char id[5], int X, int Y)
{
    TPlaylist *aux;
    TSubLista nodito, ant;
    int pri, sec;

    printf("Interprete: %s\n", id);
    aux = LP->pri;
    pri = min(X, Y);
    sec = max(X, Y);
    while (aux->id < pri)
        aux = aux->sig;
    ant = NULL;
    nodito = aux->canciones;
    printf("PLAYLIST %d\n", pri);
    printf("Id Cancion\tTitulo cancion\n");
    while (nodito != NULL)
        if (strncmp(nodito->id, id, 4) == 0)
        {
            printf("%s\t%s\n", nodito->id, nodito->titulo);
            if (ant == NULL)
            {
                aux->canciones = nodito->sig;
                free(nodito);
                nodito = aux->canciones;
            }
            else
            {
                ant->sig = nodito->sig;
                free(nodito);
                nodito = ant->sig;
            }
        }
        else
        {
            ant = nodito;
            nodito = nodito->sig;
        }
    while (aux->id < sec)
        aux = aux->sig;
    ant = NULL;
    nodito = aux->canciones;
    printf("PLAYLIST %d\n", sec);
    printf("Id Cancion\tTitulo cancion\n");
    while (nodito != NULL)
        if (strncmp(nodito->id, id, 4) == 0)
        {
            printf("%s\t%s\n", nodito->id, nodito->titulo);
            if (ant == NULL)
            {
                aux->canciones = nodito->sig;
                free(nodito);
                nodito = aux->canciones;
            }
            else
            {
                ant->sig = nodito->sig;
                free(nodito);
                nodito = ant->sig;
            }
        }
        else
        {
            ant = nodito;
            nodito = nodito->sig;
        }
}