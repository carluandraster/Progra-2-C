#include <stdio.h>
#define MAX_VERTICES 10
#define INFINITO 64999

void cargarDigrafo(unsigned int DG[][MAX_VERTICES],unsigned int *N);
void Dijkstra(unsigned int DG[][MAX_VERTICES],unsigned int N,unsigned int origen, unsigned int destino,unsigned int P[]);
void camino(unsigned int P[],unsigned int N,unsigned int origen, unsigned int destino);

int main()
{
    unsigned int DG[MAX_VERTICES][MAX_VERTICES],P[MAX_VERTICES],N,origen,destino;

    cargarDigrafo(DG,&N);
    do
    {
        printf("Ingrese origen: ");
        scanf("%u",&origen);
    } while (origen > N || origen == 0);
    do
    {
        printf("Ingrese destino: ");
        scanf("%u",&destino);
    } while (destino > N || destino == 0);
    Dijkstra(DG,N,origen-1,destino-1,P);
    camino(P,N,origen,destino);

    return 0;
}

void cargarDigrafo(unsigned int DG[][MAX_VERTICES], unsigned int *N)
{
    unsigned int i, j;
    FILE *archivo;
    archivo = fopen("matriz.txt", "rt");
    fscanf(archivo, "%u", N);
    for (i = 0; i < *N; i++)
        for (j = 0; j < *N; j++)
            fscanf(archivo, "%u", &DG[i][j]);
    fclose(archivo);
}

void Dijkstra(unsigned int DG[][MAX_VERTICES],unsigned int N,unsigned int origen, unsigned int destino,unsigned int P[]){
    short int VV[N];
    unsigned int D[N],i,k,d,minAux;

    // Inicializcion
    for (i = 0; i < N; i++)
    {
        VV[i] = 0;
        if (DG[origen][i])
        {
            D[i] = DG[origen][i];
            P[i] = 0;
        }
        else
            D[i] = P[i] = INFINITO;
    }
    D[origen] = P[origen] = 0;
    VV[origen] = 1;

    // Algoritmo de Dijsktra
    while (!VV[destino])
    {
        minAux = INFINITO;
        for (i = 0; i < N; i++)
            if (D[i] < minAux && !VV[i])
            {
                minAux = D[i];
                k = i;
            }
        VV[k] = 1;
        for (i = 0; i < N; i++)
            if (!VV[i] && DG[k][i])
            {
                d = D[k] + DG[k][i];
                if (d<D[i])
                {
                    D[i] = d;
                    P[i] = k+1;
                }
            } 
    }
}

void camino(unsigned int P[],unsigned int N,unsigned int origen,unsigned int destino){
    if (P[destino-1] == 0)
        if (origen == destino)
            printf("%u",origen);
        else
            printf("%u %u ",origen,destino);
    else
    {
        camino(P,N,origen,P[destino-1]);
        printf("%u ",destino);
    }
    
}