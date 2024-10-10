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
int suma(arbol a,unsigned nivel,unsigned x);

int main()
{
    arbol a;
    unsigned x;

    cargarArbol(&a);
    printf("Ingrese un nivel: ");
    scanf("%u",&x);
    printf("Suma: %d\n",suma(a,1,x));

    return 0;
}

void addnodo(arbol *a,TElementoA e){
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void cargarArbol(arbol *a){
    addnodo(a,5);
    addnodo(&(*a)->izq,8);
    addnodo(&(*a)->izq->der,6);
    addnodo(&(*a)->der,4);
    addnodo(&(*a)->der->izq,1);
    addnodo(&(*a)->der->izq->der,2);
}

int suma(arbol a,unsigned nivel,unsigned x){
    if (a == NULL)
        return 0;
    else
        if (nivel == x)
            return a->izq == NULL && a->der != NULL || a->izq != NULL && a->der == NULL ? a->dato : 0;
        else
            return suma(a->izq,nivel+1,x)+suma(a->der,nivel+1,x);
        
}