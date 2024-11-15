#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA Pila/pila.h"

// Sublista de pasajeros
typedef struct pasajero
{
    char destino;
    struct pasajero *sig;
} pasajero;
typedef pasajero *TSubLista;

// Lista doble de estaciones
typedef struct estacion
{
    char codigo, nombre[31];
    TSubLista pasajeros;
    struct estacion *ant, *sig;
} estacion;
typedef struct
{
    estacion *pri, *ult;
} TListaD;

void agregarEstacion(TListaD *ESTACIONES, char codigo, char nombre[]);
void agregarPasajero(TSubLista *ult, char destino);
void cargarLista(TListaD *ESTACIONES);
void eliminar(TPila *P, char estacion, int *cantElim);
void simulacionViaje(TListaD ESTACIONES, int CAPA);

int main()
{
    TListaD ESTACIONES;
    int CAPA;
    ESTACIONES.pri = ESTACIONES.ult = NULL;
    cargarLista(&ESTACIONES);
    do
    {
        printf("Ingrese capacidad del tren: ");
        scanf("%d", &CAPA);
    } while (CAPA < 1);
    simulacionViaje(ESTACIONES, CAPA);
    return 0;
}

void agregarEstacion(TListaD *ESTACIONES, char codigo, char nombre[])
{
    estacion *nuevo;
    nuevo = (estacion *)malloc(sizeof(estacion));
    nuevo->codigo = codigo;
    strcpy(nuevo->nombre, nombre);
    nuevo->pasajeros = NULL;
    nuevo->ant = ESTACIONES->ult;
    if (ESTACIONES->ult == NULL)
        ESTACIONES->pri = ESTACIONES->ult = nuevo;
    else
    {
        ESTACIONES->ult->sig = nuevo;
        ESTACIONES->ult = nuevo;
    }
    nuevo->sig = NULL;
}

void agregarPasajero(TSubLista *ult, char destino)
{
    TSubLista nuevo = (TSubLista)malloc(sizeof(pasajero));
    nuevo->destino = destino;
    nuevo->sig = NULL;
    if (*ult == NULL)
        *ult = nuevo;
    else
    {
        (*ult)->sig = nuevo;
        *ult = nuevo;
    }
}

void cargarLista(TListaD *ESTACIONES)
{
    FILE *archivo;
    char codigo, estacion[31];
    int i, cantPasajeros;
    TSubLista ult;

    archivo = fopen("INICIAL.txt", "rt");
    while (fscanf(archivo, "%c %s %d", &codigo, estacion, &cantPasajeros) == 3)
    {
        agregarEstacion(ESTACIONES, codigo, estacion);
        ult = ESTACIONES->ult->pasajeros;
        for (i = 0; i < cantPasajeros; i++)
        {
            fscanf(archivo, "%c", &codigo);
            agregarPasajero(&ult, codigo);
        }
    }
    fclose(archivo);
}

// Dado un caracter, elimina todas sus ocurrencias en la pila
void eliminar(TPila *P, char estacion, int *cantElim)
{
    TElementoP x;
    if (!VaciaP(*P))
    {
        SacaP(P, &x);
        eliminar(P, estacion, cantElim);
        if (x != estacion)
            PoneP(P, x);
        else
            ++*cantElim;
    }
    else
        *cantElim = 0;
}

void simulacionViaje(TListaD ESTACIONES, int CAPA)
{
    int aBordo = 0, cantElim;
    estacion *aux;
    TSubLista pasajero;
    TPila P;
    IniciaP(&P);
    aux = ESTACIONES.pri;
    while (aux != NULL)
    {
        eliminar(&P, aux->codigo, &cantElim);
        aBordo -= cantElim;
        while (aux->pasajeros != NULL && aBordo < CAPA)
        {
            pasajero = aux->pasajeros;
            aBordo++;
            PoneP(&P, pasajero->destino);
            aux->pasajeros = pasajero->sig;
            free(pasajero);
        }
        aux = aux->sig;
    }
    aux = ESTACIONES.ult;
    while (aux != NULL)
    {
        eliminar(&P, aux->codigo, &cantElim);
        aBordo -= cantElim;
        while (aux->pasajeros != NULL && aBordo < CAPA)
        {
            pasajero = aux->pasajeros;
            aBordo++;
            PoneP(&P, pasajero->destino);
            aux->pasajeros = pasajero->sig;
            free(pasajero);
        }
        aux = aux->ant;
    }
}