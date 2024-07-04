//VT 84 COD.001
int main()
{

	int x;     // un tipo int normal

	int& y;    // una referencia a un objeto int

	double& z; // una referencia a un objeto double
}


//VT 84 COD.002
#include <iostream>
int main()
{
    int x{ 3 };    // x es una variable int normal
    int& ref{ x }; // ref es una variable referencia lvalue 
                   // que puede ser usado como un alias para variable x

    std::cout << x << '\n';  // imprime el valor de x (3)
    std::cout << ref << '\n'; // imprime el valor de x a través de ref (3)

    return 0;
}


//VT 84 COD.003
#include <iostream>

int main()
{
    int x{ 3 }; // variable normal int
    int& ref{ x }; // ref es ahora un alias para la variable x

    std::cout << x << ref <<'\n'; // imprime 33

    x = 6; // x ahora tiene un valor 6

    std::cout << x << ref << '\n'; // imprime 66

    ref = 7; // el objeto que está siendo referenciado (x) ahora tiene valor 7

    std::cout << x << ref << '\n'; // imprime 77

    return 0;
}


//VT 84 COD.004
int main()
{
    int& refInvalida;   // error: las referencias deben inicializarse

    int x{ 3 };
    int& ref{ x }; // correcto: la referencia int está vinculada a variable int

    return 0;
}


//VT 84 COD.005
int main()
{
    int x{ 3 };
    int& ref{ x }; // correcto: la referencia int está vinculada a variable int

    double y{ 7.0 };
    int& refInvalida{ y }; // error; referencia a int no puede vincularse a variable double
    double& refInvalida2{ x }; // error: referencia a double no puede vincularse a variable int

    return 0;
}

//VT 84 COD.006


int main()
{
    int x{ 3 };
    int& ref{ x }; // válido: referencia vinculada a lvalue modificable

    const int y{ 3 };
    int& invalidRef{ y };  // error: no se puede vincular a lvalue no modificable
    int& invalidRef2{ 0 }; // error: no se puede vincular a un rvalue

    return 0;
}



//VT 84 COD.007
#include <iostream>


int main()
{
    int x{ 3 };
    int y{ 4 };

    int& ref{ x }; // ref es ahora un alias de x

    ref = y; // asignamos 4 (el valor de y) a x (el objeto referenciado por ref)
    // ¡¡ NO cambiamos ref para que sea una referencia a la variable y!!

    std::cout << x; // x tiene ahora el valor 4, no 3

    return 0;
}

//VT 84 COD.008
#include <iostream>


int main()
{
    int x{ 3 }; // integer normal
    int& ref{ x }; // referencia a variable x

    return 0;
} // x y ref mueren aquí


//VT 84 COD.009
#include <iostream>


int main()
{
    int x{ 3 };

    {
        int& ref{ x };   // ref es una referencia a x
        ref = 7; // tanto x como ref pasan a tener valor 7        
        std::cout << ref << '\n'; // imprime el valor 7
    } // ref es destruido aquí -- x no se ve afectado

    std::cout << x << '\n'; // sigue imprimiendo el valor 7

    return 0;
} // x destruido aquí

