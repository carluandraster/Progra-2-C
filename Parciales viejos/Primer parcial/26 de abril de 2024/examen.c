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
    struct nodoD *ant, *sig;
} nodoD;
typedef struct
{
    nodoD *pri, *ult;
} TListaD;

// Lista simple
typedef struct nodo
{
    char dominio[8], fecha[9], hora[6];
    struct nodo *sig;
} nodo;
typedef nodo *TLista;

typedef char string[9];

void cargarListaSimple(TLista *LT);
void cargarListaDoble(TListaD *PA);
void cargarCola(TCola *C);
void eliminar(TLista *LT, float *porcentaje);
int cantPuestos(TListaD PA);
TLista pos(TLista LT, char dominio[]);
void mesDeAbril(TCola *C, TListaD PA, TLista LT);
void generarArchivo(TListaD PA);
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
    eliminar(&LT, &porcentaje);
    printf("Primer dominio de la lista: %s\n", LT->dominio);

    // Inciso b)
    mesDeAbril(&C, PA, LT);

    // Inciso c)
    generarArchivo(PA);
    observaciones(PA);

    return 0;
}

void cargarListaSimple(TLista *LT)
{
    string DOMINIOS[] = {"AA001AA", "AA001AB", "AA001AC", "AAA002", "AAA003", "AAA004", "DQC324"};
    string FECHAS[] = {"20251201", "20250301", "20251105", "20241120", "20241125", "20240430", "20240405"};
    string HORAS[] = {"10:00", "11:00", "12:00", "13:00", "14:00", "15:00", "16:00"};
    int i;
    TLista nuevo, aux;

    for (i = 0; i < 7; i++)
    {
        nuevo = (TLista)malloc(sizeof(nodo));
        strcpy(nuevo->dominio, DOMINIOS[i]);
        strcpy(nuevo->fecha, FECHAS[i]);
        strcpy(nuevo->hora, HORAS[i]);
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

void cargarListaDoble(TListaD *PA)
{
    string PUESTOS[] = {"A01", "A02", "A03", "A04", "A05"};
    nodoD *nuevo;
    int i;
    for (i = 0; i < 5; i++)
    {
        nuevo = (nodoD *)malloc(sizeof(nodoD));
        strcpy(nuevo->puesto, PUESTOS[i]);
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

void cargarCola(TCola *C)
{
    string DOMINIOS[] = {"AAA004", "DQC324", "AA001AA", "AA001AB", "AA001AC"};
    TElementoC x;
    int i;
    for (i = 0; i < 5; i++)
    {
        strcpy(x.texto, DOMINIOS[i]);
        PoneC(C, x);
    }
}

// Elimina de LT los turnos incorrectos
void eliminar(TLista *LT, float *porcentaje)
{
    TLista aux = *LT, ant = NULL, elim;
    int casosTotales, eliminados;
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
        {
            ant = aux;
            aux = aux->sig;
        }
    }
    *porcentaje = casosTotales == 0 ? -1 : (float)eliminados / casosTotales * 100;
}

// Devuelve la cantidad de puestos
int cantPuestos(TListaD PA)
{
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

// Devuelve la posicion del dominio en la lista LT (NULL si no está)
TLista pos(TLista LT, char dominio[])
{
    TLista aux = LT;
    while (aux != NULL && strcmp(aux->dominio, dominio) < 0)
        aux = aux->sig;
    return aux != NULL && strcmp(aux->dominio, dominio) == 0 ? aux : NULL;
}

// Simula la VTV en el mes de abril
void mesDeAbril(TCola *C, TListaD PA, TLista LT)
{
    TElementoC x;
    TLista posicion;
    nodoD *aux;
    TSubLista act, ant;
    int N = cantPuestos(PA), nroPuesto, i;
    TCola colaux;

    IniciaC(&colaux);
    printf("Dominios de autos rechazados por no tener turno: \n");
    while (!VaciaC(*C))
    {
        SacaC(C, &x);
        posicion = pos(LT, x.texto);
        if (posicion != NULL)
            if (posicion->fecha[5] == '4')
            {
                nroPuesto = rand() % N + 1;
                aux = PA.pri;
                for (i = 1; i < nroPuesto; i++)
                    aux = aux->sig;
                act = (TSubLista)malloc(sizeof(nodoSub));
                strcpy(act->dominio, x.texto);
                act->cantObs = 0;
                act->sig = NULL;
                ant = aux->automoviles;
                if (ant == NULL)
                    aux->automoviles = act;
                else
                {
                    while (ant->sig != NULL)
                        ant = ant->sig;
                    ant->sig = act;
                }
            }
            else
                PoneC(&colaux, x);
        else
            printf("%s\n", x.texto);
    }
    // Asignarle a C, colaux
    while (!VaciaC(colaux))
    {
        SacaC(&colaux, &x);
        PoneC(C, x);
    }
}

void generarArchivo(TListaD PA)
{
    nodoD *aux;
    TSubLista aux1;
    FILE *archivo;

    archivo = fopen("TESTEOS.TXT", "wt");
    aux = PA.pri;
    while (aux != NULL)
    {
        aux1 = aux->automoviles;
        while (aux1 != NULL)
        {
            fprintf(archivo, "%s %s %d ", aux->puesto, aux1->dominio, rand() % 10);
            if (rand() % 2)
                fprintf(archivo, "O\n");
            else
                fprintf(archivo, "R\n");
            aux1 = aux1->sig;
        }
        aux = aux->sig;
    }
    fclose(archivo);
}

void observaciones(TListaD PA)
{
    FILE *archivo;
    nodoD *aux;
    TSubLista aux1, ant;
    char puesto[4], dominio[8], estado;
    int cantObs;

    archivo = fopen("TESTEOS.TXT", "rt");
    while (fscanf(archivo, "%s %s %d %c", puesto, dominio, cantObs, estado) == 4)
    {
        aux = PA.pri;
        while (strcmp(aux->puesto, puesto))
            aux = aux->sig;
        aux1 = aux->automoviles;
        if (estado == 'O')
        {
            while (strcmp(aux1->dominio, dominio))
                aux1 = aux1->sig;
            aux1->cantObs = cantObs;
        }
        else
        {
            ant = NULL;
            while (strcmp(aux1->dominio, dominio))
            {
                ant = aux1;
                aux1 = aux1->sig;
            }
            if (ant == NULL)
                aux->automoviles = aux1->sig;
            else
                ant->sig = aux1->sig;
            free(aux1);
        }
    }

    fclose(archivo);
}