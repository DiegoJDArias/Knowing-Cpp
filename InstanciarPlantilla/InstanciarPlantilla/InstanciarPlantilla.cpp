#include <iostream>

template <typename T>
T mayor(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << mayor<int>(1, 2) << '\n'; // instancia y llama a la función mayor<int>(int, int)  
    

    return 0;
}


#include <iostream>

template <typename T>
T mayor(T x, T y) // plantilla función para mayor(T, T)
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << mayor<int>(7, 5) << '\n'; // instancia y llama a la función mayor<int>(int, int)
    std::cout << mayor<int>(2, 6) << '\n'; // llama a la función ya instanciada mayor<int>(int, int)
    std::cout << mayor<double>(8, 2) << '\n'; // instancia y llama a la función mayor<double>(double, double)

    return 0;
}



#include <iostream>

template <typename T>
T mayor(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << mayor<int>(3, 2) << '\n'; // instancia mayor<int>
    std::cout << mayor<>(3, 2) << '\n'; // deduce mayor<int>(int, int) 
    std::cout << mayor(3, 2) << '\n'; // deduce mayor(int, int)

    return 0;
}

#include <iostream>
template <typename T>
T retorno(T x, double y)
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << retorno(2, 4.5) <<'\n'; // coincide con retorno(int, double)
    std::cout << retorno(2, 4.5f) << '\n'; // coincide con retorno(int, double) -- float promovido a double
    std::cout << retorno(2.3, 4.5) << '\n'; // coincide con retorno(double, double)
    std::cout << retorno(2.3f, 4.5) << '\n'; // coincide con retorno(float, double)
    std::cout << retorno(2.3f, 4.5f) << '\n'; // coincide con retorno(float, double) -- float es promovido a double 



    return 0;
}

#include <iostream>
template <typename T>
T retorno(T x, double y)
{
    return (x > y) ? x : y;
}

int main()
{
    int a = retorno(2, 4.5); // coincide con retorno(int, double)
    int b = retorno(2, 4.5f); // coincide con retorno(int, double) -- float promovido a double
    int c = retorno(2.3, 4.5); // coincide con retorno(double, double)
    int d = retorno(2.3f, 4.5); // coincide con retorno(float, double)
    int e = retorno(2.3f, 4.5f); // coincide con retorno(float, double) -- float es promovido a double

    std::cout << a << '\n';
    std::cout << b << '\n';
    std::cout << c << '\n';
    std::cout << d << '\n';
    std::cout << e << '\n';



    return 0;
}


#include <iostream>
template <typename T>
double retorno(T x, double y)
{
    return (x>y) ? x:y;
}

int main()
{
    double a= retorno(2, 4.5); // coincide con retorno(int, double)
    double b= retorno(2, 4.5f); // coincide con retorno(int, double) -- float promovido a double
    double c= retorno(2.3, 4.5); // coincide con retorno(double, double)
    double d= retorno(2.3f, 4.5); // coincide con retorno(float, double)
    double e= retorno(2.3f, 4.5f); // coincide con retorno(float, double) -- float es promovido a double

    std::cout << a << '\n';
    std::cout << b << '\n';
    std::cout << c << '\n';
    std::cout << d << '\n';
    std::cout << e << '\n';



    return 0;
}


#include <iostream>

template <typename T>
T sumarUno(T x)
{
    return x + 1;
}

int main()
{
    std::cout << sumarUno(1) << '\n';
    std::cout << sumarUno(2.3) << '\n';

    return 0;
}


#include <iostream>
#include <string>

template <typename T>
T sumarUno(T x)
{
    return x + 1;
}

int main()
{
    std::string hola{ "Hola, mundo" };
    std::cout << sumarUno(hola) << '\n';

    return 0;
}


#include <iostream>
#include <string>

template <typename T>
T sumarUno(T x);

template<>
std::string sumarUno<std::string>(std::string x)
{
    return x + 1;
}

int main()
{
    std::string hola{ "Hola Mundo" };
    std::cout << sumarUno(hola) << '\n';

    return 0;
}