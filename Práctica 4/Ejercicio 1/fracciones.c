#include "fracciones.h"

// Funciones auxiliares

unsigned RESTO (int dividendo, int divisor){
    if (dividendo>0)
        return divisor<0 ? dividendo % -divisor : dividendo % divisor;
    else
        if (dividendo<0)
            return divisor<0 ? -divisor + dividendo % divisor : divisor + dividendo % divisor;
        else
            return 0;
}

unsigned mcd(int a, int b){
    unsigned resto;
    if (b!=0)
    {
        do
        {
            resto = RESTO(a,b);
            a = b;
            b = resto;
        } while (resto!=0);
        return a;
    }
    else
        return a>=0 ? a : -a;  
}

unsigned mcm(int a, int b){
    unsigned maxComDiv=mcd(a,b);
    if (maxComDiv!=0)
        return a*b>=0 ? a*b / maxComDiv : -a*b / maxComDiv;
    else
        return 0;
}

// Funciones propias de la librería

fraccion crear(int num, int den){
    fraccion fracAux;
    fracAux.Numerador = num;
    fracAux.Denominador = den;
    return fracAux;
}

int numerador(fraccion f){
    return f.Numerador;
}

int denominador(fraccion f){
    return f.Denominador;
}

fraccion simplificar(fraccion f){
    unsigned MCD = mcd(numerador(f),denominador(f));
    f.Numerador/=MCD;
    f.Denominador/=MCD;
    return crear(f.Numerador,f.Denominador);
}

fraccion sumar(fraccion f1,fraccion f2){
    unsigned MCM = mcm(denominador(f1),denominador(f2));
    return simplificar(crear(numerador(f1)*MCM/denominador(f1)+numerador(f2)*MCM/denominador(f2),MCM));
}

fraccion restar(fraccion f1,fraccion f2){
    unsigned MCM = mcm(denominador(f1),denominador(f2));
    return simplificar(crear(numerador(f1)*MCM/denominador(f1)-numerador(f2)*MCM/denominador(f2),MCM));
}

fraccion multiplicar(fraccion f1,fraccion f2){
    return simplificar(crear(numerador(f1)*numerador(f2),denominador(f1)*denominador(f2)));
}

fraccion dividir(fraccion f1,fraccion f2){
    return simplificar(crear(numerador(f1)*denominador(f2),denominador(f1)*numerador(f2)));
}

short iguales(fraccion f1,fraccion f2){
    return numerador(f1)*denominador(f2) == numerador(f2)*denominador(f1);   
}