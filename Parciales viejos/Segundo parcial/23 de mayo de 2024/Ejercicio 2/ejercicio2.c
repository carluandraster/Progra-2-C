#include <stdio.h>
#include "TDA N-ario/N-ario.h"
#define INFINITO 64999

Nodo *crearNodo(TElementoA valor);
void cargarArbol(Arbol *a, Posicion *p);
unsigned int grado(Arbol A, Posicion p);
int cumple(Arbol A, Posicion p);

int main()
{
    Arbol A;
    Posicion p;
    cargarArbol(&A,&p);
    printf(cumple(A,p) ? "Existe al menos un nodo cuyos hijos tienen grado creciente.\n" : "Ningun nodo tiene hijos de grado creciente.\n");
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
    (*a)->hijoIzq->hijoIzq = crearNodo(5);
    (*a)->hijoIzq->hijoIzq->hermanoDer = crearNodo(6);

    // Agregamos un hijo al nodo 3
    (*a)->hijoIzq->hermanoDer->hijoIzq = crearNodo(7);
    // (*a)->hijoIzq->hermanoDer->hijoIzq->hermanoDer = crearNodo(7);

    // Agregamos hijos al nodo 4
    (*a)->hijoIzq->hermanoDer->hermanoDer->hijoIzq = crearNodo(8);
    (*a)->hijoIzq->hermanoDer->hermanoDer->hijoIzq->hermanoDer = crearNodo(9);

    *p = *a;
}

unsigned int grado(Arbol A, Posicion p){
    unsigned int contador;
    Posicion c;
    if (Nulo(p))
        return INFINITO;
    else
    {
        contador = 0;
        c = HijoMasIzq(p,A);
        while (!Nulo(c))
        {
            contador++;
            c = HermanoDer(c,A);
        }
        return contador;
    }
}

int cumple(Arbol A, Posicion p){
    int condicion = 0;
    unsigned int vc,grad;
    Posicion c,izq;
    izq = HijoMasIzq(p,A);
    if (Nulo(izq)) // Es hoja
        return 0;
    else{
        c = HermanoDer(izq,A);
        vc = grado(A,izq);
        grad = grado(A,c);
        while (!Nulo(c) && vc < grad)
        {
            vc = grad;
            c = HermanoDer(c,A);
            grad = grado(A,c);
        }
        if (vc < grad)
            return 1;
        else
        {
            c = izq;
            while (!Nulo(c) && !condicion)
            {
                condicion = condicion || cumple(A,c);
                c = HermanoDer(c,A);
            }
            return condicion;
        }
    }
}