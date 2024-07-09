
// VT 79 COD.001
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	char texto[]{ "Cualquier texto." };
	std::string str{ texto };
	std::string otro{ str };	

	std::cout << texto << ' ' << str << ' ' << otro << '\n';

	return 0;
}


//VT 79 COD.002
#include <iostream>
#include <string_view>

int main()
{
	std::string_view texto{ "Cualquier texto." }; // ve el texto "Cualquier texto", almacenado en un binario
	std::string_view str{ texto }; // ve el mismo "Cualquier texto"
	std::string_view otro{ str }; // ve el mismo "Cualquier texto"

	std::cout << texto << ' ' << str << ' ' << otro << '\n';

	return 0;
}



//VT 79 COD.0O3
#include <iostream>
#include <string_view>

int main()
{
	std::string_view str{ "Estoy viendo coches" };

	std::cout << str.length() << '\n'; // 19. Devuelve tamaño string
	std::cout << str.substr(0, str.find(' ')) << '\n'; // Estoy. Devuelve substring desde primer carácter a primer espacio en blanco.
	std::cout << (str == "Estoy viendo coches") << '\n'; // 1. Devuelve true

	// Desde C++20
	std::cout << str.starts_with("Sigo") << '\n'; // 0 // Devuelve false
	std::cout << str.ends_with("coches") << '\n'; // 1// Devuelve true

	std::cout << str << '\n'; // Estoy viendo coches

	return 0;
}


//VT 79 COD.004
#include <iostream>
#include <string_view>

int main()
{
	char arr[]{ "Cara" };
	std::string_view str{ arr };

	std::cout << str << '\n'; // Cara

	// Cambia 'r' a 's' en arr
	arr[2] = 's';

	std::cout << str << '\n'; // Casa

	return 0;
}


//VT 79 COD.005
#include <iostream>
#include <string_view>

int main()
{
	std::string_view str{ "Ventana" };

	std::cout << str << '\n';

	// Ignora el primer carácter.
	str.remove_prefix(1);

	std::cout << str << '\n';

	// Ignora los 2 últimos caracteres.
	str.remove_suffix(2);

	std::cout << str << '\n';

	return 0;
}


//VT 79 COD.006
#include <iostream>
#include <string>
#include <string_view>

std::string_view preguntarNombre()
{
	
	std::cout << "Escribe tu nombre\n";

	// Usamos un std::string, porque std::cin necesita modificarlo.
	std::string nombre{};
	std::cin >> nombre;

	// vamos cambiar a std::string_view solo para fines demostrativos.
	// no tiene ninguna ventaja práctica
	std::string_view vista{ nombre };

	std::cout << "Hola " << vista << '\n';

	return vista;
} // nombre sale de alcance y termina su vida útil.


int main()
{
	
	std::string_view vista{ preguntarNombre() };

	// vista está mirando a un string que ya no existe.
	std::cout << "Tu nombre es " << vista<< '\n'; // Comportamiento indefinido

	return 0;
}


//VT 79 COD.007
#include <iostream>
#include <string>
#include <string_view>

std::string preguntarNombre()
{

	std::cout << "Escribe tu nombre\n";

	
	std::string nombre{};
	std::cin >> nombre;

	
	std::string vista{ nombre };

	std::cout << "Hola " << vista << '\n';

	return vista;
} // nombre sale de alcance y termina su vida útil.



int main()
{

	std::string vista{ preguntarNombre() };

	// vista ya no mira a un string que ya no existe, sino que ahora almacena su valor. 
	std::cout << "Tu nombre es " << vista << '\n'; // Comportamiento ahora correcto

	return 0;
}


//VT 79 COD.008

#include <iostream>
#include <string>
#include <string_view>

void imprimirS(std::string imp)
{
	std::cout << imp << '\n';
}

void imprimirSV(std::string_view imp)
{
	std::cout << imp << '\n';
}


int main()
{
	std::string_view geo{ "coordenadas" };

	 //imprimirS(geo); // error de compilación no se convierte implícitamente
	imprimirSV(geo); // correcto
	std::string str{ geo }; // str se inicializa con el valor que mira geo
	imprimirS(str); // correcto
	imprimirSV(str);// correcto
	imprimirS(static_cast<std::string>(geo)); // correcto

	return 0;
}
