#include <iostream>
#include <iterator>
#include <algorithm>
#include <conio.h>


bool verifica(char vocal)
{
    switch(vocal)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return true;
    default:
        return false;
    }
}

int main() {

    char nombre[]{ "Diego J D Arias" };
    int largoArray{static_cast<int>(std::size(nombre))};
    int numeroVocal{};

    for(char* ptr{nombre}; ptr != (nombre + largoArray); ++ptr)
    {
        if(verifica(*ptr))
        {
            ++numeroVocal;
        }
    }

    // auto numeroVocal{std::count_if(std::begin(nombre), std::end(nombre), verifica)}; //uso con la biblioteca <algorithm>

    std::cout << nombre << " Tiene " << numeroVocal << " Vocales " <<  std::endl;

    _Check_return_ _getch();
    return EXIT_SUCCESS;
}
