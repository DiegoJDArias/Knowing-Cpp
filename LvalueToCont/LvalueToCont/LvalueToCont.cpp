
// VT 85. COD.001

int main()
{
    const int x{ 5 }; // x es un lvalue no-modificable (const)
    int& ref{ x }; // error: ref no puede vincularse a un lvalue no-modificable

    return 0;
}


// VT 85. COD.002
int main()
{
    const int x{ 3};    // x es un lvalue no-modificable
    const int& ref{ x }; // correcto: ref es es una referencia lvalue a un valor const

    return 0;
}


// VT 85. COD.003
#include <iostream>
int main()
{
    const int x{ 3 };    // x es un lvalue no-modificable
    const int& ref{ x }; // correcto: ref es una referencia lvalue a un valor const

    std::cout << ref;     // correcto: podemos acceder al objeto const
    ref = 6;              // error: no podemos modificar un objeto const

    return 0;
}


// VT 85. COD.004
#include <iostream>
int main()
{
    int x{ 3 };          // x es un lvalue modificable
    const int& ref{ x }; // correcto: podemos vincular una referencia const a un lvalue modificable

    std::cout << ref;  // correcto podemos acceder al objeto a través de nuestra referencia const

    ref = 7;          // error: no podemos modificar un objeto a través de una referencia const

    x = 6;          // correcto: x es un lvalue modificable, pero con su identificador  

    return 0;
}




// VT 85. COD.005
#include <iostream>

int main()
{
    const int& ref{ 3 }; // correcto: 3 es un rvalue

    std::cout << ref; // imprime 3

    return 0;
}



// VT 85. COD.006
#include <iostream>

int main()
{
    const int& ref{ 3 }; // El objeto temporal que contiene el valor 3 extiende 
                         //su  vida útil para que coincida con la referencia

    std::cout << ref; // Por tanto, podemos usarlo con seguridad aquí.

    return 0;
} // Tanto ref como el objeto temporal mueren aquí

