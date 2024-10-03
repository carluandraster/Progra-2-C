#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCAR 20

typedef struct nodo
{
    char palabra[MAXCAR];
    unsigned frecuencia;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;

void cargarLista(TLista *L);
void imprimirLista(TLista L);

int main()
{
    TLista L = NULL;
    cargarLista(&L);
    imprimirLista(L);
    return 0;
}

void cargarLista(TLista *L)
{
    TLista aux, ult;
    FILE *archivo;
    char pal[MAXCAR];
    archivo = fopen("texto.txt", "rt");
    fscanf(archivo, "%s", pal);
    aux = (TLista)malloc(sizeof(nodo));
    *L = aux;
    strcpy(aux->palabra, pal);
    aux->frecuencia = 1;
    ult = aux;
    while (fscanf(archivo, "%s", pal) == 1)
    {
        aux = *L;
        while (aux != NULL && strcmp(aux->palabra, pal))
            aux = aux->sig;
        if (aux == NULL)
        {
            aux = (TLista)malloc(sizeof(nodo));
            strcpy(aux->palabra, pal);
            aux->frecuencia = 1;
            aux->sig = NULL;
            ult->sig = aux;
            ult = aux;
        }
        else
            aux->frecuencia++;
    }
    fclose(archivo);
}

void imprimirLista(TLista L)
{
    TLista aux = L;
    printf("Palabra\tFrecuencia\n");
    while (aux != NULL)
    {
        printf("%s\t%u\n", aux->palabra, aux->frecuencia);
        aux = aux->sig;
    }
}