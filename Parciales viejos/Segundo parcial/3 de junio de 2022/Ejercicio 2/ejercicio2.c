#include <stdio.h>
#include "TDA N-ario/N-ario.h"

Nodo *crearNodo(TElementoA valor);
void cargarArbol(Arbol *a, Posicion *p);
unsigned int grado(Arbol a, Posicion p);
short int esVocal(char);
short int cumple(Arbol a, Posicion p);

int main()
{
    Arbol a;
    Posicion p;

    cargarArbol(&a, &p);
    printf(cumple(a, p) ? "Existe al menos un nodo no hoja de grado par cuya clave sea vocal y sus hijos tambien lo sean.\n" : "Para ningun nodo no hoja de grado par cuya clave sea vocal se cumple que todos sus hijos tambien lo sean.\n");

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

// Carga el arbol
void cargarArbol(Arbol *a, Posicion *p)
{
    *a = crearNodo('C'); // Raíz del árbol

    (*a)->hijoIzq = crearNodo('B');                         // Hijo más izquierdo de la raíz
    (*a)->hijoIzq->hermanoDer = crearNodo('A');             // Hermano derecho del primer hijo
    (*a)->hijoIzq->hermanoDer->hermanoDer = crearNodo('D'); // Otro hermano

    // Agregamos hijos al nodo B
    (*a)->hijoIzq->hijoIzq = crearNodo('E');
    (*a)->hijoIzq->hijoIzq->hermanoDer = crearNodo('F');

    // Agregamos un hijo al nodo A
    (*a)->hijoIzq->hermanoDer->hijoIzq = crearNodo('O');
    (*a)->hijoIzq->hermanoDer->hijoIzq->hermanoDer = crearNodo('u');

    // Agregamos hijos al nodo D
    (*a)->hijoIzq->hermanoDer->hermanoDer->hijoIzq = crearNodo('I');
    (*a)->hijoIzq->hermanoDer->hermanoDer->hijoIzq->hermanoDer = crearNodo('J');

    *p = *a;
}

unsigned int grado(Arbol a, Posicion p)
{
    unsigned int contador = 0;
    Posicion c;
    if (Nulo(p))
        return 0;
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

short int esVocal(char letra)
{
    return letra == 'A' || letra == 'a' || letra == 'E' || letra == 'e' || letra == 'I' || letra == 'i' || letra == 'O' || letra == 'o' || letra == 'U' || letra == 'u';
}

short int cumple(Arbol a, Posicion p)
{
    Posicion c;
    short int condicion = 0;

    if (Nulo(p))
        return 0;
    if (grado(a, p) % 2 == 0 && esVocal(Info(p, a)))
    {
        c = HijoMasIzq(p, a);
        if (Nulo(c)) // p es hoja
            return 0;
        while (!Nulo(c) && grado(a, c) % 2 == 0 && esVocal(Info(c, a)))
            c = HermanoDer(c, a);
        if (Nulo(c))
            return 1;
    }
    c = HijoMasIzq(p, a);
    while (!Nulo(c) && !condicion)
    {
        condicion = condicion || cumple(a, c);
        c = HermanoDer(c, a);
    }
    return condicion;
}