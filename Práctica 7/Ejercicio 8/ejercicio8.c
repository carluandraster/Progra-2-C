#include <stdio.h>
#include <stdlib.h>

typedef char *TElementoA;
typedef struct nodo
{
    TElementoA dato;
    struct nodo *izq,*der;
} nodo;
typedef nodo *arbol;

void addnodo(arbol *a,TElementoA e);
void cargarArbol(arbol *a);
void mostrarNivel(arbol a,unsigned nivel, unsigned x);
void mostrarCompetidores(arbol a);

int main()
{
    arbol a;
    cargarArbol(&a);
    printf("Campeon: ");
    mostrarNivel(a,1,1);
    printf("\nFinalistas: ");
    mostrarNivel(a,1,2);
    printf("\nSemifinalistas: ");
    mostrarNivel(a,1,3);
    printf("\nLista de competidores: \n");
    mostrarCompetidores(a);
    return 0;
}

void addnodo(arbol *a,TElementoA e){
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void cargarArbol(arbol *a){
    addnodo(a, "Federer");
    addnodo(&(*a)->izq, "Federer");
    addnodo(&(*a)->izq->der, "Murray");
    addnodo(&(*a)->izq->izq, "Federer");
    addnodo(&(*a)->der, "Djokovic");
    addnodo(&(*a)->der->izq, "Thiem");
    addnodo(&(*a)->der->der,"Djokovic");
    addnodo(&(*a)->der->izq->der, "Medvedev");
    addnodo(&(*a)->der->izq->izq,"Thiem");
}

void mostrarNivel(arbol a,unsigned nivel, unsigned x){
    if (a != NULL)
        if (nivel == x)
            printf("%s ",a->dato);
        else{
            mostrarNivel(a->izq,nivel+1,x);
            mostrarNivel(a->der,nivel+1,x);
        }
}

void mostrarCompetidores(arbol a){
    if (a != NULL)
        if (a->izq == NULL && a->der == NULL)
            printf("%s ",a->dato);
        else{
            mostrarCompetidores(a->izq);
            mostrarCompetidores(a->der);
        }
}