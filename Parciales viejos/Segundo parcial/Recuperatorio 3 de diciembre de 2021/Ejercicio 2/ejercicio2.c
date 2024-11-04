#include <stdio.h>
#include "TDA N-ario/N-ario.h"

Nodo *crearNodo(TElementoA valor);
void cargarArbol(Arbol *a, Posicion *p);
int grado(Arbol a, Posicion p);
float promedio(Arbol a, Posicion p);
int contarSi(Arbol a, Posicion p);

int main()
{
    Arbol a;
    Posicion p;
    cargarArbol(&a, &p);
    printf("Cantidad de nodos de de grado menor al promedio de las claves de sus hijos: %d\n", contarSi(a, p));
    return 0;
}

// Crea un nodo en el arbol
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

// Inicializa el arbol
void cargarArbol(Arbol *a, Posicion *p)
{
    *a = crearNodo(1); // Raíz del árbol

    (*a)->hijoIzq = crearNodo(2);                         // Hijo más izquierdo de la raíz
    (*a)->hijoIzq->hermanoDer = crearNodo(3);             // Hermano derecho del primer hijo
    (*a)->hijoIzq->hermanoDer->hermanoDer = crearNodo(4); // Otro hermano

    // Agregamos hijos al nodo 2
    (*a)->hijoIzq->hijoIzq = crearNodo(5);
    (*a)->hijoIzq->hijoIzq->hermanoDer = crearNodo(6);

    // Agregamos un hijo al nodo 3
    (*a)->hijoIzq->hermanoDer->hijoIzq = crearNodo(7);

    // Agregamos hijos al nodo 4
    (*a)->hijoIzq->hermanoDer->hermanoDer->hijoIzq = crearNodo(8);
    (*a)->hijoIzq->hermanoDer->hermanoDer->hijoIzq->hermanoDer = crearNodo(9);

    *p = *a;
}

// Devuelve el grado del vertice en la posicion p
int grado(Arbol a, Posicion p)
{
    Posicion c;
    int contador = 0;
    if (Nulo(p))
        return -1;
    else
    {
        c = HijoMasIzq(p, a);
        while (!Nulo(c))
        {
            contador++;
            c = HermanoDer(c, a);
        }
        return contador;
    }
}

// Devuelve el promedio de las claves de los hijos de p
float promedio(Arbol a, Posicion p)
{
    Posicion c;
    int acumulador = 0, contador = 0;
    if (Nulo(p))
        return -1;
    else
    {
        c = HijoMasIzq(p, a);
        while (!Nulo(c))
        {
            contador++;
            acumulador += Info(c, a);
            c = HermanoDer(c, a);
        }
        if (contador != 0)
            return (float)acumulador / contador;
        else
            return -1;
    }
}

// Cuenta los nodos no hojas del arbol cuyo grado sea menor al promedio de las claves de sus hijos
int contarSi(Arbol a, Posicion p)
{
    int contador = 0;
    Posicion c;
    if (Nulo(p))
        return 0;
    else
    {
        c = HijoMasIzq(p, a);
        if (Nulo(c))
            return 0;
        else
        {
            contador += grado(a, p) < promedio(a, p);
            while (!Nulo(c))
            {
                contador += contarSi(a, c);
                c = HermanoDer(c, a);
            }
            return contador;
        }
    }
}