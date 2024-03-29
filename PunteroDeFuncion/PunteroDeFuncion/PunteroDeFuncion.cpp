
#include <iostream>
#include <conio.h>

int ejemplo() // Se le asigna una dirección en memoria
{
    return 5;
}

int main()
{
    std::cout << ejemplo << '\n';//muestra dirección en memoria de ejemplo
    std::cout << ejemplo();  // salta a esa dirección en memoria y 
    //ejecuta su contenido

    _Check_return_ _getch();
    return 0;
}





#include <iostream>
// fcnPtr is a pointer to a function that takes no arguments and returns an integer


// int (* const ejemploPtr)();


// int* ejemploPtr();


int ejemplo()
{
    return 5;
}

int otroEjemplo()
{
    return 6;
}

int main()
{
    int (*ejemploPtr)() { &ejemplo }; // ejemploPtr apunta a la función ejemplo
    ejemploPtr = &otroEjemplo; // ejemploPtr ahora apunta a función otroEjemplo

    return 0;
}




// Declaración anticipada funciones
int primero();
double segundo();
int tercero(int x);

// Asignación punteros de función
int (*fcnPtr1)() { &primero }; // correcto
int (*fcnPtr2)() { &segundo }; // error -- tipos retorno distintos
double (*fcnPtr4)() { &segundo }; // correcto
fcnPtr1 = &tercero; // error -- fcnPtr1 no tiene parámetros, pero tercero() sí
int (*fcnPtr3)(int) { &tercero }; // correcto
int (*fcnptr)() { nullptr }; //correcto





#include <iostream>
#include <conio.h>

int ejemplo(int x)
{
    return x;
}

int main()
{
    int (*ejemploPtr)(int) { &ejemplo }; // Inicializa ejemploPtr con la función ejemplo
    int resultado = (*ejemploPtr)(3); // llama a la función ejemplo(3) a través de ejemploPtr.
    std::cout << resultado;

    _Check_return_ _getch();
    return 0;
}





#include <iostream>
int ejemplo(int x)
{
    return x;
}

int main()
{
    int (*ejemploPtr)(int) { &ejemplo }; // Inicializa ejemploPtr con la función ejemplo
    int resultado = ejemploPtr(5); // llama a la función ejemplo (3) a través de ejemploPtr.
    std::cout << resultado;

    return 0;
}





int ejemplo(int x)
{
    return x;
}

int main()
{
    int (*ejemploPtr)(int) { &ejemplo }; // Inicializa ejemploPtr con la función ejemplo
    if (ejemploPtr) // Se asegura que punteroPtr no es un puntero nulo
        ejemploPtr(5); // porque de serlo, esto provocaría un comportamient indefinido

    return 0;
}




#include <iostream>
#include <utility> // para std::swap
#include <conio.h>

void ordenSeleccion(int* array, int tamanio, bool (*fcnComparacion)(int, int))
{
    // se itera a traves de cada elemento del array, observa que la comparacion definida por el usuario
    // es el tercer parametro
    for (int indiceInicio{ 0 }; indiceInicio < (tamanio - 1); ++indiceInicio)
    {
        // mejorIndice es el inidce del elemento mas pequenio encontrado hasta ahora.
        int mejorIndice{ indiceInicio };

        //busca por eleento mas pequenio que quede en el arrya (empezando con indiceInicio + 1.
        for (int indiceActual{ indiceInicio + 1 }; indiceActual < tamanio; ++indiceActual)
        {
            // si el elemento actual es menor que el mas pequenio encontrado hasta ahora
            if (fcnComparacion(array[mejorIndice], array[indiceActual])) // AQUI SE HACE LA COMPARACION.
            {
                // este pasa a ser el numero mas pequenio para esta iteracion.
                mejorIndice = indiceActual;
            }
        }
         
        // Swap (intercambia) nuestro elemento de inicio con el elemento mas pequenio.
        std::swap(array[indiceInicio], array[mejorIndice]);
    }
}

// Esta es una funcion de comparacion que coloca en orden ascendente
// (Nota: es esactamente la misma que la funcion ascendente() anterior)
bool ascendente(int x, int y)
{
    return x > y;
}

bool descendente(int x, int y)
{
    return x < y;
}


// Esta funcion imprime los valores en el array.
void imprimirArray(int* array, int tamanio)
{
    for (int indice{ 0 }; indice < tamanio; ++indice)
    {
        std::cout << array[indice] << ' ';
    }

    std::cout << '\n';
}


int main()
{
    int array[9]{ 3, 7, 9, 5, 6, 1, 8, 2, 4 };

    std::cout << "Escribe 1 para ordenar descendente o 2 para orden ascendente: \n";

    int elegir{};
    std::cin >> elegir;
    if (elegir == 1)
    {
        // Coloca el array en orden descendente usando la funcion descendente().
        ordenSeleccion(array, 9, descendente);
        imprimirArray(array, 9);
    }
    else if (elegir == 2)
    {
        // Coloca el array en orden ascendente usando la fucion ascendente().
        ordenSeleccion(array, 9, ascendente);
        imprimirArray(array, 9);
    }
    else
        std::cout << "Escribe 1 o 2";

    _Check_return_ _getch();
    return 0;
}
