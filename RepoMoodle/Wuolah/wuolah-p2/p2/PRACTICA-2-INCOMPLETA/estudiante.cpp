/*!	
	\file  estudiante.cpp
	\brief Código auxiliar de las funciones de la clase Estudiante
	\author Adrián López Ortiz
	\date 30-12-17
	\version 1.2
*/


#include <iostream>
#include <stdio.h>

// Eliminar el comentario si se desea usar atof en la sobrecarga del operador >>
// #include <stdlib.h>

#include "estudiante.hpp"

// Se han utilizado los calificadores ed:: y std:: en vez de las sentencias siguientes
//using namespace ed;
//using namespace std;

/* Definiciones de las funciones lectura y escritura de la clase Estudiante */

void ed::Estudiante::leerEstudiante(){

	std::cout << "Introduce el nombre: ";

	// Uso de getline para leer nombres compuestos separados por espacios
	std::getline(std::cin,this->_nombre);

	// Esta sentencia no permite leer nombres compuestos con espacios en blanco
	// std::cin >> this->_nombre;
	std::cout << "Introduce los apellidos: ";
	
	// Uso de getline para leer los apellidos separados por espacios
	std::getline(std::cin,this->_apellidos);

	// Esta sentencia no permite leer dos apellidos separados por espacios en blanco
	// std::cin >> this->_apellidos;
	std::cout << "Introduce la nota de teoría: ";
	std::cin >> this->_teoria;

	std::cout << "Introduce la nota de práctica: ";
	std::cin >> this->_practica;

	// Se elimina el salto de línea para evitar problemas en una posterior lectura de cadenas 
	std::cin.ignore(); 
}


void ed::Estudiante::escribirEstudiante(){//Funcion que escribe los datos de los estudiantes
	
	//Escribe el nombre
	std::cout << "Nombre:" << this->getNombre() << std::endl;
	
	//Escribe los apellidos
	std::cout << "Apellidos:" << this->getApellidos() << std::endl;
	
	//Escribe la nota de teoría
	std::cout << "Nota de teoría:" << this->getTeoria() << std::endl;
	
	//Escribe la nota de prácticas
	std::cout << "Nota de prácticas:" << this->getPractica() << std::endl;
	
	//Escribe la nota final
	std::cout << "Nota final:" << this->getFinal() << std::endl;

}

ed::Estudiante &ed::Estudiante::operator=(const ed::Estudiante &e){//Esta funcion sobrecarga el operador '=' de forma que se pueda volcar en un objeto Estudiante otro objeto Estudiante.

	// Se comprueba que no sean el mismo objeto
	if (this != &e){
	
	//Si no son el mismo objeto se vuelca los datos uno a uno en las variables del objeto.
	this->setNombre(e.getNombre());
	this->setApellidos(e.getApellidos());
	this->setTeoria(e.getTeoria());
	this->setPractica(e.getPractica());
	
	}

	// Se devuelve el objeto actual
	return *this;
}


bool ed::Estudiante::operator==(const ed::Estudiante & e) const {//Devuelve verdadero si la clave del objeto es igual. Falso si no.
	
	return (    (this->getNombre() == e.getNombre()) 
		and (this->getApellidos() == e.getApellidos()));
}


bool ed::Estudiante::operator <(const ed::Estudiante & e) const {//Compara entre 2 objetos por orden alfabético quien es 'menor'.

	if (this->getApellidos() < e.getApellidos())
		return true;

	else if (     (this->getApellidos() == e.getApellidos()) 
				and (this->getNombre() < e.getNombre())
		){
		
		return true;
     		
     		}
     	else
		return false;
}

/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed{

std::istream &operator>>(std::istream &i, ed::Estudiante &e)
{
  std::getline(i,e._nombre);

  std::getline(i,e._apellidos);

  i >> e._teoria;
  // Se elimina el salto de línea del flujo de entrada para evitar problemas con la posterior lectura de cadenas
  i.ignore();

  i >> e._practica;
  // Se elimina el salto de línea del flujo de entrada para evitar problemas con la posterior lectura de cadenas
  i.ignore();

/* Forma alternativa para la lectura de datos numéricos usando una variable auxiliar: cadena
  std::string cadena;

 	std::getline(i,cadena);
  e._teoria = atof(cadena.c_str());

  std::getline(i,cadena);
  e._practica = atof(cadena.c_str());
*/

  // Se devuelve el flujo de entrada
  return i;
}


std::ostream &operator<<(std::ostream &o, ed::Estudiante const &e)
{
  o << e._nombre << std::endl;
  o << e._apellidos << std::endl;

  o << e._teoria << std::endl;
  o << e._practica << std::endl;

  // Se devuelve el flujo de salida
  return o;
}

} // Fin del espacio de nombres ed




