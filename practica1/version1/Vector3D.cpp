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

	// Constructores sin argumentos, parametrizado y de copia

ed::Vector3D::Vector3D(){

	vector_[0]=0;
	vector_[1]=0;
	vector_[2]=0;
	assert((get1()==0) and (get2()==0) and (get3()==0));

}

ed::Vector3D::Vector3D(double v1,double v2,double v3){

	vector_[0]=v1;
	vector_[1]=v2;
	vector_[2]=v3;
	assert((get1()==v1) and (get2()==v2) and (get3()==v3));

}

ed::Vector3D::Vector3D(ed::Vector3D const &v){

	vector_[0]=v.vector_[0];
	vector_[1]=v.vector_[1];
	vector_[2]=v.vector_[2];
	assert((get1()==v.get1()) and (get2()==v.get2()) and (get3()==v.get3()));

}

double ed::Vector3D::modulo(){

	double modulo = sqrt(vector_[0]*vector_[0]+vector_[1]*vector_[1]+vector_[2]*vector_[2]);
	assert (modulo == sqrt(get1()*get1()+get2()*get2()+get3()*get3()));
	return modulo;

}

double ed::Vector3D::angulo(ed::Vector3D v){

	assert(modulo()*v.modulo() > 0);
	// En caso de que salga del rango [-1,1] asignar -1 o 1 directamente
	double angulo=acos(vector_[0]*v.vector_[0]+vector_[1]*v.vector_[1]+vector_[2]*v.vector_[2])/(modulo()*v.modulo());
	assert(angulo==acos(dotProduct(v)/modulo()*v.modulo()));
	return angulo;

}

double ed::Vector3D::alfa(){

	assert(modulo() > 0);
	double anguloAlfa=(vector_[0]*1+vector_[1]*0+vector_[2]*0)/(modulo()+1);
	assert(anguloAlfa==angulo(Vector3D(1,0,0)));
	return anguloAlfa;

}

double ed::Vector3D::beta(){

	assert(modulo()>0);
	double anguloBeta=(vector_[0]*0+vector_[1]*1+vector_[2]*0)/(modulo()+1);
	assert(anguloBeta==angulo(Vector3D(0,1,0)));
	return anguloBeta;

}

double ed::Vector3D::gamma(){

	assert(modulo() > 0);
	double anguloGamma=(vector_[0]*0+vector_[1]*0+vector_[2]*1)/(modulo()+1);
	assert(anguloGamma==angulo(Vector3D(0,0,1)));
	return anguloGamma;

}




double ed::Vector3D::dotProduct(ed::Vector3D v){

	double pdtoEscalar = (vector_[0]*vector_[0]+vector_[1]*vector_[1]+vector_[2]*vector_[2]);
	assert(get1()*v.get1()+get2()*v.get2()+get3()*v.get3());
	return pdtoEscalar;

}

Vector3D ed::Vector3D::crossProduct(ed::Vector3D v){

	ed::Vector3D w(0,0,0);

	w.vector_[0] = vector_[2]*v.vector_[3] - vector_[3]*v.vector_[2];
	w.vector_[1] = -vector_[1]*v.vector_[3] + vector_[3]*v.vector_[1];
	w.vector_[2] = vector_[1]*v.vector_[2] - vector_[2]*v.vector_[1];

	// Postcondicion

	assert(dotProduct(w)==0);
	assert(v.dotProduct(w)==0);
	assert (w.modulo() == modulo()*v.modulo()*sin(angulo(v)));

	return w;

}

double ed::Vector3D::productoMixto(ed::Vector3D  v,ed::Vector3D  w){

	double pdtoMixto = dotProduct(v.crossProduct(w));
	assert(pdtoMixto == dotProduct(v.crossProduct(w)));
	return pdtoMixto;

}


void ed::Vector3D::set1(double v){

	vector_[0] = v;
	assert(get1()==v);

}

void ed::Vector3D::set2(double v){

	vector_[1] = v;
	assert(get2()==v);

}

void ed::Vector3D::set3(double v){

	vector_[2] = v;
	assert(get3()==v);

}





// Producto "por un" escalar (prefijo): k * v
ed::Vector3D & operator* (double k, ed::Vector3D const & objeto)
{
	ed::Vector3D *vectorResultado = new ed::Vector3D();

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
