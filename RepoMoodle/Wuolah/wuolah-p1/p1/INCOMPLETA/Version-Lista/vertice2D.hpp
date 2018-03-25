/*! 
   \file vertice2D.hpp
   \brief Fichero de la clase Vertice2D: vértice del plano euclídeo 
*/

#ifndef _VERTICE2D_HPP_
#define _VERTICE2D_HPP_

// Entrada y salida 
#include <iostream>

// Para usar abs
#include <cmath>

// Se include la declaración de la clase  vertice2DInterfaz
#include "vertice2DInterfaz.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;


#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación números reales


// Se incluye la clase Vertice2D dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Vertice2D
class Vertice2D: public ed::vertice2DInterfaz
{

  //! \name Atributos privados de la clase Vertice2D
   private: 
      	double _x; //!< abscisa del Vertice2D 
	double _y; //!< ordenada del Vertice2D 


   //! \name Funciones o métodos públicos de la clase Vertice2D
   public:

	//! \name Constructores de la clase Vertice2D
	/*! 
		\brief     Constructor que crea un Vertice2D a partir de sus coordenadas x e y
		\attention Función sobrecargada        
		\note      Función inline
	 	\warning   Los parámetros tienen valores por defecto
		\param     x abscisa de Vertice2D; valor por defecto 0.0
		\param     y ordenada de Vertice2D; valor por defecto 0.0
		\pre       Ninguna
		\post      Ninguna
		\sa        setX(), setY()
	*/
	inline Vertice2D(double x=0.0, double y=0.0)
	{
		setX(x);
		setY(y);

	}

	/*! 
		\brief     Constructor de "copia" que crea un Vertice2D a partir de otro Vertice2D
		\attention Función sobrecargada        
		\note      Función inline
		\warning   Se requiere que las funciones de acceso getX y getY tengan el modificador const
		\param     q Vertice2D utilizado para proporcionar los valores iniciales del nuevo Vertice2D
		\pre       El Vertice2D q debe existir
		\post      Los atributos _x e _y deben tener los valores de los atributos del Vertice2D q
		\sa        getX(), getY(), setX(), setY()
	*/
	inline Vertice2D(Vertice2D const &q)
	{
		setX(q.getX());
		setY(q.getY());
	}

	//! \name Observadores: funciones de consulta de Vertice2D

	/*! 
		\brief   Función que devuelve la abscisa o coordenada "x" de un Vertice2D
		\warning Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "="
		\note    Función inline
		\return  Componente "x" del Vertice2D (tipo double)
		\pre     
		\post    Ninguna
		\sa      getY()
	*/
	inline double getX()const
	{
		return _x;
	}
	/*! 
		\brief   Función que devuelve la ordenada o coordenada "y" de un Vertice2D
		\warning Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "="
		\note    Función inline
		\return  Componente "y" del Vertice2D (tipo double)
		\pre     
		\post    Ninguna
		\sa      getX()
	*/
	inline double getY()const
	{
		return _y;

	}


	//! \name Funciones de modificación de Vertice2D

	/*! 
		\brief Función que asigna un valor "v" a la coordenada "x" de un Vertice2D
		\note  Función inline
		\param v Nuevo valor de la abscisa del Vertice2D
		\pre   
		\post  El atributo _x de Vertice2D debe tener el valor "v"
		\sa setY()
	*/
	inline void setX(double v)
	{
		_x = v;
	}


	/*! 
   	\brief Función que asigna un valor "v" a la coordenada "y" de un Vertice2D
		\note  Función inline
		\param v Nuevo valor de la ordenada del Vertice2D
		\pre   
		\post  El atributo _y de Vertice2D debe tener el valor "v"
		\sa    setX()
	*/
	inline void setY(double v)
	{
		_y = v;
	}


  //! \name Operadores
   
	/*! 
		\brief     Operador de asignación: operador que "copia" un Vertice2D en otro Vertice2D
		\attention Se sobrecarga el operador de asignación "="
		\note      Función inline
		\warning   Se requiere que las funciones de acceso getX y getY tengan el modificador const
		\param     v Vertice2D pasado como referencia constante
		\pre       El Vertice2D q debe existir y ser diferente del vertice actual
		\post      Ninguna
		\sa        getX(), getY(), setX(), setY(),  operator==
	*/
	inline Vertice2D & operator=(Vertice2D const &v)
	{
		// Se comprueba que no sean el mismo objeto
		if (this != &v) 
		{
			setX(v.getX());
			setY(v.getY());
		}

		return *this;
	}


	/*! 
		\brief     Operador de igualdad: compara si un Vertice2D es igual a otro Vertice2D
		\attention Se sobrecarga el operador de asignación "=="
		\note      Función inline
		\param     v Vertice2D pasado como referencia constante
		\pre       El Vertice2D q debe existir y ser diferente del vertice actual
		\post      Ninguna
		\sa        getX(), getY(), setX(), setY(),  operator=
	*/
	inline bool operator == (Vertice2D const &v) const
  {
  	// Se utiliza COTA_ERROR para controlar la precisión de los números reales
    return (
                  (std::abs (v.getX() - this->getX()) < COTA_ERROR)   
              and (std::abs (v.getY() - this->getY()) < COTA_ERROR)
            );
	}

	//! \name Funciones lectura y escritura de la clase Vertice2D

	/*! 
		\fn      void leerVertice2D();
		\brief   Asigna a un Vertice2D las coordenadas "x" e "y" leídas desde el teclado
		\warning Se deben teclear números
		\pre     
		\post    Los atributos _x e _y de Vertice2D deben tener valores numéricos
		\sa      setX(), setY()
	*/
	void leerVertice2D();


	/*! 
		\fn    void escribirVertice2D();
		\brief Escribe por pantalla las coordenadas de un Vertice2D de la forma (x,y)
		\pre   El Vertice2D debe tener valores asignados a sus coordenadas
		\post  Ninguna
		\sa    getX(), getY()
	*/
	void escribirVertice2D();
	

   //! \name Funciones amigas para poder acceder a la parte privada de Vertice2D.

    /*!
		\fn        friend ostream &operator<<(ostream &stream, Vertice2D const &P);
  		\brief     Sobrecarga del operador de salida o escritura "<<"
		\attention Función amiga de la clase Vertice2D
		\param     stream Flujo de salida
		\param     v Vertice2D del cual se van a escribir sus coordenadas en un "flujo de salida"
		\pre        
		\post      Se escriben por pantalla las coordenadas del vertice p de la forma (x, y)
		\sa        operator>>
    */
    friend ostream &operator<<(ostream &stream, Vertice2D const &v);

    /*!
		\fn         friend istream &operator>>(istream &stream, Vertice2D &P);
  		\brief      Sobrecarga del operador de entrada o lectura ">>"
		\attention  Función amiga de la clase Vertice2D
		\param      stream Flujo de entrada
		\param      v Vertice2D al que se le van a asignar nuevos valores.
		\pre        
		\post       El vertice v tiene asignadas como coordenadas los valores leídos desde el teclado
		\sa         operator<<
    */
    friend istream &operator>>(istream &stream, Vertice2D &v);



}; // Fin de la definición de la clase Vertice2D

//! \name Función auxiliar de la clase Vertice2D

/*! 
	\brief  Calcula la distancia euclídea entre dos Vertice2D: v1 y v2
	\param  v1 Primer Vertice2D 
	\param  v2 Segundo Vertice2D
	\return raiz ( (x2-x1)^2 + (y2 - y1)^2 )
	\pre    Los Vertice2D v1 y v2 deben existir
	\post   Ninguna
	\sa     getX(), getY() de la clase Vertice2D
*/
double calcularDistanciaEuclidea2D(Vertice2D const&v1, Vertice2D const&v2);

} // \brief Fin de namespace ed.

//  _VERTICE2D_HPP_
#endif 
