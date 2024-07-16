
//Se omiten los cuerpos para mejor visualización
int sumar(int x, int y); // dos parámetros
int sumar(int x, int y, int z);// tres parámetros
int sumar(int x, int y); // versión int
double sumar(double x, double y); // versión floating point
double sumar(int x, double y); // versión mixta
double sumar(double x, int y); // versión mixta
double sumar(double x, int y, int z); //diferencia en número y tipos

using peso_t = double;  // creamos alias del tipo double

#include <string> // para std::string
#include <vector> // para std::vector
#include <utility> // para std::pair

bool esDuplicado(std::vector<std::pair<std::string, int>> listapares)
{
    // some code here
    return false;
}

int main()
{
    std::vector<std::pair<std::string, int>> listapares;

    return 0;
}

#include <string> // for std::string
#include <vector> // for std::vector
#include <utility> // for std::pair

using listapares_t = std::vector<std::pair<std::string, int>>; // hacemos listapares_t un alias 
                                                               //para este tipo enrevesado

bool esDuplicado(listapares_t pairlist) // usamos listapares_t en un parámetro de función
{
    // algo de código aquí
    return false;
}

int main()
{
    listapares_t listapares; // instanciamos una variable listapares_t

    return 0;
}


#ifdef INT_2_BYTES
using int8_t = char;
using int16_t = int;
using int32_t = long;
#else
using int8_t = char;
using int16_t = short;
using int32_t = int;
#endif


using peso_t = double;

typedef double peso_t;

int sumar(int x, int y) // dos parámetros
{
    return (x + y);
}

using masa_t = int;

int sumar(masa_t x, masa_t y)
{
    return(x + y);
}
int main()
{
    sumar(4, 8);
}

void imprimir(int)
{
    //hacer algo
}

void imprimir(const int)
{
    //hacer algo
}

int main()
{
    imprimir(6);
}

int getValorAleatorio()
{
    //hacerAlgo
}
double getValorAleatorio()
{
    //hacerAlgo
}

