#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCAR 20

typedef struct nodo
{
    char nombre[MAXCAR];
    struct nodo *sig, *contenido; // Si el nodo es un archivo o carpeta vacía, contenido = NULL
} nodo;
typedef nodo *TLista;

void addnodo(TLista *L, char nombre[]);
void addnodito(TLista *L, char nombre[]);
void cargarLista(TLista *L);
void mostrarContenido(TLista L, char carpeta[]);

int main()
{
    TLista L = NULL;
    char nombre[MAXCAR];
    cargarLista(&L);
    printf("Ingrese una carpeta: ");
    scanf(" %s", nombre);
    mostrarContenido(L, nombre);
    return 0;
}

void addnodo(TLista *L, char nombre[])
{
    TLista nuevo;
    nuevo = (TLista)malloc(sizeof(nodo));
    strcpy(nuevo->nombre, nombre);
    nuevo->sig = *L;
    nuevo->contenido = NULL;
    *L = nuevo;
}

void addnodito(TLista *L, char nombre[])
{
    TLista nuevo;
    nuevo = (TLista)malloc(sizeof(nodo));
    strcpy(nuevo->nombre, nombre);
    nuevo->sig = (*L)->contenido;
    nuevo->contenido = NULL;
    (*L)->contenido = nuevo;
}

void cargarLista(TLista *L)
{
    addnodo(L, "Ejercicio_3");
    addnodito(L, "ejercicio3.c");
    addnodito(L, "ejercicio3.exe");
    addnodo(L, "Ejercicio_2");
    addnodito(L, "ejercicio2.c");
    addnodito(L, "ejercicio2.exe");
    addnodo(L, "Ejercicio_1");
    addnodito(L, "Inciso c");
    addnodito(&(*L)->contenido, "ejercicio1c.c");
    addnodito(&(*L)->contenido, "ejercicio1c.exe");
    addnodito(L, "Inciso b");
    addnodito(&(*L)->contenido, "ejercicio1b.c");
    addnodito(&(*L)->contenido, "ejercicio1b.exe");
    addnodito(L, "Inciso a");
    addnodito(&(*L)->contenido, "ejercicio1a.c");
    addnodito(&(*L)->contenido, "ejercicio1a.exe");
}

void mostrarContenido(TLista L, char carpeta[])
{
    TLista aux = L;
    while (aux != NULL && strcmp(aux->nombre, carpeta))
        aux = aux->sig;
    if (aux == NULL)
        printf("No se encontro a la carpeta\n");
    else
    {
        printf("Contenido de %s: \n", aux->nombre);
        aux = aux->contenido;
        while (aux != NULL)
        {
            printf("%s\n", aux->nombre);
            aux = aux->sig;
        }
    }
}