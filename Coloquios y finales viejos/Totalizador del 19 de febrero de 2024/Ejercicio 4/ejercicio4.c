#include <stdio.h>
#define N 7

int cumple(int A[][N], unsigned int K, unsigned int i, unsigned int j, unsigned int vc1, unsigned int vc2);

int main()
{
    int A[N][N] = {{0, 0, 1, 1, 1, 0, 0},  // A
                   {0, 0, 0, 0, 1, 1, 1},  // B
                   {1, 0, 0, 0, 0, 0, 1},  // C
                   {1, 0, 0, 0, 0, 1, 0},  // D
                   {1, 1, 0, 0, 0, 0, 0},  // E
                   {0, 1, 0, 1, 0, 0, 0},  // F
                   {0, 1, 1, 0, 0, 0, 0}}; // G
    unsigned int K;
    do
    {
        printf("Ingrese un numero K: ");
        scanf("%u", &K);
    } while (K > N);
    printf(cumple(A, K, 0, 0, 0, 0) ? "Los primeros K nodos tienen el mismo grado\n" : "Los primeros K nodos no tienen el mismo grado\n");
    return 0;
}

int cumple(int A[][N], unsigned int K, unsigned int i, unsigned int j, unsigned int vc1, unsigned int vc2)
{
    if (i < K)
    {
        if (j == N)
            if (i == 0 || vc1 == vc2)
                return cumple(A, K, i + 1, 0, vc2, 0);
            else
                return 0;
        else
            return cumple(A, K, i, j + 1, vc1, vc2 + A[i][j]);
    }
    else
        return 1;
}