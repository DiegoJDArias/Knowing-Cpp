//VT 87. COD.001
#include <iostream>

void addUno(int y) // y es una copia de x
{
    ++y; // esto modifica la copia de x, no el objeto real x
}

int main()
{
    int x{ 3 };

    std::cout << "valor = " << x << '\n';

    addUno(x);

    std::cout << "valor = " << x << '\n'; // x no ha sido modificado

    return 0;
}



//VT 87. COD.002
#include <iostream>

void addUno(int& y) // y está vinculado al objeto real x
{
    ++y; // esto modifica el objeto real x
}

int main()
{
    int x{ 3 };

    std::cout << "valor = " << x << '\n';

    addUno(x);

    std::cout << "valor = " << x << '\n'; // x ha sido modificado

    return 0;
}


//VT 87. COD.003
#include <iostream>
#include <string>

void imprimirValor(int& y) // y solo acepta lvalues modificables
{
    std::cout << y << '\n';
}

int main()
{
    int x{ 5 };
    imprimirValor(x); // correcto: x es un lvalue modificable

    const int z{ 3 };
    imprimirValor(z); // error: z es un lvalue no modificable

    imprimirValor(4); // error: 4 es un rvalue

    return 0;
}



//VT 87. COD.004
#include <iostream>
#include <string>

void imprimirValor(const int& y) // y es ahora una referencia const
{
    std::cout << y << '\n';
}

int main()
{
    int x{ 3 };
    imprimirValor(x); // correcto: x es un lvalue modificable

    const int z{ 3 };
    imprimirValor (z); // correcto: z es un lvalue no-modificable

    imprimirValor(4); // correcto: 4 es un rvalue literal

    return 0;
}


//VT 87. COD.005
void addUno(const int& ref)
{
    ++ref; // no permitido: ref es const
}




//VT 87. COD.006
#include <string>

void foo(int a, int& b, const std::string& c)
{
}


int main()
{
    int x{ 3 };
    const std::string s{ "Hola, mundo" };

    foo(4, x, s);

    return 0;
}


//VT 87. COD.007
#include <iostream>

// Evalúa a true si el tipo (o el objeto) usa 2 o menor direcciones de memori por el valor de memoria
#define isSmall(T) (sizeof(T) <= 2 * sizeof(void*))

struct S
{
    double a, b, c;
};

int main()
{
    std::cout << std::boolalpha; // imprime true o false en lugar de 1 ó 0
    std::cout << isSmall(int) << '\n'; // true
    std::cout << isSmall(double) << '\n'; // true
    std::cout << isSmall(S) << '\n'; // false

    return 0;
}
