
#include <iostream>

void imprimir(int x, int y = 21) // 21  es el argumentos predeterminado
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}


#include <iostream>

void imprimir(int x, int y = 6) // 6 es el argumento predeterminado
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

int main()
{
    imprimir(9, 8); // y usará el argumento pasado por el llamador, 8
    imprimir(3); // y usará el argumento predeterminado, 6

}


#include <string>
int calculoCuadrado(int sides = 4)
{

}
void abrirArchivoLog(std::string nombrearchivo = "default.log")
{

}


#include <iostream>

void imprimir(int x = 1, int y = 10, int z = 100)
{
    std::cout << "Valores: " << x << " " << y << " " << z << '\n';
}

int main()
{
    imprimir(5, 4, 3); // todos argumentos explícitos
    imprimir(3, 30); // argumento más a la derecha predeterminado
    imprimir(20); // los dos argumentos más a la derecha predeterminados
    imprimir(); // todos los argumentos predeterminados

    imprimir( , , 6); //no permitido

    return 0;
}

void imprimir(int x = 10, int y) // no permitido
{
    //código
}


#include <iostream>

void imprimir(int x, int y = 4); // declaración anticipada

void imprimir(int x, int y = 4) // error: redefinición de argumento predeterminado
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

int main()
{
    imprimir(4);
}

#include "ArgumentosPredeterminados.h"
#include <iostream>

void imprimir(int x, int y)
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

int main()
{
    imprimir(7);

    return 0;
}

#include <iostream>
#include <string>
void imprimir(std::string string)
{
    std::cout << string << "\n";
}

void imprimir(char ch = 'b' )
{
    std::cout << ch << "\n";
}

int main()
{
    imprimir("Hola, mundo"); // resuelve a imprimir(std::string)
    imprimir('a'); // resuelve a imprimir(char)
    imprimir(); // resuelve a imprimir (char)

    return 0;
}

#include <iostream>
void imprimir(int x)
{
    std::cout << x<< "\n";
}
void imprimir(int x, int y = 10)
{
    std::cout << x <<", "<< y << "\n";
}
void imprimir(int x, double y = 20.5)
{
    std::cout << x << ", " << y << "\n";
}

int main()
{
    imprimir(1, 2); // resolverá para imprimir valores(int, int)
    imprimir(1, 2.5); // resolverá para imprimir valores(int, double)
    imprimir(1); // llamada a función ambigua
}
