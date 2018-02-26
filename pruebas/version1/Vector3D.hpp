/*!
   \file Vector3D.hpp
   \brief Fichero de definición de la clase Vector3D: vector libre de tres dimensiones
*/

#ifndef _VECTOR3D_HPP_
#define _VECTOR3D_HPP_

// Entrada y salida
#include <iostream>

// Para usar abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

// Libreria para el uso de vectores
#include <vector>


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación números reales


// Se incluye la clase Vector3D dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Vector3D:  \f$ \vec{v} = (v_1, v_2, v_3) = v_1 \vec{i} + v_2 \vec{j} + v_3 \vec{k} \f$
class Vector3D
{
  //! \name Atributos privados de la clase Vector3D
   private:

	// COMPLETARVector3D
     double vector_[2];


   //! \name Funciones o métodos públicos de la clase Vector3D
   public:

	//! \name Constructores de la clase Vector3D

	// COMPLETAR
     // Los metodos get deben de ser de tipo const
	//! \name Observadores: funciones de consulta de Vector3D

     // Constructores

     Vector3D();                             // Sin argumentos
     Vector3D(int v1, int v2, int v3);       // Parametrizado
     Vector3D(Vector3D const &v);            // De copia

     // Observadores de la clase Vector3D

     double get1()const{return vector_[0];};
     double get2()const{return vector_[1];};
     double get3()const{return vector_[2];};

     double modulo();
     double angulo(Vector3D const &v);

	//! \name Modificadores: funciones de modificación de Vector3D

	// COMPLETAR


    //! \name Operadores de la clase

	// COMPLETAR COMENTARIOS DE DOXYGEN


	// COMPLETAR COMENTARIOS DE DOXYGEN
	bool operator == (Vector3D const &objeto) const;

	// COMPLETAR EL RESTO DE OPERADORES


	//! \name Funciones lectura y escritura de la clase Vector3D

	// COMPLETAR

}; // Fin de la definición de la clase Vector3D


//////////////////////////////////////////////////////////////////////////////////////

//! \name Funciones que utilizan un objetos de la clase Vector3D, pero que no pertenecen a la clase Vector3D

	// COMPLETAR COMENTARIOS DE DOXYGEN
    Vector3D & operator* (double k, Vector3D const & objeto);


	// COMPLETAR COMENTARIOS DE DOXYGEN
    istream &operator>>(istream &stream, Vector3D &objeto);

	// COMPLETAR COMENTARIOS DE DOXYGEN
	ostream &operator<<(ostream &stream, Vector3D const &objeto);


} // \brief Fin de namespace ed.

//  _VECTOR3D_HPP_
#endif
