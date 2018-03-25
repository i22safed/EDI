/*! 
   \file poligono2DInterfaz.hpp
   \brief Fichero de la clase Poligono2DInterfaz: clase de interfaz del polígono del plano euclídeo 
*/

#ifndef _POLIGONO2DINTERFAZ_HPP_
#define _POLIGONO2DINTERFAZ_HPP_


// Se incluye para utilizar la definición de la clase Vertice2D
#include "vertice2D.hpp"


namespace ed {

//!  Definición de la clase Poligono2DInterfaz
class Poligono2DInterfaz 
{
   //! \name Funciones o métodos públicos de la clase Poligono2DInterfaz
   public:
	
	//! \name Observadores: funciones de consulta de vertice2DInterfaz

	/*! 
		\fn      virtual int numeroVerticesPoligono () const =0;
		\brief   Funcion que devuelve el numero de vertices de la lista.
		\note    Función virtual pura que deberá ser redefinida por la clase heredera
		\return  tipo int. Numero de vertices almacenados en la lista.
	*/
	virtual int numeroVerticesPoligono () const =0;
	
	/*! 
		\fn     virtual bool comprobarPoligonoVacio () const =0;
		\brief  Funcion que comprueba si el poligono esta vacio o no.
		
		\note    Función virtual pura que deberá ser redefinida por la clase heredera
		\return  devuelve verdadero si esta vacio y falso si no lo esta
	*/
	virtual bool comprobarPoligonoVacio () const =0;
	
	/*! 
		\fn     virtual bool existeVertice (const unsigned int &indice) const =0;
		\brief  Funcion que comprueba si existe el vertice indicado por la posicion del indice
		
		\note    Función virtual pura que deberá ser redefinida por la clase heredera
		\return  devuelve verdadero si existe y falso si no
	*/
	
	virtual bool existeVertice (const unsigned int &indice) const =0;
	
	/*! 
		\fn     virtual Vertice2D const & getVertice2D (const unsigned int &indice
) const =0;
		\brief  Funcion que accede a la posicion de la lista indicada por el indice
		
		\note    Función virtual pura que deberá ser redefinida por la clase heredera
		\return  devuelve el vertice pedido
	*/
	
	virtual Vertice2D const & getVertice2D (const unsigned int &indice) const =0;
	
	/*! 
		\fn     void insertarVertice (const Vertice2D &vertice)=0;
		\brief  Funcion que inserta un vertice al final de la lista
		
		\note    Función virtual pura que deberá ser redefinida por la clase heredera
	*/
	virtual void insertarVertice (const Vertice2D &vertice)=0;
	
	/*! 
		\fn     virtual void borrarVertice (int indice)=0;
		\brief  Funcion que borra el vertice de la posicion indice de la lista
		
		\note    Función virtual pura que deberá ser redefinida por la clase heredera
	*/
	virtual void borrarVertice (int indice)=0;
	



}; // Fin de la definición de la clase Poligono2DInterfaz



} // Fin del espacio de nombres ed

// _POLIGONO2DINTERFAZ_HPP_
#endif 
