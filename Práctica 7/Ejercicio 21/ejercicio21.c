#include <stdio.h>
#include <stdlib.h>

typedef int TElementoA;
typedef struct nodo
{
    TElementoA dato;
    struct nodo *izq,*der;
} nodo;
typedef nodo *arbol;

void addnodo(arbol *a,TElementoA e);
void cargarArbol(arbol *a);
unsigned int grado(arbol a); // Grado de la raiz
TElementoA acumularK(arbol a, unsigned int K);
unsigned int contarK(arbol a, unsigned int K);
void promediarK(arbol a,unsigned int K, short int *error,float *promedio);

int main()
{
    arbol a;
    unsigned int K;
    short int error;
    float promedio;

    cargarArbol(&a);
    printf("Ingrese K: ");
    scanf("%u",&K);
    promediarK(a,K, &error,&promedio);
    if (error)
        printf("No hay nodos de grado %u.\n",K);
    else
        printf("Promedio de los nodos de grado %u: %5.2f\n",K,promedio);
    
    return 0;
}

void addnodo(arbol *a,TElementoA e){
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

unsigned int grado(arbol a){
    unsigned int contaHijos = 0;
    if(a!=NULL){
        a = a->izq;
        while (a != NULL)
        {
            contaHijos++;
            a = a->der;
        }
    }
    return contaHijos;
}

TElementoA acumularK(arbol a, unsigned int K){
    if (a == NULL)
        return 0;
    else
        return (a->dato)*(grado(a) == K) + acumularK(a->izq,K) + acumularK(a->der,K);
}

unsigned int contarK(arbol a, unsigned int K){
    if (a == NULL)
        return 0;
    else
        return (grado(a) == K) + contarK(a->izq,K) + contarK(a->der,K);
}

void promediarK(arbol a,unsigned int K, short int *error,float *promedio){
    unsigned int contador = contarK(a,K);
    if (contador == 0)
        *error = 1;
    else
    {
        *error = 0;
        *promedio = (float)acumularK(a,K)/contador;
    }
}