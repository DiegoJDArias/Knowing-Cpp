//VT 88. COD.001
#include <iostream>

int main()
{
	int x{ 3 };
	std::cout << x; // imprime valor de variable x

	int* ptr{ &x }; // ptr contiene la dirección de x
	std::cout << *ptr; // con el operador de indirección imprimimos 
					   // el valor almacenado en la dirección de ptr 
					   // que es el valor de x (3).

	return 0;
}

//VT 88. COD.002
int main()
{
	int* ptr{}; // ptr es ahora un puntero nulo, 
				// no contiene ninguna dirección, 
				// pero no es un puntero colgante.

	return 0;
}


//VT 88. COD.003
#include <iostream>

int main()
{
	int* ptr{}; // ptr es un puntero nulo, no contiene ninguna dirección

	int x{ 3 };
	ptr = &x; // ptr ahora apunta al objeto x (ya no es un puntero nulo)

	std::cout << *ptr; // imprime el valor de x a través del operador de indirección

	return 0;
}


//VT 88. COD.004

void cualquierFuncion(int* x)
{
	//hacer algo
}

int main()
{
	int* ptr{ nullptr }; // podemos usar nullptr para inicializar un puntero como nulo
	int valor{ 3 };
	int* ptr2{ &valor }; // ptr2 es un puntero válido
	ptr2 = nullptr; // Podemos asignar nullptr para convertir un puntero en puntero nulo

	cualquierFuncion(nullptr); // podemos también pasar nullptr a una función que tenga un parámetro puntero

	return 0;
}


//VT 88. COD.005

#include <iostream>

int main()
{
	int* ptr{}; // Crea un puntero nulo
	std::cout << *ptr; // indirecciona el puntero nulo

	return 0;
}



//VT 88. COD.006
#include <iostream>

int main()
{
	int x{ 3 };
	int* ptr{ &x };

	// punteros se convierten a Boolean false si son null, y Boolean true si son no-null
	if (ptr == nullptr) // explicit test for equivalence
		std::cout << "ptr es null\n";
	else
		std::cout << "ptr es no-null\n";

	int* nullPtr{};
	std::cout << "nullPtr es " << (nullPtr == nullptr ? "null\n" : "no-null\n"); // usamos operador condicional

	return 0;
}


//VT 88. COD.007
#include <iostream>

int main()
{
	int x{ 3 };
	int* ptr{ &x };

	// Los punteros se convierten a boolean false si son null, y boolean true si son no-null
	if (ptr) // conversión implícita a Boolean
		std::cout << "ptr es no-null\n";
	else
		std::cout << "ptr es null\n";

	int* nullPtr{};
	std::cout << "nullPtr is " << (nullPtr ? "non-null\n" : "null\n"); // conversión implícita a boolean

	return 0;
}


#include <iostream>
int main() {
	int x{ 3 };
	int* ptr{ &x };

	if (ptr) // si ptr no es un puntero nulo
		std::cout << *ptr; // correcto para indireccionar
	else
		// hace algo que no sea indireccionar ptr (imprimir mensaje, no hacer nada...., etc...)
		std::cout << "indirección provocará error";
		
	return 0;

}


//VT 88. COD.008
int main()
{
	float* ptr{ 0 };  // ptr es ahora un puntero nulo (pero no hacerlo)

	float* ptr2; // ptr2 está sin inicializar
	ptr2 = 0; // ptr2 es ahora un puntero nulo (pero no hacerlo)

	return 0;
}


//VT 88. COD.009
#include <cstddef> // para NULL

int main()
{
	double* ptr{ NULL }; // ptr es un puntero nulo (pero no hacerlo)

	double* ptr2; // ptr2 está sin inicializar
	ptr2 = NULL; // ptr2 es ahora un puntero nulo (pero no hacerlo
}


//VT 88. COD.010
int main()
{
	int* ptr{ };


	{
		int x{ 5 };
		ptr = &x; // el puntero apunta a un objeto que será destruido al salir del bloque 
				  // esto no puede ocurrir con una referencia
	} // a partir de aquí x se destruye y ptr pasa a ser un puntero colgante

	return 0;
}

