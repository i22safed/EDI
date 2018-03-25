/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 1
  \author Adrián López Ortiz
  \date 2 de Marzo de 2017
*/


#include <iostream>
#include <string>

#include "funcionesAuxiliares.hpp"
#include "vertice2D.hpp"

#include "macros.hpp"

int ed::menu()
{
 int opcion, posicion;

		// Se muestran las opciones del menú
		posicion=8;

		// Se borra la pantalla
		std::cout << CLEAR_SCREEN;

		LUGAR(5,10);
   	std::cout << BBLUE;
		std::cout << "Programa principal | Opciones del menú   ";
		std::cout << RESET;

		LUGAR(posicion++,10);
		std::cout <<BIPURPLE<< "[1] Comprobar si el poligono está vacío"<< RESET;

		LUGAR(posicion++,10);
		std::cout <<BIPURPLE<< "[2] Cargar un poligono de un fichero"<< RESET ;

		LUGAR(posicion++,10);
		std::cout <<BIPURPLE<< "[3] Grabar un poligono en un fichero"<< RESET;

		LUGAR(posicion++,10);
		std::cout <<BIPURPLE<< "[4] Leer un polígono desde el teclado"<< RESET;

		LUGAR(posicion++,10);
		std::cout <<BIPURPLE<< "[5] Borrar un polígono"<< RESET;

		LUGAR(posicion++,10);
		std::cout <<BIPURPLE<< "[6] Insertar un nuevo vértice al final del polígono"<< RESET ;

		LUGAR(posicion++,10);
		std::cout <<BIPURPLE<< "[7] Borrar un vértice de un polígono"<< RESET;

		LUGAR(posicion++,10);
		std::cout <<BIPURPLE<< "[8] Consultar un poligono: muestra sus vértices"<< RESET;

		LUGAR(posicion++,10);
		std::cout <<BIPURPLE<< "[9] Calcular el centroide, el perímetro y el área de un polígono"<< RESET;

		LUGAR(posicion++,10);
		std::cout << GREEN << "[0] Salir";

		LUGAR(posicion++,20);
		std::cout << IYELLOW;
		std::cout << "Opción: ";
		std::cout << RESET;
		std::cin >> opcion;
    // Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

		return opcion;
}

 void ed::comprobarPoligono2DVacio(ed::Poligono2D const & poligono)
{
	std::cout << "version 1.0 de la funcion\n" ;
	
	if(poligono.comprobarPoligonoVacio()){std::cout<<"El poligono esta vacio\n";}
	else{std::cout<<"El poligono no esta vacio\n";}
	
}

void ed::cargarPoligono2D(ed::Poligono2D & poligono)
{
	std::string nomfich;
	std::cout<<"Introduce el nombre del fichero.\n";
	std::cin>>nomfich;
	
  	poligono.cargarPoligono (nomfich);
}

void ed::grabarPoligono2D(ed::Poligono2D  & poligono)
{
	std::string nomfich;
	std::cout<<"Introduce el nombre del fichero.\n";
	std::cin>>nomfich;
  	poligono.grabarPoligono (nomfich);
}

void ed::leerPoligono2D(ed::Poligono2D &poligono)
{
	  	poligono.leePoligono ();

}




void ed::borrarPoligono2D(ed::Poligono2D &poligono)
{
	poligono.borrarPoligono ();
}


// Inserta un vertice al final del polígono
void ed::insertarVertice2DEnPoligono2D(ed::Poligono2D & poligono)
{
	Vertice2D vertice;
	vertice.leerVertice2D();
	poligono.insertarVertice (vertice);
}

void ed::borrarVertice2DDePoligono2D(ed::Poligono2D & poligono)
{
	int indice;
	std::cout<<"¿Que vertice quiere borrar?(introduzca el indice.\n";
	std::cin>>indice;
	poligono.borrarVertice (indice);
}


void ed::consultarPoligono2D(ed::Poligono2D  & poligono)
{
		poligono.escribePoligono(poligono);
}

void ed::calcularDatosPoligono2D(ed::Poligono2D  & poligono)
{
	Vertice2D centroide;
	double perimetro,area;
	
	centroide=poligono.centroidePoligono ();
	perimetro=poligono.perimetroPoligono();
	area=poligono.areaPoligono();
	
	std::cout<<"Centroide: "<<"("<<centroide.getX()<<","<<centroide.getY()<<")\n";
	std::cout<<"Perimetro: "<<perimetro<<std::endl;
	std::cout<<"Area: "<<area<<std::endl;
}


