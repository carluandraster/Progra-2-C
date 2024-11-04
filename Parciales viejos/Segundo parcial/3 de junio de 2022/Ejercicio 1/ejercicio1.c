#include <stdio.h>
#include <stdlib.h>

typedef int TElementoA;
typedef struct nodo
{
    TElementoA dato;
    struct nodo *izq, *der;
} nodo;
typedef nodo *arbol;

void addnodo(arbol *a, TElementoA e);
void cargarArbol(arbol *a);
unsigned int grado(arbol a);
unsigned int sumarSi(arbol a, unsigned int K, unsigned int nivel);

int main()
{
    arbol a;
    unsigned int K;
    cargarArbol(&a);
    printf("Ingrese un nivel K: ");
    scanf("%u", &K);
    printf("Suma de todas las claves de grado impares y nivel menor a K: %u", sumarSi(a, K, 1));
    return 0;
}

void addnodo(arbol *a, TElementoA e)
{
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->izq = (*a)->der = NULL;
}

void cargarArbol(arbol *a)
{
    addnodo(a, 17);
    addnodo(&(*a)->izq, 3);
    addnodo(&(*a)->izq->izq, 1);
    addnodo(&(*a)->izq->izq->der, 2);
    addnodo(&(*a)->izq->izq->der->izq, 8);
    addnodo(&(*a)->izq->izq->der->izq->der, 24);
    addnodo(&(*a)->izq->der, 10);
    addnodo(&(*a)->izq->der->der, 23);
    addnodo(&(*a)->izq->der->der->izq, 5);
    addnodo(&(*a)->izq->der->der->izq->der, 22);
    addnodo(&(*a)->izq->der->der->der, 15);
    addnodo(&(*a)->izq->der->der->der->izq, 7);
    addnodo(&(*a)->izq->der->der->der->izq->der, 34);
    addnodo(&(*a)->izq->der->der->der->izq->der->izq, 21);
    addnodo(&(*a)->izq->der->der->der->izq->der->der, 40);
}

// Grado de la raiz
unsigned int grado(arbol a)
{
    unsigned int contador = 0;
    if (a == NULL)
        return 0;
    else
    {
        a = a->izq;
        while (a != NULL)
        {
            contador++;
            a = a->der;
        }
        return contador;
    }
}

unsigned int sumarSi(arbol a, unsigned int K, unsigned int nivel)
{
    if (a == NULL || nivel >= K)
        return 0;
    else
        return (grado(a) % 2) * a->dato + sumarSi(a->izq, K, nivel + 1) + sumarSi(a->der, K, nivel);
}