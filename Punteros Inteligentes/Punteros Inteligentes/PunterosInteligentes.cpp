

#include <iostream>
#include <memory>
#include <conio.h>

class MiClase 
{

public:
    MiClase() { std::cout << "Constructor de MiClase" << std::endl; }

    ~MiClase() { std::cout << "Destructor de MiClase" << std::endl; }

    void HacerAlgo() { std::cout << "Haciendo algo..." << std::endl; }
};


int main() 
{
    // Crear un unique_ptr
    std::unique_ptr<MiClase> punteroUnico = std::make_unique<MiClase>();

    // Utilizar el puntero
    punteroUnico->HacerAlgo();

    // No es necesario liberar la memoria manualmente, se hace automáticamente al salir del alcance
    _Check_return_ _getch();
    return 0;
}  // El destructor de std::unique_ptr se llama aquí, liberando automáticamente la memoria





#include <iostream>
#include <memory>
#include <conio.h>

class MiClase {
public:
    MiClase() {
        std::cout << "Constructor de MiClase" << std::endl;
    }

    ~MiClase() {
        std::cout << "Destructor de MiClase" << std::endl;
    }

    void HacerAlgo() {
        std::cout << "Haciendo algo..." << std::endl;
    }
};

int main() {
    // Crear un shared_ptr
    std::shared_ptr<MiClase> punteroCompartido1 = std::make_shared<MiClase>();

    // Crear otro shared_ptr que comparte el mismo recurso
    std::shared_ptr<MiClase> punteroCompartido2 = punteroCompartido1;

    // Utilizar los punteros
    punteroCompartido1->HacerAlgo();
    punteroCompartido2->HacerAlgo();

    // La memoria se libera automáticamente cuando el último puntero shared_ptr se destruye
    _Check_return_ _getch();
    return 0;
}  // El destructor de std::shared_ptr se llama aquí, liberando automáticamente la memoria si es necesario





/* std::weak_ptr es un puntero inteligente que no posee la propiedad del recurso al que apunta, pero puede observar
y acceder al recurso si aún existe. Esto es útil para evitar referencias circulares y posibles fugas de memoria al
trabajar con std::shared_ptr. Aquí tienes un ejemplo: */

#include <iostream>
#include <memory>

class MiClase;

// Definición de funciones que usan shared_ptr y weak_ptr
void ImprimirWeak(std::weak_ptr<MiClase> weak_ptr) {
    // Intentar bloquear (lock) el weak_ptr
    if (auto shared_ptr = weak_ptr.lock()) {
        std::cout << "El recurso sigue existiendo. Valor: " << shared_ptr->ObtenerValor() << std::endl;
    }
    else {
        std::cout << "El recurso ya no existe." << std::endl;
    }
}

class MiClase {
private:
    int valor;

public:
    MiClase(int val) : valor(val) {
        std::cout << "Constructor de MiClase. Valor: " << valor << std::endl;
    }

    ~MiClase() {
        std::cout << "Destructor de MiClase. Valor: " << valor << std::endl;
    }

    int ObtenerValor() const {
        return valor;
    }
};

int main() {
    // Crear un shared_ptr y un weak_ptr
    std::shared_ptr<MiClase> shared_ptr = std::make_shared<MiClase>(42);
    std::weak_ptr<MiClase> weak_ptr = shared_ptr;

    // Utilizar el shared_ptr
    std::cout << "Desde el shared_ptr: " << shared_ptr->ObtenerValor() << std::endl;

    // Utilizar el weak_ptr
    ImprimirWeak(weak_ptr);

    // Restablecer el shared_ptr
    shared_ptr.reset();

    // Utilizar el weak_ptr después de que el shared_ptr se ha restablecido
    ImprimirWeak(weak_ptr);

    return 0;
}  // Los destructores de MiClase se llaman aquí (en el orden correcto)

/* En este ejemplo:

Se crea un shared_ptr y un weak_ptr que comparten la propiedad del mismo objeto MiClase.
Se utiliza el shared_ptr para acceder al objeto y se llama a una función que toma un weak_ptr para imprimir el valor.
Se resetea el shared_ptr, lo que significa que ya no posee la propiedad del objeto.
Se llama a la función con el weak_ptr después de que el shared_ptr se ha reseteado, y se verifica si el objeto aún existe antes de intentar acceder a él.
Usar std::weak_ptr de esta manera ayuda a prevenir problemas relacionados con la gestión de la memoria al trabajar con std::shared_ptr.*/





#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Controller
{
public:
    int Num;
    wstring Status;
    vector<weak_ptr<Controller>> others;
    explicit Controller(int i) : Num(i), Status(L"On")
    {
        wcout << L"Creating Controller" << Num << endl;
    }

    ~Controller()
    {
        wcout << L"Destroying Controller" << Num << endl;
    }

    // Demonstrates how to test whether the
    // pointed-to memory still exists or not.
    void CheckStatuses() const
    {
        for_each(others.begin(), others.end(), [](weak_ptr<Controller> wp) {
            auto p = wp.lock();
            if (p)
            {
                wcout << L"Status of " << p->Num << " = " << p->Status << endl;
            }
            else
            {
                wcout << L"Null object" << endl;
            }
            });
    }
};

void RunTest()
{
    vector<shared_ptr<Controller>> v{
        make_shared<Controller>(0),
        make_shared<Controller>(1),
        make_shared<Controller>(2),
        make_shared<Controller>(3),
        make_shared<Controller>(4),
    };

    // Each controller depends on all others not being deleted.
    // Give each controller a pointer to all the others.
    for (int i = 0; i < v.size(); ++i)
    {
        for_each(v.begin(), v.end(), [&v, i](shared_ptr<Controller> p) {
            if (p->Num != i)
            {
                v[i]->others.push_back(weak_ptr<Controller>(p));
                wcout << L"push_back to v[" << i << "]: " << p->Num << endl;
            }
            });
    }

    for_each(v.begin(), v.end(), [](shared_ptr<Controller>& p) {
        wcout << L"use_count = " << p.use_count() << endl;
        p->CheckStatuses();
        });
}

int main()
{
    RunTest();
    wcout << L"Press any key" << endl;
    char ch;
    cin.getline(&ch, 1);

    return 0;
}

