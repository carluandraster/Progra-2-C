#include <stdio.h>
#define MAX_VERTICES 10
#define INFINITO 64999

void cargarDigrafo(unsigned int DG[][MAX_VERTICES],unsigned int *N);
void Floyd(unsigned int DG[][MAX_VERTICES],unsigned int N,unsigned int P[][MAX_VERTICES]);
void camino(unsigned int P[][MAX_VERTICES],unsigned int N,unsigned int v, unsigned int w);

int main()
{
    unsigned int DG[MAX_VERTICES][MAX_VERTICES],P[MAX_VERTICES][MAX_VERTICES],N,v,w;
    cargarDigrafo(DG,&N);
    Floyd(DG,N,P);
    do
    {
        printf("Ingrese origen: ");
        scanf("%u",&v);
    } while (v > N || v == 0);
    do
    {
        printf("Ingrese destino: ");
        scanf("%u",&w);
    } while (w > N || w == 0);
    camino(P,N,v,w);

    return 0;
}

void cargarDigrafo(unsigned int DG[MAX_VERTICES][MAX_VERTICES], unsigned int *N)
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

void Floyd(unsigned int DG[][MAX_VERTICES],unsigned int N,unsigned int P[][MAX_VERTICES]){
    unsigned int A[N][N],i,j,k;

    // Inicializar A y P
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (i == j)
                A[i][j] = P[i][j] = 0;
            else if (DG[i][j])
            {
                A[i][j] = DG[i][j];
                P[i][j] = 0;
            }
            else
                A[i][j] = P[i][j] = INFINITO;
            
    // Algoritmo de Floyd
    for (k = 0; k < N; k++)
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                if (A[i][k] + A[k][j] < A[i][j])
                {
                    A[i][j] = A[i][k] + A[k][j];
                    P[i][j] = k+1;
                }         
}

void camino(unsigned int P[][MAX_VERTICES],unsigned int N,unsigned int v, unsigned int w){
    if (P[v-1][w-1] == 0 && v == w)
        printf("%u ",v);
    else
    {
        camino(P,N,v,P[v-1][w-1]);
        printf("%u ",P[v-1][w-1]);
        camino(P,N,P[v-1][w-1],w);
    }
}