#include <stdio.h>
#include "../Implementacion/N-ario.h"

Nodo *crearNodo(TElementoA valor);
void cargarArbol(Arbol *a, Posicion *p);
unsigned int cantidadNodos(Arbol a, Posicion p);
unsigned int cantidadClavesPares(Arbol a, Posicion p);
float porcentajeClavesPares(Arbol a, Posicion p);
unsigned int gradoDeUnNodo(Arbol a, Posicion p);
void GRADO(Arbol a, Posicion p, unsigned int *grado);
unsigned int nodosGradoImparEnNivelesImpares(Arbol a, Posicion p, unsigned int nivel);
short int cumple(Arbol a, Posicion p);
void CUMPLE(Arbol a, short int *Cumple);
float promedioSi(Arbol a, unsigned int K, unsigned int nivel);

int main()
{
    Arbol a;
    short int Cumple;
    unsigned int K, grado = 0;
    Posicion p;

    cargarArbol(&a, &p);
    printf("Cantidad de nodos: %u\n", cantidadNodos(a, p));                     // Inciso a
    printf("Porcentaje de claves pares: %f %%\n", porcentajeClavesPares(a, p)); // Inciso b
    // Inciso c
    GRADO(a, p, &grado);
    printf("Grado del arbol: %u\n", grado);
    // Inciso d
    printf("Cantidad de nodos de grado impar en niveles impares: %u\n", nodosGradoImparEnNivelesImpares(a, p, 1));
    // Inciso e
    printf(cumple(a, p) ? "(Funcion int) Para todas las claves salvo las de las hojas, su valor numerico es igual a la cantidad de hijos.\n" : "(Funcion int) Existen claves cuyos valores numericos no son iguales a sus cantidades de hijos.\n");
    CUMPLE(a, &Cumple);
    printf(Cumple ? "(Funcion void) Para todas las claves salvo las de las hojas, su valor numerico es igual a la cantidad de hijos.\n" : "(Funcion void) Existen claves cuyos valores numericos no son iguales a sus cantidades de hijos.\n");
    // Inciso f
    printf("Ingrese un nivel K: ");
    scanf("%u", &K);
    printf("Promedio de las claves del nivel K: %5.2f", promedioSi(a, K, 1));

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

unsigned int cantidadNodos(Arbol a, Posicion p)
{
    unsigned int contador = 0;
    Posicion c;

    if (!Nulo(p))
    {
        contador = 1;
        c = HijoMasIzq(p, a);
        while (c != NULL)
        {
            contador += 1 + cantidadNodos(a, HijoMasIzq(c, a));
            c = HermanoDer(c, a);
        }
    }

    return contador;
}

unsigned int cantidadClavesPares(Arbol a, Posicion p)
{
    unsigned int contador = 0;
    Posicion c;

    if (!Nulo(p))
    {
        contador = Info(p, a) % 2 == 0;
        c = HijoMasIzq(p, a);
        while (c != NULL)
        {
            contador += (Info(c, a) % 2 == 0) + cantidadClavesPares(a, HijoMasIzq(c, a));
            c = HermanoDer(c, a);
        }
    }

    return contador;
}

float porcentajeClavesPares(Arbol a, Posicion p)
{
    return (float)cantidadClavesPares(a, p) / cantidadNodos(a, p) * 100;
}

unsigned int gradoDeUnNodo(Arbol a, Posicion p)
{
    unsigned int contador = 0;
    Posicion c;

    if (!Nulo(p))
    {
        c = HijoMasIzq(p, a);
        while (!Nulo(c))
        {
            contador++;
            c = HermanoDer(c, a);
        }
    }
    return contador;
}

void GRADO(Arbol a, Posicion p, unsigned int *grado)
{
    Posicion c;
    unsigned int contador = 0;

    if (!Nulo(p))
    {
        c = HijoMasIzq(p, a);
        while (c != NULL)
        {
            contador++;
            GRADO(a, c, grado);
            c = HermanoDer(c, a);
        }
        if (contador > *grado)
            *grado = contador;
    }
}

unsigned int nodosGradoImparEnNivelesImpares(Arbol a, Posicion p, unsigned int nivel)
{
    Posicion c;
    unsigned int contador = 0;

    if (!Nulo(p))
    {
        contador = gradoDeUnNodo(a, p) % 2 == 1 && nivel % 2 == 1;
        c = HijoMasIzq(p, a);
        while (!Nulo(c))
        {
            contador += nodosGradoImparEnNivelesImpares(a, c, nivel + 1);
            c = HermanoDer(c, a);
        }
    }

    return contador;
}

short int cumple(Arbol a, Posicion p)
{
    Posicion c;
    short int aux = 1;

    if (!Nulo(p))
        if (Info(p, a) == gradoDeUnNodo(a, p))
        {
            c = HijoMasIzq(p, a);
            while (!Nulo(c) && aux)
            {
                aux = aux && cumple(a, c);
                c = HermanoDer(c, a);
            }
        }
        else
            return 0;

    return aux;
}