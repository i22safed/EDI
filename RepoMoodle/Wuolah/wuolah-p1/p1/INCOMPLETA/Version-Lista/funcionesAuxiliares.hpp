
/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 1
  \author Adrián López Ortiz
  \date 2 de Marzo de 2017
*/

#ifndef _funcionesAuxiliares_HPP_
#define _funcionesAuxiliares_HPP_

#include "poligono2D.hpp"

namespace ed
{
	/*! 
		\brief   Muestra el menú del programa principal 
		\return  Devuelve el número de opción elegido
	*/
  int menu();

	/*! 
		\brief   Comprueba si un polígono está vacía 
		\return  void
	*/
  void comprobarPoligono2DVacio(ed::Poligono2D const & poligono);

	/*! 
		\brief   Carga los vértices de un fichero en un polígono
		\param   poligono en el que se van a insertar los vértices 
		\return  void
    \sa      grabarPoligono2D
	*/
	void cargarPoligono2D(ed::Poligono2D & poligono);

	/*! 
		\brief   Graba los vértices de un polígono en un fichero
		\param   poligono compuesto por los vértices 
		\return  void
	  \sa      cargarPoligono2D
	*/
  void grabarPoligono2D(ed::Poligono2D  & poligono);

	/*! 
		\brief   Lee los vértices de un polígono desde el teclado
		\param   poligono compuesto por los vértices 
		\return  void
	  \sa      consultarPoligono2D
	*/
	void leerPoligono2D(ed::Poligono2D & poligono);	

  /*! 
		\brief   Borra todos los vértices de un polígono 
		\param   poligono compuesto por los vértices 
		\return  void
	  \sa      consultarPoligono2D
	*/
	void borrarPoligono2D(ed::Poligono2D & poligono);

	/*! 
		\brief   Inserta un vértice en un polígono 
		\param   poligono compuesto por los vértices 
		\return  void
	  \sa      borrarVertice2DEnPoligono2D
	*/
	void insertarVertice2DEnPoligono2D(ed::Poligono2D & poligono);

	/*! 
		\brief   Borra un vértice de un polígono 
		\param   poligono compuesto por los vértices 
		\return  void
	  \sa      insertarVertice2DEnPoligono2D
	*/
	void borrarVertice2DDePoligono2D(ed::Poligono2D & poligono);


	/*! 
		\brief   Muestra los vértices de un polígono 
		\param   poligono compuesto por los vértices 
		\return  void
	  \sa      
	*/
  void consultarPoligono2D(ed::Poligono2D  & poligono);

	/*! 
		\brief   Calcular el centroide, el área y el perímetro de un polígono 
		\param   poligono compuesto por los vértices 
		\return  void
	  \sa      consultarPoligono2D
	*/
  void calcularDatosPoligono2D(ed::Poligono2D  & poligono);


} // Fin del espacio de nombre de la asignatura: ed

// Fin de _funcionesAuxiliares_HPP_
#endif

