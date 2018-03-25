/*! 
   \file vertice2DInterfaz.hpp
   \brief Fichero de la clase vertice2DInterfaz: clase de interfaz del vértice del plano euclídeo 
*/

#ifndef _VERTICE2DINTERFAZ_HPP_
#define _VERTICE2DINTERFAZ_HPP_


//! Espacio de nombres de la asignatura de Estructura de Datos
namespace ed {

// Se incluye la clase vertice2DInterfaz dentro del espacio de nombre de la asigantura: ed
//!  Definición de la clase vertice2DInterfaz
class vertice2DInterfaz 
{
   //! \name Funciones o métodos públicos de la clase vertice2DInterfaz
   public:

	//! \name Observadores: funciones de consulta de vertice2DInterfaz

	/*! 
		\fn      virtual double getX()const = 0;
		\brief   Función que devuelve la abscisa o coordenada "x" de un vertice2DInterfaz
		\warning Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "="
		\note    Función virtual pura que deberá ser redefinida por la clase heredera
		\return  Componente "x" del vertice2DInterfaz (tipo double)
		\pre     El vertice2DInterfaz debe existir
		\post    Ninguna
		\sa      getY()
	*/
	virtual double getX()const = 0;


	/*! 
		\fn      virtual double getY()const = 0;
		\brief   Función que devuelve la ordenada o coordenada "y" de un vertice2DInterfaz
		\warning Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "="
		\note    Función virtual pura que deberá ser redefinida por la clase heredera
		\return  Componente "y" del vertice2DInterfaz (tipo double)
		\pre     El vertice2DInterfaz debe existir
		\post    Ninguna
		\sa      getX()
	*/
	virtual double getY()const = 0;


	//! \name Funciones de modificación de vertice2DInterfaz

	/*! 
		\fn    virtual void setX(double v) = 0;
		\brief Función que asigna un valor "v" a la coordenada "x" de un vertice2DInterfaz
		\note  Función virtual pura que deberá ser redefinida por la clase heredera
		\param v Nuevo valor de la abscisa del vertice2DInterfaz
		\pre   El vertice2DInterfaz debe existir
		\post  El atributo _x de Vertice2D debe tener el valor "v"
		\sa    setY()
	*/
	virtual void setX(double v) = 0;


	/*! 
		\fn    virtual void setY(double v) = 0;
		\brief Función que asigna un valor "v" a la coordenada "y" de un Vertice2D
		\note  Función virtual pura que deberá ser redefinida por la clase heredera
		\param v Nuevo valor de la ordenada del Vertice2D
		\pre   El Vertice2D debe existir
		\post  El atributo _y de Vertice2D debe tener el valor "v"
		\sa    setX()
	*/
	virtual void setY(double v) = 0;

}; // Fin de la definición de la clase Vertice2DInterfaz


}//  _VERTICE2DINTERFAZ_HPP_
#endif 
