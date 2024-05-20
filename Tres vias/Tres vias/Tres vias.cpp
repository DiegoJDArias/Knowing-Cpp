#include <iostream>
#include <compare>


// std::strong_ordering
class Point {
public:
    int x, y;

    // Constructor
    Point(int x, int y) : x(x), y(y) {}

    // Operador de comparación de tres vías
    auto operator<=>(const Point&) const = default;

    // Opcional: puedes definir la distancia al origen para usarla en otras funciones
    double distance() const {
        return std::sqrt(x * x + y * y);
    }
};


int main() {

    Point p1(3, 4);
    Point p2(1, 1);

    // Uso del operador de comparación de tres vías
    if (auto cmp = p1 <=> p2; cmp < 0) 
    {
        std::cout << "p1 es menor que p2\n";
    }
    else if (cmp > 0) 
    {
        std::cout << "p1 es mayor que p2\n";
    }
    else 
    {
        std::cout << "p1 es igual a p2\n";
    }

    return EXIT_SUCCESS;
}

// std::weak_ordering

#include <iostream>
#include <compare>

class Point {

public:
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    // Operador de comparación de tres vías con ordenación débil
    std::weak_ordering operator<=>(const Point& other) const {
        if (auto cmp = x <=> other.x; cmp != 0) return cmp;
        return y <=> other.y;
    }
};


int main() {

    Point p1(3, 4);
    Point p2(3, 5);

    if (auto cmp = p1 <=> p2; cmp < 0) 
    {
        std::cout << "p1 es menor que p2\n";
    }
    else if (cmp > 0) 
    {
        std::cout << "p1 es mayor que p2\n";
    }
    else 
    {
        std::cout << "p1 es igual a p2\n";
    }

    return EXIT_SUCCESS;
}

// std::partial_ordering

#include <iostream>
#include <compare>
#include <cmath>


class Point {
public:
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    // Operador de comparación de tres vías con ordenación parcial
    std::partial_ordering operator<=>(const Point& other) const {

        if (std::isnan(x) || std::isnan(other.x) || std::isnan(y) || std::isnan(other.y)) {
            return std::partial_ordering::unordered;
        }
        if (auto cmp = x <=> other.x; cmp != 0) return cmp;
        return y <=> other.y;
    }
};


int main() {

    Point p1(3, 4);
    Point p2(NAN, 5);

    if (auto cmp = p1 <=> p2; cmp == std::partial_ordering::unordered) {
        std::cout << "p1 y p2 no son comparables\n";
    }
    else if (cmp < 0) {
        std::cout << "p1 es menor que p2\n";
    }
    else if (cmp > 0) {
        std::cout << "p1 es mayor que p2\n";
    }
    else {
        std::cout << "p1 es igual a p2\n";
    }

    return EXIT_SUCCESS;
}

