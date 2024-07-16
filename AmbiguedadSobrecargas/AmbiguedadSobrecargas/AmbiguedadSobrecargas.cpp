#include <iostream>

void imprimir(int x)
{
    std::cout << x << "\n";
}

void imprimir(double d)
{
    std::cout << d << "\n" ;
}

int main()
{
    imprimir(5); // 5 es un int, así que coincide con imprimir(int)
    imprimir(6.7); // 6.7 es un double, así que coincide con imprimir(double)

    return 0;
}


#include <iostream>

void imprimir(int x)
{
    std::cout << x;
}

void imprimir(double d)
{
    std::cout << d;
}

int main()
{
    imprimir('a'); // char no coincide con int ó double
    imprimir(5l); // long no coincide con int ó double

    return 0;
}


void imprimir(int)
{
}
void imprimir(double)
{
}
int main()
{
    imprimir(0); // coincidencia exacta con imprimir(int)
    imprimir(3.4); // coincidencia exacta con imprimir(double)

    return 0;
}



void imprimir(const int)
{
}

void imprimir(double)
{

}

int main()
{
    int x{ 0 };
    imprimir(x); // x convertido trivialmente a const int

    return 0;



void imprimir(int)
{
}

void imprimir(double)
{
}

int main()
{
    imprimir('a'); // promovido para coincidir con imprimir(int)
    imprimir(true); // promovido para coincidir con imprimir(int)
    imprimir(4.5f); // promovido para coincidir con imprimir(double)

    return 0;
}

#include <string> // para std::string

void imprimir(double)
{
}

void imprimir(std::string)
{
}

int main()
{
    imprimir('a'); // 'a' convertido para coincidir con print(double)

    return 0;
}





// Aún no hemos visto clases, así que no es necesario entender todo
class X // Aquí definimos un nuevo tipo llamado X
{
public:
    operator int() { return 0; } // conversión definida por el usuario que 
                                 // convierte de X a int
};

void imprimir(int)
{
}

void imprimir(double)
{
}

int main()
{
    X x; // Aquí, creamos un objeto de tipo X (llamado x)
    imprimir(x); // x es convertido a tipo int usando la 
                 // conversión de X a int definida por el usuario

    return 0;
}

void foo()
{
}

int main()
{
    foo(); // correcto: coincidencia encontrada
    goo(); // error de compilación: sin coincidencias

    return 0;
}




void imprimir(int x)
{
}

void imprimir(double d)
{
}

int main()
{
    imprimir(7l); // 7l es tipo long

    return 0;
}


#include <iostream>

void imprimir(char c, int x)
{
    std::cout << 'a';
}

void imprimir(char c, double x)
{
    std::cout << 'b';
}

void imprimir(char c, float x)
{
    std::cout << 'c';
}

int main()
{
    imprimir('x', 'a');
}


