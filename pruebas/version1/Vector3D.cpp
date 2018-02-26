/*!
   \file Vector3D.cpp
   \brief Fichero que contiene el código de las funciones de la clase Vector3D
*/


// Ficheros de cabecera
#include <iostream>

// Para usar sqrt, acos
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#include "Vector3D.hpp"

// OBSERVADORES
// COMPLETAR


////////////////////////////////////////////////////////////////

// MODIFICADORES
// COMPLETAR



////////////////////////////////////////////////////////////////////////////////

// OPERADORES
// COMPLETAR



////////////////////////////////////////////////////////////////////////////////

// FUNCIONES DE LECTURA Y ESCRITURA
// COMPLETAR


////////////////////////////////////////////////////////////////////////////////


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{

ed::Vector3D::Vector3D(){

	vector_[0] = 0;
	vector_[1] = 0;
	vector_[2] = 0;

	// Compribamos la postcondicion del método
	assert((get1()==0) and (get2()==0) and (get3()==0));

}

ed::Vector3D::Vector3D(int v1, int v2, int v3){

	vector_[0] = v1;
	vector_[1] = v2;
	vector_[2] = v3;

	assert((get1()==0) and (get2()==0) and (get3()==0));

}

ed::Vector3D::Vector3D(ed::Vector3D const &v){

	vector_[0] = v.vector_[0];
	vector_[0] = v.vector_[0];
	vector_[0] = v.vector_[0];

	assert((get1()==v.get1()) and (get2()==v.get2()) and (get3()==v.get3()));

}

double ed::Vector3D::modulo(){

	double modulo = 0;

	modulo = sqrt(vector_[0]*vector_[0]+vector_[1]*vector_[1]
		+vector_[2]*vector_[2]);

		// Poscondicion
		assert(modulo = sqrt(get1()*get1()+get2()*get2()+
		get3()*get3()));

	return modulo;

}

double ed::Vector3D::angulo(ed::Vector3D const &v){

	assert((modulo()*v.modulo()) > 0);

	angulo = arccos((vector_[0]*v.vector_[0]+
			vector_[1]*v.vector_[1]+
			vector_[2]*v.vector_[2])/(
			modulo()*v.modulo()))

	//assert(angulo == acos(dotProduct(v)/modulo()*v.modulo()))

	return angulo;

}


// Producto "por un" escalar (prefijo): k * v
ed::operator* (double k, ed::Vector3D const & objeto)
{
	ed::Vector3D *vectorResultado = new ed::Vector3D();

	// COMPLETAR

	return *vectorResultado;
}


// Sobrecarga del operador de salida
// Se escriben por pantalla las coordenadas del vector 3D  de la forma (v1, v2, v3)
ostream &operator<<(ostream &stream, ed::Vector3D const &objeto)
{
	// COMPLETAR

  return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Vector3D &objeto)
{
  // COMPLETAR

  return stream;
}

} // Fin del espacio de nombres ed
