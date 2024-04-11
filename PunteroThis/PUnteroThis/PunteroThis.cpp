#include <iostream>

class Simple
{
private:
    int m_id{};

public:
    Simple(int id) : m_id{ id }
    {
    }
    void setID(int id) { m_id = id; }
    int getID() { return m_id; }
};


int main()
{
    Simple simple{ 4 };
    Simple otroSimple{ 6 };
    otroSimple.setID(2);
    simple.setID(3);

    std::cout << simple.getID() << '\n';
    std::cout << otroSimple.getID() << '\n';

    return 0;
}



#include <iostream>

class Simple
{
private:
    int m_id{};

public:
    Simple(int id) : m_id{ id }
    {
    }
    void setID(int id) { m_id = id; }
    int getID() { return m_id; }
};


int main()
{
    Simple A{ 1 }; // this = &A dentro del constructor Simple
    Simple B{ 2 }; // this = &B dentro del constructor Simple
    A.setID(3); // this = &A dentro de la función miembro setID
    B.setID(4); // this = &B dentro de la función miembro setID

    return 0;
}



class Cualquiera
{
private:
    int datos;

public:
    Cualquiera(int datos)
    {
        this->datos = datos; // this->datos es el miembro, 
        //datos es el parámetro local
    }
};


#include <iostream>
class Calc
{
private:
    int m_valor{ 0 };

public:

    void sumar(int valor) { m_valor += valor; }
    void restar(int valor) { m_valor -= valor; }
    void mult(int valor) { m_valor *= valor; }

    int getValor() { return m_valor; }
};


int main()
{
    Calc calc{};
    calc.sumar(5); // devuelve void
    calc.restar(3); // devuelve void
    calc.mult(4); // devuelve void

    std::cout << calc.getValor() << '\n';
    return 0;
}


#include <iostream>
#include <conio.h>


class Calc
{
private:
    int m_valor{};

public:
    Calc& sumar(int valor) { m_valor += valor; return *this; }
    Calc& restar(int valor) { m_valor -= valor; return *this; }
    Calc& mult(int valor) { m_valor *= valor; return *this; }

    int getValor() { return m_valor; }
};


int main()
{
    Calc calc{};
    calc.sumar(5).restar(3).mult(4);

    std::cout << calc.getValor() << '\n';

    _Check_return_ _getch();
    return 0;
}

