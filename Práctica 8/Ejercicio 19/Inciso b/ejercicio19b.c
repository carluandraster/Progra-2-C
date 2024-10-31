#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10

typedef char TElementoG;
typedef struct TVertice
{
    TElementoG id;
    struct TVertice *sig;
} TVertice;

void agregarRelacion(TVertice DG[], unsigned int N, TElementoG vertice, TElementoG e);
void cargarGrafo(TVertice DG[], unsigned int *N);
void alcanza(TVertice DG[],unsigned int N, TElementoG origen,TElementoG destino, short int VV[], short int *cumple);

int main()
{
    TVertice DG[MAX_VERTICES];
    unsigned int i,N;
    TElementoG origen,destino;
    short int VV[MAX_VERTICES],cumple = 0;

    // Inicializar variables
    cargarGrafo(DG,&N);
    for (i = 0; i < N; i++)
        VV[i] = 0;

    // Ingresar datos
    do
    {
        printf("Ingrese origen: ");
        scanf(" %c",&origen);
    } while (origen > 65 + N || origen <65);
    VV[origen-65] = 1;
    do
    {
        printf("Ingrese destino: ");
        scanf(" %c",&destino);
    } while (destino > 65 + N || destino <65);

    // Respuesta
    alcanza(DG,N,origen,destino,VV,&cumple);
    printf(cumple ? "El destino es alcanzable desde el origen.\n" : "El destino no es alcanzable desde el origen.\n");

    return 0;
}

void agregarRelacion(TVertice DG[MAX_VERTICES], unsigned int N, TElementoG vertice, TElementoG e)
{
    unsigned i = 0;
    TVertice *aux, *ant;

    while (i < N && DG[i].id != vertice)
        i++;
    if (i < N)
    {
        aux = (TVertice *)malloc(sizeof(TVertice));
        aux->id = e;
        aux->sig = NULL;
        ant = &DG[i];
        while (ant->sig != NULL)
            ant = ant->sig;
        ant->sig = aux;
    }
}

void cargarGrafo(TVertice DG[], unsigned int *N){
    unsigned i;
    *N = 6;

    for (i = 0; i < *N; i++)
    {
        DG[i].id = i+65;
        DG[i].sig = NULL;
    }

    agregarRelacion(DG,*N,'A','C');
    agregarRelacion(DG,*N,'A','E');
    agregarRelacion(DG,*N,'B','A');
    agregarRelacion(DG,*N,'B','D');
    agregarRelacion(DG,*N,'C','E');
    agregarRelacion(DG,*N,'E','F');
}

void alcanza(TVertice DG[],unsigned int N, TElementoG origen,TElementoG destino, short int VV[], short int *cumple){
    TVertice *aux;
    if (origen == destino)
        *cumple = 1;
    else
    {
        aux = DG[origen-65].sig;
        while (aux != NULL && !*cumple)
        {
            if (!VV[aux->id - 65])
            {
                VV[aux->id - 65] = 1;
                alcanza(DG,N,aux->id,destino,VV,cumple);
            }
            aux = aux->sig;
        } 
    }
}