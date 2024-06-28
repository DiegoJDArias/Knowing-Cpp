
//VT 89. COD.001
int main()
{
    int x{ 3 };
    int* ptr{ &x }; // ptr es un puntero normal (no-const)

    int y{ 6 };
    ptr = &y; // podemos cambiar para apuntar a otro valor

    *ptr = 7; // podemos cambiar el valor de la dirección que almacena

    return 0;
}


//VT 89. COD.002
int main()
{
    const int x{ 3 }; // x es un int constante 
    int* ptr{ &x };   // error de compilación: 
                      //no podemos convertir de const int* a int*

    return 0;
}


//VT 89. COD.003
int main()
{
    const int x{ 3 };
    const int* ptr{ &x }; // correcto: ptr está apuntando a un  "const int"

    *ptr = 7; // no permitido: no podemos cambiar un valor const

    return 0;
}



//VT 89. COD.004

int main()
{
    const int x{ 3 };
    const int* ptr{ &x }; // ptr apunta a const int x

    const int y{ 7 };
    ptr = &y; // correcto: ptr ahora apunta a const int y


    return 0;
}


//VT 89. COD.005
int main()
{
    int x{ 3 }; // no-const
    const int* ptr{ &x }; // ptr apunta a "const int"

    *ptr = 7;  // no permitido: ptr apunta a un valor "const int" 
               //así que no podemos cambiar su valor a través de ptr
    x = 7; // permitido: la variable x sigue siendo no-const, así que 
           //su valor es modificable a través de su identificador x

    return 0;
}


//VT 89. COD.006
int main()
{
    int x{ 3 };
    int* const ptr{ &x }; // const después del asterisco significa 
                          //que es un puntero constante

    return 0;
}


//VT 89. COD.007
int main()
{
    int x{ 3 };
    int y{ 7 };

    int* const ptr{ &x }; // correcto: el puntero const se 
                          //inicializa a la dirección de x
    ptr = &y; // error: una vez inicializado, un 
              //puntero const no puede ser cambiado.

    return 0;
}


//VT 89. COD.008
int main()
{
    int x{ 3 };
    int* const ptr{ &x }; // ptr siempre apuntará a x

    *ptr = 7; // correcto: el valor al que apunta es no-const

    return 0;
}



//VT 89. COD.009
int main()
{
    int valor{ 3 };
    const int* const ptr{ &valor }; // un puntero constante a un valor constante

    return 0;
}



//VT 89. COD.010
int main()
{
    int valor{ 3 };

    int* ptr0{ &valor };             // ptr0 apunta a un "int" y él mismo es no-const, 
                                     //así que es un puntero normal.
    const int* ptr1{ &valor };       // ptr1 apunta a un "const int", pero él mismo es 
                                     //no-const, así que es un puntero a un valor constante.
    int* const ptr2{ &valor };       // ptr2 apunta a un "int", pero él mismo es const, así 
                                     //que es un puntero const (a un valor no-const).
    const int* const ptr3{ &valor }; // ptr3 apunta a un "const int", y él mismo es const, 
                                     //así que es un puntero const a un valor const.

    return 0;
}

//VT 89. COD.010
int main()
{
    int valor{ 3 };

    int* ptr0{ &valor };

    const int* ptr1{ &valor };

    int* const ptr2{ &valor };

    const int* const ptr3{ &valor }; 


    return 0;
}



//VT 89. COD.011
#include <iostream>
int main()
{
    const int x{ 3 };
    const int* ptr{ &x }; // ptr apunta a const int x

    const int y{ 7 };
    ptr = &y; // correcto: ptr ahora apunta a const int y
    std::cout << *ptr;


    return 0;
}
