#include <iostream>

int main()
{
    std::cout << 5+ 1; // La expresión 5 + 1 produce el valor 6

    return 0;
}


#include <iostream>

int main()
{
    int x{ 5 };
    int y{ 3 };
    int z =++x + y; // Esta expresión tiene el efecto lateral de incremenntar x
    std::cout << z <<'\n'; //Imprime 9
    std::cout << x << '\n'; // Imprime 6

    return 0;
}



#include <iostream>

int main()
{
    auto primero{ 8/ 2 }; // int / int => int
    auto segundo{ 16.0 / 6 }; // double / int => double

    return 0;
}



#include <iostream>

void imprimir(int x)
{
    std::cout << x;
}

int main()
{
    imprimir("hola"); // error: imprimirt() esperaba un argumento int, le pasamos un literal stringe 

    return 0;
}



int main()
{
    int x{};

    x = 5; // válido: podemos asignar el literal 5 a la variable x
    5 = x; // error: no podemos asignar el valor de x al literal 5
    return 0;
}


#include <iostream>

int main()
{
    int x{};
    // x es una expresión lvalue
    std::cout << x << '\n'; 

    return 0;
}


#include <iostream>

int main()
{
    int x{};
    const double d{};
    // x es una expresión lvalue modificable
    std::cout << x << '\n';
    // d es una expresión lvalue no-modificable
    std::cout << d << '\n'; 

    return 0;
}



#include <iostream>

int return5()
{
    return 5;
}


int main()
{
    // 5 es una expresión rvalue
    int x{ 5 }; 
    // 1.2 es una expresión rvalue
    const double d{ 1.2 };
    // x es una expresión lvalue modificable
    std::cout << x << '\n';
    // d es una expresión lvalue no-modificable
    std::cout << d << '\n';
    // return5() es una expresión rvalue (devuelto por valor)
    std::cout << return5() << '\n';
    // x + 1 es un rvalue
    std::cout << x + 1 << '\n';
    // resultado del static casting d a un int es un rvalue
    std::cout << static_cast<int>(d) << '\n'; 

    return 0;
}



int main()
{
    int x{};
    /* Asignación exige que el operando izquierdo sea una
    expresión lvalue modificable y el operando de la derecha 
    sea una expresión rvalue (o conversión implícita)*/

    x = 5; // válido: x es una expresión lvalue modificable 
           // y 5 es una expresión rvalue

    5 = x; // error: 5 es una expresión rvalue y x 
           //es una expresión lvalue modificable

    return 0;
}



int main()
{
    int x{ 6 };
    int y{ 4 };
    // y es un lvalue modificable, no un rvalue 
    // pero el compilador puede convertir implícitamente
    // de lvalue a rvalue (no al contrario)
    x = y; // esto es totalmente legal.

    return 0;
}


int main()
{
    int x{ 6};

    x = x + 1;

    return 0;
}

