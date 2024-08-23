#include <stdio.h>
#define MAXELEM 50

void ingresar(int V[], unsigned short int *N);
void duplicar(int V[], unsigned short int N);
void mostrar(int V[], unsigned short int N);

int main()
{
    int V[MAXELEM];
    unsigned short int N;

    ingresar(V, &N);
    duplicar(V, N);
    mostrar(V, N);

    return 0;
}

void ingresar(int V[], unsigned short int *N)
{
    unsigned short int i;
    printf("Ingrese cantidad de numeros: ");
    scanf("%u", N);
    for (i = 0; i < *N; i++)
    {
        printf("Ingrese numero para la posicion %d: ", i);
        scanf("%d", &V[i]);
    }
}

void duplicar(int V[], unsigned short int N)
{
    unsigned short int i = 0;
    do
    {
        V[i] *= 2;
        i += 2;
    } while (i < N);
}

void mostrar(int V[], unsigned short int N)
{
    unsigned short int i;
    printf("Vector: ");
    for (i = 0; i < N; i++)
        printf("%d \t", V[i]);
}