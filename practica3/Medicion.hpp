/*!
   \file Medicion.hpp
   \brief Fichero de la clase Medicion: medición de una estación meteorológica
*/

#ifndef _MEDICION_HPP_
#define _MEDICION_HPP_

// Entrada y salida
#include <iostream>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>

// Definición de la clase Fecha
#include "Fecha.hpp"


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales


// Se incluye la clase Medicion dentro del espacio de nombres de la asigantura: ed
namespace ed {

//!  Definición de la clase Medicion
class Medicion{

  //! \name Atributos privados de la clase Medicion
   private:

          Fecha _fecha;
          float _precipitacion;


   //! \name Funciones o métodos públicos de la clase Medicion
   public:

	//! \name Constructor de la clase Medicion

          // Constructor de parametrizado

     	Medicion(Fecha fecha=Fecha(1,1,1),float precipitacion=0.0){

               assert((getFecha()==fecha) and (getPrecipitacion()==precipitacion));

          }

          // Constructor de copia

          inline Medicion(Medicion &m){

               this->setFecha(m.getFecha());
               this->setPrecipitacion(m.getPrecipitacion());

          }

	//! \name Observadores: funciones de consulta de la clase Medicion

		// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

          inline Fecha getFecha()const{return this->_fecha;};

          inline float getPrecipitacion()const{return this->_precipitacion;};

	//! \name Funciones de modificación de la clase Medicion

		// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

          inline void setFecha(Fecha fecha){
               this->_fecha = fecha;
               assert(getFecha() == fecha);
          };

          inline void setPrecipitacion(float precipitacion){
               assert(precipitacion >= 0.0);
               this->_precipitacion = precipitacion;
               assert(getPrecipitacion() == precipitacion);
          };

	//! \name Operadores

		// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

          inline bool operator == (Medicion const &m)const{

               bool valorDevuelto = false;

               if(this->_fecha == m.getFecha()){
                    valorDevuelto = true;
                    assert(valorDevuelto == (this->_fecha == m.getFecha()));
               }

               return valorDevuelto;

          }

          inline Medicion operator = (Medicion const &m){

               Medicion medicion;

               medicion.setFecha(m.getFecha());
               medicion.setPrecipitacion(m.getPrecipitacion());

               assert(getFecha()==medicion.getFecha());
               assert(getPrecipitacion()==medicion.getPrecipitacion());

               return medicion;

          }

	//! \name Funciones de lectura y escritura de la clase Medicion

		// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

          void escribirMedicion()const;
          void leerMedicion();





}; // Fin de la definición de la clase Medicion


   //! \name Funciones externas de la clase Medicion: sobrecarga de los operadores de flujo

		// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN



} // \brief Fin de namespace ed.

//  _MEDICION_HPP_
#endif
