
/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 1
  \author David Sánchez Fernández
  \date     2018-03-08
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Vector3D.hpp"

namespace ed{

	/*!
		\brief   Muestra el menú del programa principal
		\return  Devuelve el número de opción elegido
	*/

	int menu();

	void leerVectores(ed::Vector3D &u, ed::Vector3D &v, ed::Vector3D &w);
	void escribirVectores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);
	void observadoresDeVectores(ed::Vector3D const &u, ed::Vector3D const &v);
	void modificarVector(ed::Vector3D &u, ed::Vector3D const &v, double k);
	void mostrarProductoEscalar(ed::Vector3D const &u, ed::Vector3D const &v);
	void mostrarProductoVectorial(ed::Vector3D const &u, ed::Vector3D const &v);
	void mostrarProductoMixto(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);
	void mostrarOperadores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D &w,  double k);

} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif
