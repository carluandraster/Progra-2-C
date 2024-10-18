#include <stdio.h>
#include <stdlib.h>

typedef unsigned int TElementoA;
typedef struct nodo
{
    TElementoA dato;
    struct nodo *izq,*der;
} nodo;
typedef nodo *arbol;

void addnodo(arbol *a,TElementoA e);
void cargarArbol(arbol *a);
unsigned int grado(arbol a); // Grado de la raiz
short int tieneNodoSi (arbol a,unsigned int K);
short int todosTienenNodoSi(arbol a, unsigned int K);

int main()
{
    arbol a;
    unsigned int K;

    cargarArbol(&a);
    printf("Ingrese un grado K: ");
    scanf("%u",&K);
    printf(todosTienenNodoSi(a,K) ? "Se verifica que todos los arboles del bosque tiene al menos un nodo de grado K." : "Existen arboles del bosque que no tienen nodos de grado K.");

    return 0;
}

void addnodo(arbol *a,TElementoA e){
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

unsigned int grado(arbol a){
    unsigned int contador = 0;
    if(a!=NULL)
    {
        a = a->izq;
        while (a != NULL)
        {
            contador++;
            a = a->der;
        } 
    }
    return contador;
}

short int tieneNodoSi (arbol a,unsigned int K){
    if (a == NULL)
        return 0;
    else
        if (grado(a) == K)
            return 1;
        else
            return tieneNodoSi(a->izq,K) || tieneNodoSi(a->der,K);
}

short int todosTienenNodoSi(arbol a, unsigned int K){
    while (a != NULL && (grado(a) == K || tieneNodoSi(a->izq,K)))
        a = a->der;
    return a==NULL;
}