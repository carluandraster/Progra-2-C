#include <stdio.h>
#include "TDA N-ario/N-ario.h"

Nodo *crearNodo(TElementoA valor);
void cargarArbol(Arbol *a, Posicion *p);
int cumple(Arbol a, Posicion p);

int main()
{
    Arbol a;
    Posicion p;
    cargarArbol(&a, &p);
    printf(cumple(a, p) ? "Hay al menos un nodo cuyos hijos son mayores.\n" : "No hay ningun nodo cuyos hijos sean mayores.\n");
    return 0;
}

Nodo *crearNodo(TElementoA valor)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo != NULL)
    {
        nuevo->dato = valor;
        nuevo->hijoIzq = NULL;
        nuevo->hermanoDer = NULL;
    }
    return nuevo;
}

void cargarArbol(Arbol *a, Posicion *p)
{
    *a = crearNodo(3); // Raíz del árbol

    (*a)->hijoIzq = crearNodo(2);                         // Hijo más izquierdo de la raíz
    (*a)->hijoIzq->hermanoDer = crearNodo(1);             // Hermano derecho del primer hijo
    (*a)->hijoIzq->hermanoDer->hermanoDer = crearNodo(2); // Otro hermano

    // Agregamos hijos al nodo 2
    (*a)->hijoIzq->hijoIzq = crearNodo(1);
    (*a)->hijoIzq->hijoIzq->hermanoDer = crearNodo(1);

    // Agregamos un hijo al nodo 3
    (*a)->hijoIzq->hermanoDer->hijoIzq = crearNodo(-7);

    // Agregamos hijos al nodo 4
    (*a)->hijoIzq->hermanoDer->hermanoDer->hijoIzq = crearNodo(1);
    (*a)->hijoIzq->hermanoDer->hermanoDer->hijoIzq->hermanoDer = crearNodo(0);

    *p = *a;
}

int cumple(Arbol a, Posicion p)
{
    Posicion c = HijoMasIzq(p, a);
    TElementoA clavePadre = Info(p, a);

    if (Nulo(c))
        return 0;
    else
    {
        while (!Nulo(c) && Info(c, a) > clavePadre)
            c = HermanoDer(c, a);
        if (Nulo(c))
            return 1;
        else
        {
            c = HijoMasIzq(p, a);
            while (!Nulo(c) && !cumple(a, c))
                c = HermanoDer(c, a);
            return !Nulo(c);
        }
    }
}