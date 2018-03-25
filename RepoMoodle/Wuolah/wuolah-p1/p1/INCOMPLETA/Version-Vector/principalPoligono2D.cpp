/*!
 \mainpage Implementación de un polígono usando un vector de la STL
 \author Adrián López Ortiz
 \date 2 de Marzo de 2017
 \version 1.1
*/


/*!

	\file principalPoligono2D.cpp
	\brief Programa principal de la practica 1 de ED, Poligono2D de estudiantes
	\author Adrian Lopez Ortiz
	\date 2 de Marzo de 2017
*/

#include <iostream>

#include "funcionesAuxiliares.hpp"

#include "poligono2D.hpp"
#include "vertice2D.hpp"

#include "macros.hpp"

/*! 
		\brief   Programa principal de la práctica 1: polígonos de dos dimensiones
		\return  int
*/
int main(){

	ed::Poligono2D poligono;

	int opcion;

	do{

		// Se elige la opción del menún
		opcion = ed::menu();		

		std::cout << CLEAR_SCREEN;
		LUGAR(5,1);

		// Se ejecuta la opción del menú elegida
		switch(opcion)
		{
			case 0: 
				std::cout << INVERSE;
				std::cout << "Fin del programa" << std::endl;
				std::cout << RESET;
			break;

			case 1: 
					std::cout <<BLUE<< "[1]" <<YELLOW<< "Comprobar si el poligono está vacío" <<RESET<< std::endl;
					ed::comprobarPoligono2DVacio(poligono);
					break;

			case 2: 
				  std::cout <<BLUE<< "[2]"<<YELLOW<<" Cargar un poligono de un fichero" <<RESET<< std::endl;
					ed::cargarPoligono2D(poligono);
				break;

			case 3: 
				  std::cout <<BLUE<< "[3]"<<YELLOW<<" Grabar un poligono en un fichero" <<RESET<< std::endl;
					ed::grabarPoligono2D(poligono);
					break;

			case 4: 
			  	std::cout <<BLUE<< "[4]"<<YELLOW<<" Leer un polígono desde el teclado" <<RESET<< std::endl; 
					ed::leerPoligono2D(poligono);
					break;

			case 5: 
					std::cout <<BLUE<< "[5]"<<YELLOW<<" Borrar un polígono" <<RESET<< std::endl;
					ed::borrarPoligono2D(poligono);
					break;

			case 6: 
					std::cout <<BLUE<< "[6]"<<YELLOW<<" Insertar un nuevo vértice al final del polígono" <<RESET<< std::endl;
				  ed::insertarVertice2DEnPoligono2D(poligono);
					break;

			case 7: 
					std::cout <<BLUE<< "[7]"<<YELLOW<<" Borrar un vértice de un polígono" <<RESET<< std::endl;
					ed::borrarVertice2DDePoligono2D(poligono);
					break;

			case 8: 
			  	std::cout <<BLUE<< "[8]"<<YELLOW<<" Consultar un polígono: muestra sus vértices" <<RESET<< std::endl; 
					ed::consultarPoligono2D(poligono);
					break;

			case 9: 
			  	std::cout <<BLUE<< "[9]"<<YELLOW<<" Calcular el centroide, el perímetro y el área de un polígono" <<RESET<< std::endl; 
					ed::calcularDatosPoligono2D(poligono);
					break;

			default:
			    LUGAR(25,25);
					std::cout << INVERSE;
					std::cout << "Opción incorrecta ";
					std::cout << RESET;
			  	std::cout << RED;
					std::cout << " --> " << opcion << std::endl;
					std::cout << RESET;
     }
  
    if (opcion !=0)
    {
		 LUGAR(30,5);
		 std::cout << "pulse ";
		 std::cout << UNDERLINE;
		 std::cout << IYELLOW;
		 std::cout << "ENTER";
		 std::cout << RESET;
		 std::cout << " para ";
		 std::cout << INVERSE;
		 std::cout << "continuar"; 
		 std::cout << RESET;
     // Pausa
		 std::cin.ignore();

		 std::cout << CLEAR_SCREEN;
    }
	  }while(opcion!=0);

//Fin del programa
	return 0;
}


