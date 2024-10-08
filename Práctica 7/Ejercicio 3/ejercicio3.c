#include <stdio.h>
#include <stdlib.h>

typedef int TElememtoA;
typedef struct nodo
{
    TElememtoA dato;
    struct nodo *izq;
    struct nodo *der;
} NODO;
typedef NODO *arbol;

void addnodo(arbol *a, TElememtoA e);
void cargarArbol(arbol *a);
int sumaMultiplo3(arbol a);
unsigned cantHojas(arbol a);
short esta(arbol a, int x);

int main()
{
    arbol a;
    int x;
    cargarArbol(&a);
    printf("Suma de todos los multiplos de 3: %d\n", sumaMultiplo3(a));
    printf("Cantidad de hojas: %u\n", cantHojas(a));
    printf("Ingrese un numero: ");
    scanf("%d", &x);
    printf(esta(a, x) ? "El valor recibido se encuentra en el arbol." : "El valor recibido no se encuentra en el arbol.");
    return 0;
}

void addnodo(arbol *a, TElememtoA e)
{
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void cargarArbol(arbol *a)
{
    addnodo(a, 5);
    addnodo(&(*a)->izq, 8);
    addnodo(&(*a)->izq->izq, 3);
    addnodo(&(*a)->izq->der, 6);
    addnodo(&(*a)->der, 4);
    addnodo(&(*a)->der->izq, 1);
    addnodo(&(*a)->der->izq->der, 2);
}

int sumaMultiplo3(arbol a)
{
    if (a == NULL)
        return 0;
    else
        return a->dato % 3 == 0 ? a->dato + sumaMultiplo3(a->izq) + sumaMultiplo3(a->der) : sumaMultiplo3(a->izq) + sumaMultiplo3(a->der);
}

unsigned cantHojas(arbol a)
{
    if (a == NULL)
        return 0;
    else if (a->izq == NULL && a->der == NULL)
        return 1;
    else
        return cantHojas(a->izq) + cantHojas(a->der);
}

short esta(arbol a, int x)
{
    if (a == NULL)
        return 0;
    else if (a->dato == x)
        return 1;
    else
        return esta(a->izq, x) || esta(a->der, x);
}