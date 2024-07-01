#include <iostream>

int main()
{
    char x{ 'a' };    
    std::cout << x << '\n';  // imprime valor de x
    std::cout << &x << '\n'; // imprime dirección en memoria de x

    return 0;
}


#include <iostream>

int main()
{
    int x{ 5 };
    std::cout << x << '\n';  // imprime valor de x
    std::cout << &x << '\n'; // imprime dirección en memoria de x

    return 0;
}



#include <iostream>

int main()
{
    int x{ 5 };
    std::cout << x << '\n';  // imprime el valor de la variable x
    std::cout << &x << '\n'; // imprime la dirección en memoria de la variable x
    

    std::cout << *(&x) << '\n'; // imprime el valor en la dirección de memoria de la variable x 
                                //(paréntesis no son necesarios, pero facilitan la lectura)

    return 0;
}


#include <iostream>
int main()
{   
    int x{ 5 };
    int* ptr{ &x };

    std::cout <<  *ptr;


    return 0;
}



#include <iostream>
int main()
{
    int x{ 5 };

    int* ptr;        // un puntero no inicializado (dirección basura)
    int* ptr2{};     // un puntero nulo 
    int* ptr3{ &x }; // un puntero inicializado con la dirección de la variable x
    std::cout << *ptr3;

    return 0;
}

