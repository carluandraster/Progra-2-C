#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA cola/cola.h"
#define INFINITO 9999999

// Archivo
typedef struct
{
    char CodigoLote[5], DocumentoOfertante[9], medio;
    float PrecioOfertado;
} TRegistro;

// Lista circular
typedef struct nodoC
{
    char CodigoLote[5];
    float PrecioBase;
    struct nodoC *sig;
} nodoC;
typedef nodoC *TListaC;

// Sublistas
typedef struct SubNodo
{
    char DocumentoOfertante[9];
    float PrecioOfertado;
    struct SubNodo *sig;
} SubNodo;
typedef SubNodo *TSubLista;

// Lista simple
typedef struct nodo
{
    char CodigoLote[5];
    float PrecioRealEstimado;
    TSubLista ofertasT, ofertasM;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;

void cargarArchivo();
void cargarListaCircular(TListaC *LC);
void cargarLista(TLista *L, TListaC LC);
void cargarCola(TCola *CodigosLote);
void eliminarVendidos(TLista *L, TCola *CodigosLote);

int main()
{
    TListaC LC = NULL;
    TLista L = NULL;
    TCola CodigosLote;

    cargarArchivo();
    cargarListaCircular(&LC);
    cargarCola(&CodigosLote);

    cargarLista(&L, LC);
    eliminarVendidos(&L, &CodigosLote);
    return 0;
}

void cargarArchivo()
{
    TRegistro registro;
    FILE *archT, *archB;

    archT = fopen("Archivos/OFERTAS.TXT", "rt");
    archB = fopen("Archivos/OFERTAS.DAT", "wb");
    if (archT != NULL && archB != NULL)
    {
        while (fscanf(archT, "%s %s %f %c", registro.CodigoLote, registro.DocumentoOfertante, &registro.PrecioOfertado, &registro.medio) == 4)
            fwrite(&registro, sizeof(registro), 1, archB);
    }
    fclose(archT);
    fclose(archB);
}

void cargarListaCircular(TListaC *LC)
{
    TListaC pri, nuevo;
    FILE *archivo;
    char CodigoLote[5];
    float PrecioBase;

    archivo = fopen("Archivos/listaCircular.txt", "rt");
    while (fscanf(archivo, "%s %f", CodigoLote, &PrecioBase) == 2)
    {
        nuevo = (TListaC)malloc(sizeof(nodoC));
        strcpy(nuevo->CodigoLote, CodigoLote);
        nuevo->PrecioBase = PrecioBase;
        if (*LC == NULL)
            *LC = pri = nuevo;
        else
        {
            (*LC)->sig = nuevo;
            *LC = nuevo;
        }
    }
    (*LC)->sig = pri;
    fclose(archivo);
}

void cargarLista(TLista *L, TListaC LC)
{
    TLista nuevo, ult;
    TListaC aux = LC->sig;
    TSubLista nodito;
    char vc[5];
    TRegistro registro;
    FILE *archivo;
    float minOferta, maxOferta;

    archivo = fopen("Archivos/OFERTAS.DAT", "rb");
    while (fread(&registro, sizeof(registro), 1, archivo) == 1)
    {
        if (*L == NULL || strcmp(registro.CodigoLote, vc) != 0)
        {
            strcpy(vc, registro.CodigoLote);
            nuevo = (TLista)malloc(sizeof(nodo));
            strcpy(nuevo->CodigoLote, registro.CodigoLote);
            nuevo->ofertasM = nuevo->ofertasT = NULL;
            nuevo->sig = NULL;
            if (*L == NULL)
                *L = ult = nuevo;
            else
            {
                while (strcmp(aux->CodigoLote, registro.CodigoLote) < 0)
                    aux = aux->sig;
                ult->PrecioRealEstimado = aux->PrecioBase + 0.2 * (minOferta + maxOferta) / 2;
                ult->sig = nuevo;
                ult = nuevo;
            }
            minOferta = INFINITO;
            maxOferta = -1;
        }
        nodito = (TSubLista)malloc(sizeof(SubNodo));
        strcpy(nodito->DocumentoOfertante, registro.DocumentoOfertante);
        nodito->PrecioOfertado = registro.PrecioOfertado;
        if (registro.medio == 'T')
        {
            nodito->sig = ult->ofertasT;
            ult->ofertasT = nodito;
        }
        else
        {
            nodito->sig = ult->ofertasM;
            ult->ofertasM = nodito;
        }
        if (registro.PrecioOfertado > maxOferta)
            maxOferta = registro.PrecioOfertado;
        if (registro.PrecioOfertado < minOferta)
            minOferta = registro.PrecioOfertado;
    }
    ult->sig = NULL;
    fclose(archivo);
}

void cargarCola(TCola *CodigosLote)
{
    TElementoC x;
    FILE *archivo;
    archivo = fopen("Archivos/cola.txt", "rt");
    IniciaC(CodigosLote);
    while (fscanf(archivo, " %s", x.texto) == 1)
        PoneC(CodigosLote, x);
    fclose(archivo);
}

void eliminarVendidos(TLista *L, TCola *CodigosLote)
{
    TLista aux, ant;
    TElementoC x;
    FILE *archivo;
    TSubLista elim;
    unsigned int contador;

    archivo = fopen("Archivos/LOTESBAJA.TXT", "wt");
    if (archivo != NULL)
        while (!VaciaC(*CodigosLote))
        {
            contador = 0;
            aux = *L;
            ant = NULL;
            SacaC(CodigosLote, &x);
            while (strcmp(aux->CodigoLote, x.texto) < 0)
            {
                ant = aux;
                aux = aux->sig;
            }
            if (strcmp(aux->CodigoLote, x.texto) == 0)
            {
                if (ant == NULL)
                    *L = aux->sig;
                else
                    ant->sig = aux->sig;
                contador = 0;
                elim = aux->ofertasT;
                while (elim != NULL)
                {
                    contador++;
                    aux->ofertasT = elim->sig;
                    free(elim);
                    elim = aux->ofertasT;
                }
                elim = aux->ofertasM;
                while (elim != NULL)
                {
                    contador++;
                    aux->ofertasM = elim->sig;
                    free(elim);
                    elim = aux->ofertasM;
                }
                fprintf(archivo, "%s %u\n", aux->CodigoLote, contador);
                free(aux);
            }
        }
    fclose(archivo);
}