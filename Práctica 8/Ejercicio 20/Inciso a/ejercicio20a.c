#include <stdio.h>
#define MAX_VERTICES 10

void cargarDigrafo(unsigned int DG[][MAX_VERTICES], unsigned int *N);
void alcanza(unsigned int DG[][MAX_VERTICES],unsigned int N, unsigned int origen,unsigned int destino, short int VV[], short int *cumple, unsigned int *cantVertices);

int main()
{
    unsigned int DG[MAX_VERTICES][MAX_VERTICES], i,N,cantVertices = 0;
    short int VV[MAX_VERTICES], cumple = 0;
    char origen,destino;

    cargarDigrafo(DG,&N);
    for (i = 0; i < N; i++)
        VV[i] = 0;
    
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
    alcanza(DG,N,origen-65,destino-65,VV,&cumple,&cantVertices);

    if (cumple)
    {
        printf("El destino es alcanzable desde el origen.\n");
        printf("El camino pasa por %u vertices\n",cantVertices);
    }
    else
        printf("El destino no es alcanzable desde el origen.\n");
    
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

void alcanza(unsigned int DG[][MAX_VERTICES],unsigned int N, unsigned int origen,unsigned int destino, short int VV[], short int *cumple, unsigned int *cantVertices){
    unsigned int i;
    if (origen == destino)
        *cumple = 1;
    else
    {
        i = 0;
        while (i<N && !*cumple)
        {
            if (DG[origen][i] > 0 && !VV[i]){
                VV[i] = 1;
                alcanza(DG,N,i,destino,VV,cumple,cantVertices);
            }
            i++;
        }
    }
    *cantVertices += *cumple;
}