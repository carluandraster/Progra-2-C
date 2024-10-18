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
unsigned int altura(arbol a);
unsigned int cantArboles(arbol a, unsigned int K);

int main()
{
    arbol a;
    unsigned int K;

    cargarArbol(&a);
    printf("Ingrese una altura K: ");
    scanf("%u", &K);
    printf("Cantidad de arboles de al menos altura %u: %u", K, cantArboles(a, K));

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
    addnodo(a, 23);
    addnodo(&(*a)->izq, 4);
    addnodo(&(*a)->izq->izq, 1);
    addnodo(&(*a)->izq->der, 5);
    addnodo(&(*a)->izq->der->der, 6);
    addnodo(&(*a)->izq->der->der->izq, 7);
    addnodo(&(*a)->izq->der->der->izq->der, 2);
    addnodo(&(*a)->der, 33);
    addnodo(&(*a)->der->izq, 40);
    addnodo(&(*a)->der->izq->der, 44);
    addnodo(&(*a)->der->izq->der->izq, 46);
    addnodo(&(*a)->der->izq->der->izq->izq, 50);
    addnodo(&(*a)->der->izq->der->izq->izq->der, 60);
    addnodo(&(*a)->der->der, 72);
    addnodo(&(*a)->der->der->izq, 9);
    addnodo(&(*a)->der->der->izq->der, 19);
    addnodo(&(*a)->der->der->izq->der->der, 29);
    addnodo(&(*a)->der->der->izq->der->der->izq, 26);
    addnodo(&(*a)->der->der->izq->der->der->izq->der, 27);
    addnodo(&(*a)->der->der->izq->der->der->izq->der->der, 28);
}

unsigned int altura(arbol a)
{
    unsigned int altIzq, altDer;
    if (a == NULL)
        return 0;
    else
    {
        altIzq = altura(a->izq);
        altDer = altura(a->der);
        return altIzq >= altDer ? (a->izq != NULL) + altIzq : altDer;
    }
}

unsigned int cantArboles(arbol a, unsigned int K)
{
    arbol aux = a;
    unsigned int contador = 0;
    while (aux != NULL)
    {
        contador += 1 + altura(aux->izq) >= K;
        aux = aux->der;
    }
    return contador;
}