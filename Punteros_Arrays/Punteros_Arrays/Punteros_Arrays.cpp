//VT 80. COD. 001
#include <iostream>

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");

    int array[5]{ 8, 2, 5, 6, 1 };    

    // imprime el valor del puntero al que decae el array
    std::cout << "El array decae a un puntero que contiene la dirección: " << array << '\n';

    // imprime la dirección del primer elemento del array
    std::cout << "Elemento 0 tiene la dirección: " << &array[0] << '\n';

    return 0;
}


//VT 80. COD. 002
#include <iostream>
int main()
{
    int array[5]{ 8, 2, 5, 6, 1 };

    // Indirección a través de un array devuelve el valor del primer elemento (elemento 0)
    std::cout << *array << '\n'; // imprimirá 8

    char nombre[]{ "Juan" }; // string estilo-C (también un array)
    std::cout << *nombre << '\n'; // imprimirá 'J'
}


//VT 80. COD. 003
#include <iostream>

int main()
{
    int array[5]{ 8, 2, 5, 6, 1 };
    std::cout << *array << '\n'; // imprimirá 8

    int* ptr{ array };
    std::cout << *ptr << '\n'; // imprimirá 8

    return 0;
}


//VT 80. COD. 004
#include <iostream>

int main()
{
    int array[5]{ 8, 2, 5, 6, 1 };

    std::cout << sizeof(array) << '\n'; // imprimirá sizeof(int) * array length

    int* ptr{ array };
    std::cout << sizeof(ptr) << '\n'; // imprimirá el tamaño de un puntero

    return 0;
}



//VT 80. COD. 005
#include <iostream>

int main()
{
    int array[5]{ 8, 2, 5, 6, 1 };
    std::cout << array << '\n';	 // tipo int[5], imprime 000000C1C8F3F6F8
    std::cout << &array << '\n'; // tipo int(*)[5], imprime 000000C1C8F3F6F8

    std::cout << '\n';

    int* ptr{ array };
    std::cout << ptr << '\n';	 // tipo int*, imprime 000000C1C8F3F6F8
    std::cout << &ptr << '\n';	 // tipo int**, imprime 000000C1C8F3F728

    return 0;
}


//VT 80. COD. 006
#include <iostream>

void imprimirTam(int* array)
{
    // array es tratado omo un puntero aquí
    std::cout << sizeof(array) << '\n'; // imprime el tamaño de un puntero, no el tamaño del array
    std::cout << &array << '\n';
}

int main()
{
    int array[]{ 4, 3, 1, 1, 8, 3, 24, 19 };
    std::cout << sizeof(array) << '\n'; // imprimirá sizeof(int) * array length
    std::cout << &array << '\n';

    imprimirTam(array); // el argumento array decae a un puntero aquí

    return 0;
}


//VT 80. COD. 006
#include <iostream>

// parametro ptr contiene una copia de la dirección del array
void cambiarArray(int* ptr)
{
    ptr[3] = 7; // así que si cambiamos un elemento del array cambiamos el array real
}

int main()
{
    int array[]{ 4, 3, 1, 1, 8, 3, 24, 19 };
    int* punt{ array };
    std::cout << "Elemento 3 tiene el valor: " << array[3] << '\n';
    cambiarArray(array);
    std::cout << "Elemento 3 tiene el valor: " << array[3] << '\n';
    

    return 0;
}
