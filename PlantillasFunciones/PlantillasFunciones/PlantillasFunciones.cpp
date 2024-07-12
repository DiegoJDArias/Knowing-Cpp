
template <typename T>
T mayor(T x, T y)
{
    return (x > y) ? x : y;
}


template<typename T>  //esta es la declaración del parámetro de plantilla
T mayor(T x, T y) //no compilará sin definir "T"
{
    return (x > y) ? x : y;
}


// definición de la plantilla de función
template <typename T>
T mayor(T x, T y)
{
    return (x > y) ? x : y;
}


// Instanciaciones de la plantilla de función
int mayor(int x, int y)
{
    return (x > y) ? x : y;
}

double mayor(double x, double y)
{
    return (x > y) ? x : y;
}


long mayor(long x, long y)
{
    return (x > y) ? x : y;
}

long double mayor(long double x, long double y)
{
    return (x > y) ? x : y;
}

long long mayor(long long x, long long y)
{
    return (x > y) ? x : y;
}

