#include <stdio.h>
#define MAXELEM 100

void ingresarVectores(int A[MAXELEM], unsigned int *N, int B[MAXELEM], unsigned int *M);
void mezclar(int A[MAXELEM], unsigned int N, unsigned i, int B[MAXELEM], unsigned int M, unsigned j, int C[MAXELEM * 2], unsigned int *Z);
void mostrarElementos(int VECTOR[MAXELEM * 2], unsigned int N);

short main()
{
    int A[MAXELEM], B[MAXELEM], C[MAXELEM * 2];
    unsigned N, M, Z;
    ingresarVectores(A, &N, B, &M);
    Z = 0;
    mezclar(A, N, 0, B, M, 0, C, &Z);
    mostrarElementos(C, Z);
    return 0;
}

void ingresarVectores(int A[MAXELEM], unsigned int *N, int B[MAXELEM], unsigned int *M)
{
    FILE *archivo;
    unsigned i;
    archivo = fopen("vectores.txt", "rt");
    fscanf(archivo, "%u %u", N, M);
    for (i = 0; i < *N; i++)
        fscanf(archivo, "%d", &A[i]);
    for (i = 0; i < *M; i++)
        fscanf(archivo, "%d", &B[i]);
}

void mezclar(int A[MAXELEM], unsigned int N, unsigned i, int B[MAXELEM], unsigned int M, unsigned j, int C[MAXELEM * 2], unsigned int *Z)
{
    if (i == N - 1 && j < M - 1)
    {
        C[*Z] = B[j];
        ++*Z;
        mezclar(A, N, i, B, M, j + 1, C, Z);
    }
    else if (j == M - 1 && i < N - 1)
    {
        C[*Z] = A[i];
        ++*Z;
        mezclar(A, N, i + 1, B, M, j, C, Z);
    }
    else
    {
        /* code */
    }

    C[*Z] = A[i] < B[j] ? A[i] : B[j];
    ++*Z;

    if (A[i] == B[j])
    {
        i++;
        j++;
    }
    else
    {
        /* code */
    }

    if (i < N - 1 || j < M - 1)
        mezclar(A, N, i, B, M, j, C, Z);
}

void mostrarElementos(int VECTOR[MAXELEM], unsigned int N)
{
    if (N > 1)
        mostrarElementos(VECTOR, N - 1);
    printf("%d ", VECTOR[N - 1]);
}