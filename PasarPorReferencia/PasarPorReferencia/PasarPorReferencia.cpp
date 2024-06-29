//VT 86. COD. 001

#include <iostream>

void imprimirValor(int y)
{
    std::cout << y << '\n';
} // y es destruido aquí


int main()
{
    int x{ 7 };

    imprimirValor(x); // x es pasado por valor (copiado) en el parámetro y (poco costoso)

    return 0;
}


//VT 86. COD.002

#include <iostream>
#include <string>


void imprimirValor(std::string y)
{
    std::cout << y << '\n';
} // y se destruye aquí


int main()
{
    
    setlocale(LC_ALL, "es_ES.UTF-8");
    std::string x{ "¡Hola, mundo!" }; // x es un std::string

   imprimirValor(x); // x es pasado por valor (copiado) al parámetro y (costoso)

    return 0;
}


//VT 86. COD. 003
#include <iostream>
#include <string>

void imprimirValor(std::string& y) // tipo cambiado a std::string& (referencia)
{
    std::cout << y << '\n';
} // y es destruido aquí


int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    std::string x{ "¡Hola, mundo!" };

    imprimirValor(x); // x ahora se pasa por referencia al parámetro referencia y (sin costo)

    return 0;
}

