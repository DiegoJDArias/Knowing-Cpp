
int nValor;
float fValor;

struct Cualquiera
{
    int n;
    float f;
};

int main()
{
    Cualquiera sValor;

    void* ptr; // ptr es un puntero void

    ptr = &nValor; // válido
    ptr = &fValor; // válido
    ptr = &sValor; // válido
}





#include <iostream>
int main()
{
    int valor{ 5 };
    void* voidPtr{ &valor };

    std::cout << *voidPtr << '\n'; // ilegal: indireccionar un puntero void

    int* intPtr{ static_cast<int*>(voidPtr) }; // pero, si hace cast de ese puntero void a un puntero int...

    std::cout << *intPtr << '\n'; // entonces podemos indireccionar el resultado
}



#include <iostream>

enum class Tipo
{
    tInt, // nota: no podemos usar aquí "int" porque es una palabra clave
    tFloat,
    tCString
};

void imprimirValor(void* ptr, Tipo tipo)
{
    switch (tipo)
    {
    case Tipo::tInt:
        std::cout << *static_cast<int*>(ptr) << '\n'; // cast a puntero int y lleva a cabo indirección
        break;
    case Tipo::tFloat:
        std::cout << *static_cast<float*>(ptr) << '\n'; // cast a puntero float y lleva a cabo indirección
        break;
    case Tipo::tCString:
        std::cout << static_cast<char*>(ptr) << '\n'; // cast a puntero char (no indirección)
        // std::cout tratará char* como un string C-style
        // si fueramos a llevar a cabo indirección con el resultado, deberíamos imprimir el char, al que apunta ptr
        break;
    default:
        "tipo no encontrado";
        break;

    }
}

int main()
{
    void* ptr{ nullptr };

    int nValor{ 3 };
    float fValor{ 1.5f };
    char szValor[]{ "Ivancinho8" };

    imprimirValor(&nValor, Tipo::tInt);
    imprimirValor(&fValor, Tipo::tFloat);
    imprimirValor(szValor, Tipo::tCString);
    imprimirValor(&nValor, Tipo::tCString);

    return 0;
}