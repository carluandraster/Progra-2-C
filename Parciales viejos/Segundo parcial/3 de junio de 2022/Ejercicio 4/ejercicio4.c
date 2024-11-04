/*4.a) Hay 4 aristas: 2 en la clase de 1, 1 en la clase de 3 y 1 en la
clase de 9
b) i) Para que se incluya la arista (i,j) en el AAM, tiene que ser
una arista de peso mínimo que no encierre un ciclo
ii)*/

#include <stdio.h>

void actualizarCC(unsigned int CC[], unsigned int N, unsigned int i, unsigned int j);
void mostrarVector(unsigned int CC[], unsigned int N);

int main()
{
    unsigned int CC[10] = {1, 1, 3, 4, 1, 3, 7, 8, 9, 9};
    actualizarCC(CC, 10, 1, 3);
    mostrarVector(CC, 10);
    return 0;
}

void actualizarCC(unsigned int CC[], unsigned int N, unsigned int i, unsigned int j)
{
    unsigned int k, ccAux;
    if (CC[i - 1] < CC[j - 1])
    {
        ccAux = CC[j - 1];
        for (k = 0; k < N; k++)
            if (CC[k] == ccAux)
                CC[k] = CC[i - 1];
    }
    else
    {
        ccAux = CC[i - 1];
        for (k = 0; k < N; k++)
            if (CC[k] == ccAux)
                CC[k] = CC[j - 1];
    }
}

void mostrarVector(unsigned int CC[], unsigned int N)
{
    unsigned int i;
    printf("CC = ");
    for (i = 0; i < N; i++)
        printf("%u ", CC[i]);
}