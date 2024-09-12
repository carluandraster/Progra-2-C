typedef struct
{
    int Numerador;
    int Denominador;
} fraccion;

fraccion crear(int num, int den);
int numerador(fraccion f);
int denominador(fraccion f);
fraccion sumar(fraccion f1,fraccion f2);
fraccion restar(fraccion f1, fraccion f2);
fraccion multiplicar (fraccion f1, fraccion f2);
fraccion dividir (fraccion f1, fraccion f2);
fraccion simplificar(fraccion f);
short iguales(fraccion f1, fraccion f2);