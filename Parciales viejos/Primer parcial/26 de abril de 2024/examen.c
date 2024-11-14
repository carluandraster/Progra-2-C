#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA cola/cola.h"

// Sublista
typedef struct nodoSub
{
    char dominio[8];
    int cantObs;
    struct nodoSub *sig;
} nodoSub;
typedef nodoSub *TSubLista;

// Lista doble
typedef struct nodoD
{
    char puesto[4];
    TSubLista automoviles;
    struct nodoD *ant,*sig;
} nodoD;
typedef struct
{
    nodoD *pri,*ult;
} TListaD;

// Lista simple
typedef struct nodo
{
    char dominio[8],fecha[9],hora[6];
    struct nodo *sig;
} nodo;
typedef nodo *TLista;

typedef char string[9];

void cargarListaSimple(TLista *LT);
void cargarListaDoble(TListaD *PA);
void cargarCola(TCola *C);
void eliminar(TLista *LT, float *porcentaje);
int cantPuestos(TListaD PA);
int esta(TLista LT, char dominio[]);
void mesDeAbril(TCola *C, TListaD PA, TLista LT);
void observaciones(TListaD PA);

int main()
{
    TLista LT;
    TListaD PA;
    TCola C;
    float porcentaje;

    // Inicializaciones
    LT = NULL;
    PA.pri = PA.ult = NULL;
    IniciaC(&C);

    // Cargar listas y cola
    cargarListaSimple(&LT);
    cargarListaDoble(&PA);
    cargarCola(&C);

    // Inciso a)
    eliminar(&LT,&porcentaje);
    printf("Porcentaje de turnos depurados: %5.2f\n",porcentaje);

    // Inciso b)
    mesDeAbril(&C,PA,LT);

    // Inciso c)
    observaciones(PA);

    return 0;
}

void cargarListaSimple(TLista *LT){
    string DOMINIOS[] = {"AAA002", "AAA003", "AAA004", "DQC324","AA001AA", "AA001AB", "AA001AC" };
    string FECHAS[] = {"20250301", "20250401", "20250405","20241120", "20241125", "20241130", "20241205" };
    string HORAS[] = {"10:00", "11:00","12:00","13:00","14:00","15:00","16:00"};
    int i;
    TLista nuevo,aux;

    for (i = 0; i < 7; i++)
    {
        nuevo = (TLista)malloc(sizeof(nodo));
        strcpy(nuevo->dominio,DOMINIOS[i]);
        strcpy(nuevo->fecha,FECHAS[i]);
        strcpy(nuevo->hora,HORAS[i]);
        if (*LT == NULL)
            aux = *LT = nuevo;
        else
        {
            aux->sig = nuevo;
            aux = aux->sig;
        }
    }
    aux->sig = NULL;
}

void cargarListaDoble(TListaD *PA){
    string PUESTOS[] = {"A01", "A02","A03","A04","A05"};
    nodoD *nuevo;
    int i;
    for (i = 0; i < 5; i++)
    {
        nuevo = (nodoD*)malloc(sizeof(nodoD));
        strcpy(nuevo->puesto,PUESTOS[i]);
        nuevo->automoviles = NULL;
        nuevo->ant = PA->ult;
        if (PA->ult == NULL)
            PA->pri = nuevo;
        else
            PA->ult->sig = nuevo;
        PA->ult = nuevo;
    }
    PA->ult->sig = NULL;
}

void cargarCola(TCola *C){
    string DOMINIOS[] = {"AAA004", "DQC324","AA001AA", "AA001AB", "AF001AC" };
    TElementoC x;
    int i;
    for (i = 0; i < 5; i++){
        strcpy(x.texto,DOMINIOS[i]);
        PoneC(C,x);
    }
}

// Elimina de LT los turnos incorrectos
void eliminar(TLista *LT, float *porcentaje){
    TLista aux = *LT,ant = NULL,elim;
    int casosTotales,eliminados;
    casosTotales = eliminados = 0;
    while (aux != NULL)
    {
        casosTotales++;
        if (!(aux->fecha[4] == '1' && (aux->fecha[5] == '1' || aux->fecha[5] == '2') || aux->fecha[5] == aux->dominio[5]))
        {
            eliminados++;
            elim = aux;
            aux = aux->sig;
            if (ant == NULL)
                *LT = aux;
            else
                ant->sig = aux;
            free(elim);
        }
        else
            aux = aux->sig;
    }
    *porcentaje = casosTotales == 0 ? -1 : (float) eliminados / casosTotales * 100;
}

// Devuelve la cantidad de puestos
int cantPuestos(TListaD PA){
    int contador = 0;
    nodoD *aux;
    aux = PA.pri;
    while (aux != NULL)
    {
        contador++;
        aux = aux->sig;
    }
    return contador;
}

// Verifica si un dominio esta en la lista LT (sabiendo que esta ORDENADA)
int esta(TLista LT, char dominio[]){
    TLista aux = LT;
    while (aux != NULL && strcmp(aux->dominio,dominio)<0)
        aux = aux->sig;
    return aux != NULL && !strcmp(aux->dominio,dominio);
}