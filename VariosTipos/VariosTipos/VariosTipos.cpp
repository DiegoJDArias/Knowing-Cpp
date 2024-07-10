#include <iostream>

//plantilla de función abreviada
auto mayor(auto x, auto y)
{
    return (x > y) ? x : y;
}

/*plantilla de función clásica
template <typename T, typename U>
auto mayor(T x, U y)
{
    return (x > y) ? x : y;
}*/


int main()
{
    std::cout << mayor(6, 8.5) << '\n';

    return 0;
}













/*#include <iostream>

template <typename T, typename U>
auto mayor(T x, U y)
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << mayor(6, 8.5) << '\n';

    return 0;
}*/
























/*#include <iostream>

template <typename T, typename U> // estamos usando dos tipos parámetros de plantilla T y U                                
T mayor(T x, U y) // "x" puede resolver a tipo T, e "y" puede resolver a tipo U
{
    return (x > y) ? x : y; 
}

int main()
{
    std::cout << mayor(2, 3.5) << '\n'; // Tenemos un problema de estrechamiento por conversión aquí

    std::cout << mayor <double, int> (8.3, 6) << '\n';

    std::cout << mayor <int, double>(8.3, 6) << '\n'; //Aquí también estrechamiento pero explícito    

    return 0;
}*/





/*#include <iostream>
template <typename T>
T mayor(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << mayor<int>(6.5, 2) << '\n';  // compilación correcta

    return 0;
}*/


/*#include <iostream>

int mayor(int x, int y)
{
    return (x > y) ? x : y;
}

double mayor(double x, double y)
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << mayor(6.5, 2) << '\n';  

    return 0;
}*/







/*#include <iostream>

template <typename T>
T mayor(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << mayor(4, 7) << '\n';   // instanciará mayor(int, int)
    std::cout << mayor(4.5, 7.5) << '\n'; // instanciará mayor(double, double)

    return 0;
}*/




/*#include <iostream>

template <typename T>
T mayor(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << mayor(static_cast<double>(2), 3.5) << '\n'; // convierte el int a double 
                                                             //compilador instancia mayor(double, double)

    return 0;
}*/



/*#include <iostream>

double mayor(double x, double y)
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << mayor(2, 3.5) << '\n'; // el tipo del argumento int se convierte a double

    return 0;
}*/

/*#include <iostream>

template <typename T>
T mayor(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << mayor<double>(2, 3.5) << '\n'; // le proveemos un tipo real, así que
                                                //el compilador no tiene que deducir por argumentos

    return 0;
}*/









