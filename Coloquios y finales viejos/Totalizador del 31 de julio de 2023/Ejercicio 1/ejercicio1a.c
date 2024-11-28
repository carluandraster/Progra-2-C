/*Verdedero, simplemente hay que poner 0 en las posiciones en las que A_N es infinito o 0 y 1 en las posiciones
ni nulas ni infinitas*/
#define MAX 20
#define INFINITO 29999

void generarMatrizCT(int A[][MAX], int N, int CT[][MAX]){
    int i,j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            CT[i][j] = A[i][j] != 0 && A[i][j] != INFINITO;
    // De esta forma, controlamos que entre i y j haya al menos un camino posible de longitud mayor a 0
}