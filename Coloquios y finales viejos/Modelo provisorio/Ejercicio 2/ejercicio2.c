#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXCAR 20

typedef struct nodito
{
    char palabra[20];
    unsigned int apariciones;
    struct nodito *sig;
} nodito;
typedef nodito *TSubLista;
typedef nodito *TListaC;

typedef struct nodo
{
    char letra;
    TSubLista palabras;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;

void buscarLetra(TLista *L, char c, TLista *nuevo);
void buscarPalabra(TSubLista *palabras, char pal[], TSubLista *new);
void cargarLista(TLista *L);
void eliminarPalabra(TLista L, char X[MAXCAR]);
int esVocal(char c);
void insertar(TListaC *LC, char pal[], unsigned int apariciones);
void generarListaC(TLista L, TListaC *LC);
void mostrarLista(TListaC LC);

int main()
{
    TLista L = NULL;
    TListaC LC = NULL;
    char X[MAXCAR];

    cargarLista(&L);
    printf("Ingrese una palabra: ");
    scanf("%s", X);
    eliminarPalabra(L, X);
    generarListaC(L, &LC);
    mostrarLista(LC);

    return 0;
}

// Dada una letra, la busca en L. Si la encuentra, devuelve su posición. Caso contrario, crea un nodo
void buscarLetra(TLista *L, char c, TLista *nuevo)
{
    TLista aux;

    if (*L == NULL || c < (*L)->letra)
    {
        *nuevo = (TLista)malloc(sizeof(nodo));
        (*nuevo)->letra = c;
        (*nuevo)->palabras = NULL;
        (*nuevo)->sig = *L;
        *L = *nuevo;
    }
    else
    {
        aux = *L;
        if (aux->letra == c)
            *nuevo = aux;
        else
        {
            while (aux->sig != NULL && aux->sig->letra < c)
                aux = aux->sig;

            if (aux->sig != NULL && aux->sig->letra == c)
                *nuevo = aux->sig;
            else
            {
                *nuevo = (TLista)malloc(sizeof(nodo));
                (*nuevo)->letra = c;
                (*nuevo)->palabras = NULL;
                (*nuevo)->sig = aux->sig;
                aux->sig = *nuevo;
            }
        }
    }
}

void buscarPalabra(TSubLista *palabras, char pal[], TSubLista *new)
{
    TSubLista aux;

    if (*palabras == NULL || strcmp(pal, (*palabras)->palabra) < 0)
    {
        *new = (TSubLista)malloc(sizeof(nodito));
        strcpy((*new)->palabra, pal);
        (*new)->apariciones = 0;
        (*new)->sig = *palabras;
        *palabras = *new;
    }
    else
    {
        aux = *palabras;
        if (strcmp(aux->palabra, pal) == 0)
            *new = aux;
        else
        {
            while (aux->sig != NULL && strcmp(aux->sig->palabra, pal) < 0)
                aux = aux->sig;
            if (aux->sig != NULL && strcmp(aux->sig->palabra, pal) == 0)
                *new = aux->sig;
            else
            {
                *new = (TSubLista)malloc(sizeof(nodito));
                strcpy((*new)->palabra, pal);
                (*new)->apariciones = 0;
                (*new)->sig = aux->sig;
                aux->sig = *new;
            }
        }
    }
}

void cargarLista(TLista *L)
{
    TLista busc1;
    TSubLista busc2;
    FILE *archivo;
    char pal[MAXCAR];

    archivo = fopen("texto.txt", "rt");
    if (archivo != NULL)
        while (fscanf(archivo, " %s", pal) == 1)
        {
            buscarLetra(L, toupper(pal[0]), &busc1);
            buscarPalabra(&busc1->palabras, pal, &busc2);
            busc2->apariciones++;
        }
    fclose(archivo);
}

void eliminarPalabra(TLista L, char X[MAXCAR])
{
    TLista busc1;
    TSubLista aux, elim;
    buscarLetra(&L, toupper(X[0]), &busc1);
    if (busc1->palabras != NULL)
    {
        aux = busc1->palabras;
        if (strcmp(aux->palabra, X) == 0)
        {
            busc1->palabras = aux->sig;
            free(aux);
        }
        else
        {
            // Hay que eliminar aux->sig
            while (aux->sig != NULL && strcmp(aux->sig->palabra, X) < 0)
                aux = aux->sig;
            if (aux->sig != NULL && strcmp(aux->sig->palabra, X) == 0)
            {
                elim = aux->sig;
                aux->sig = elim->sig;
                free(elim);
            }
        }
    }
}

int esVocal(char c)
{
    c = toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void insertar(TListaC *LC, char pal[], unsigned int apariciones)
{
    TListaC nuevo;
    nuevo = (TListaC)malloc(sizeof(nodito));
    strcpy(nuevo->palabra, pal);
    nuevo->apariciones = apariciones;
    if (*LC == NULL)
        nuevo->sig = nuevo;
    else
    {
        nuevo->sig = (*LC)->sig;
        (*LC)->sig = nuevo;
    }
    *LC = nuevo;
}

void generarListaC(TLista L, TListaC *LC)
{
    TLista aux1 = L;
    TSubLista aux2;

    while (aux1 != NULL && aux1->letra <= 'U')
    {
        if (esVocal(aux1->letra))
        {
            aux2 = aux1->palabras;
            while (aux2 != NULL)
            {
                if (aux2->apariciones > 5)
                    insertar(LC, aux2->palabra, aux2->apariciones);
                aux2 = aux2->sig;
            }
        }
        aux1 = aux1->sig;
    }
}

void mostrarLista(TListaC LC)
{
    TListaC aux = LC;
    printf("Palabra\tApariciones\n");
    do
    {
        aux = aux->sig;
        printf("%s\t%u\n", aux->palabra, aux->apariciones);
    } while (aux != LC);
}