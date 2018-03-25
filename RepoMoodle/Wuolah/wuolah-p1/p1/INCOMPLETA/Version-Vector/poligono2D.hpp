/*! 
  \file poligono2D.hpp
  \brief Fichero de definición de la clase Poligono2D: polígono de vértices del plano euclídeo 
*/

#ifndef _POLIGONO2D_HPP_
#define _POLIGONO2D_HPP_

#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>

// Se incluye para utilizar la definición de la clase Vertice2D
#include "vertice2D.hpp"

// Se incluye para utilizar la definición de la clase Poligono2DInterfaz
#include "poligono2DInterfaz.hpp"


namespace ed {

//!  Definición de la clase Poligono2D
class Poligono2D: public ed::Poligono2DInterfaz
{
  //! \name Atributos privados de la clase Poligono2D
   private:
   
   std::vector <ed::Vertice2D> v_;//! vector que guarda los vertices que conforman el poligono

   //! \name Funciones o métodos públicos de la clase Poligono2D
   public:
	//! \name Constructor

	/*!
		\brief Crea un Poligono que almacena los vertices que lo forman en un vector 
		\note  Crea un vector que almacena datos de tipo Vertice2D
	 */
	inline Poligono2D (){};
	 
	 /*! 
		\name 	   DESTRUCTOR
		\brief     Destructor de la clase Poligono2D	       
		
		 Si el poligono está vacio no elimina los valores del vector
	 	*/

		~Poligono2D(){    
	
			if(not comprobarPoligonoVacio())
				v_.clear();
		}
	 
	 
	//! \name Constructor de Copia

	/*!
		\brief Crea y opia un Poligono que almacena los vertices que lo forman en un vector 
		\note  Crea y copia un vector que almacena datos de tipo Vertice2D
		\param q Vector copia que vuelva su informacion en v_
	 */
	 
	inline Poligono2D (Poligono2D const &q){
	
		v_=q.v_;
	};
	//! \name Observadores
	/*!
		@fn bool comprobarPoligonoVacio ()const
		\brief Comprueba que el poligono esta vacio o no 
		\return devuelve un valor booleano que dice si esta o no vacio el vector
		
		Comprueba si el vector esta vacío o no, es decir, si tiene vertices o esta vacío y devuelve consecuentemente true o false si no esta vacío o si lo esta, respectivamente.
		*/
	inline bool comprobarPoligonoVacio ()const{
	
		if(numeroVerticesPoligono() != 0){return false;}
		
		else{return true;}		
	};
	/*! 
		@fn int numeroVerticesPoligono ()const
		\brief Te dice el número de vértices que tiene el poligono almacenado en el vector 
		\return devuelve una variable entera que te dice el numero de vertices que hay en la variable vector v_
		*/
	inline int numeroVerticesPoligono ()const{return v_.size();};
	
	/*! 
		@fn bool existeVertice (const unsigned int &indice)const
		\brief Te dice si hay un vertice en el indice en el que te pregunta
		\param indice variable entera que te dice la posicion del vector que quiere consultar 
		\return devuelve una variable booleana que devuelve verdadero si existe un vertice en la posicion indicada  por indice o falso si este no existe.
		*/
		
	inline bool existeVertice (const unsigned int &indice)const{
	
	return(indice<0 || indice>v_.size());
	};	
	/*!
		@fn ed::Vertice2D const & getVertice2D (const unsigned int &indice)const
		\brief Accede al vertice almacenado en la posicion indicada en el vector 
		\param indice variable entera que te dice la posicion del vector que quiere consultar 
		\return Devuelve el vertice que se quiere consultar del vector pasando como variable local la posicion del vector v_ en la que se encuentra.
		*/
	
	ed::Vertice2D const & getVertice2D (const unsigned int &indice)const;
	
	
	/*!
	
	@fn ed::Vertice2D const & operator [] (const int indice)
		\brief Accede al vertice almacenado en la posicion indicada en el vector 
		\param indice variable entera que te dice la posicion del vector que quiere consultar 
		\return Devuelve el vertice que se quiere consultar del vector pasando como variable local la posicion del vector v_ en la que se encuentra.
		
		Es la misma funcion que getVertice2D pero sobrecargando el operador []
		*/
	ed::Vertice2D const & operator [] (const int indice);
	
	
	//! \name Modificadores
	/*!
	
	@fn void insertarVertice (const ed::Vertice2D &vertice)
		\brief Inserta un vertice al final del vector, es decir, en la ultima posicion de este.
		\param vertice recibe como parametro el vertice que se quiere almacenar en el vector v_ 
		*/
	inline void insertarVertice (const ed::Vertice2D &vertice){

	v_.push_back(vertice);
	}
	
	/*!
	
	@fn void borrarVertice (int indice)
		\brief borra el vertice que ocupa la posicion indice del vector v_. 
		\param indice es una variable enteera que indica la posicion del vector en la que se encuentra el vertice que se quiera borrar
		 
		*/
	
	inline void borrarVertice (int indice){ v_.erase(v_.begin()+indice);};
	
	/*!
	
	@fn void borrarPoligono ()
		\brief borra el vector v_. 
				 
		*/
	
	inline void borrarPoligono (){v_.clear();};
	
	
	//! \name Sobrecarga de operadores
	
	/*!
	@fn bool const  operator = (ed::Poligono2D const &p)
		\brief sobrecarga del operador =
		\param p es un Poligono2D que vuelca su informacion en el actual.
	*/
	
	Poligono2D const & operator = (ed::Poligono2D const &p);
	
	/*!
	@fn bool const  operator == (ed::Poligono2D const &p)
		\brief sobrecarga del operador ==
		\param p es un Poligono2D que se compara con el actual.
		\return devuelve una variable booleana que es verdadera en caso de que los dos poligonos sean iguales y en caso contrario devuelve false
	*/
	bool const  operator == (ed::Poligono2D const &p);
	
	
	//! \name Lectura/Escritura
	
	/*!
	@fn void leePoligono ()
		\brief lee por pantalla una cantidad x de vertices y pide tambien por pantalla el numero de vertices x que se van a introducir. 
		
	*/
	void leePoligono ();
	
	/*!
	@fn void escribePoligono (ed::Poligono2D &poligono)
		\brief escribe en pantalla los vertices pertenecientes al poligono almacenados en el vector v_
		
	*/
	
	void escribePoligono (ed::Poligono2D &poligono);
	
	/*!
	@fn void cargarPoligono (std::string nomfich)
		\brief carga un poligono desde un archivo de texto al vector
		\param nomfich variable string en la que se le pasa a la funcion el nombre del fichero de texto
	*/
	void cargarPoligono (std::string nomfich);
	
	/*!
	@fn void grabarPoligono (std::string nomfich)
		\brief carga el poligono actual en un archivo de texto
		\param nomfich variable string en la que se le pasa a la funcion el nombre del fichero de texto
	*/
	void grabarPoligono (std::string nomfich);
	
	//! \name Funciones auxiliares
	
	/*!
	@fn ed::Vertice2D centroidePoligono ()
		\brief Calcula el centro de gravedad del poligono
		\return devuelve un vertice en el que se encuentra el centro de gravedad del poligono
	*/
	ed::Vertice2D centroidePoligono ();
	
	/*!
	@fn double perimetroPoligono()
		\brief Calcula el perimetro del poligono
		\return devuelve una variable en la que se encuentra el perimetro del poligono
	*/
	double perimetroPoligono();
	/*!
	@fn double areaPoligono()
		\brief Calcula el area del poligono
		\return devuelve una variable en la que se encuentra el area del poligono
	*/
	double areaPoligono();

}; // Fin de la definición de la clase Poligono2D



} // \brief Fin de namespace ed

// _POLIGONO2D_HPP_
#endif 
