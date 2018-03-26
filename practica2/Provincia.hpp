/*!
	\file  Provincia.hpp
	\brief Definición de la clase Provincia
	\author
	\date
	\version

*/

#ifndef _PROVINCIA_HPP_
#define _PROVINCIA_HPP_

// Para comprobar las pre y post condiciones
#include <cassert>

#include <string>


#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"


// DEBES COMPLETAR O MODIFICAR EL CÓDIGO DE LA CLASE Provincia

// DEBES COMPLETAR LOS COMENTARIOS DE DOXYGEN

// IMPORTANTE
// Se incluyen los prototipos de las funciones virtuales que hay que redefinir
// Hay que incluir los prototipos de las demás funciones


/*!
	\namespace ed
	\brief Espacio de nombres para la Provincia Estructuras de Datos

*/
namespace ed{
/*!

  \class Provincia
  \brief Definición de la clase Provincia

*/
class Provincia
{
	//!	\name Métodos públicos de la clase Provincia

	private:
		std::string      _nombre;     //!<  \brief Nombre de la Provincia
		int              _codigo;	  //!<  \brief Código de la Provincia

	  	ed::ListaDoblementeEnlazadaOrdenadaMunicipios _listaMunicipios; //!<  \brief Lista de municipios de la Provincia


	/////////////////////////////////////////////////////////////////////

	//!	\name  Métodos públicos de la clase Provincia

  public:

	//!	\name Constructor

	Provincia(std::string nombre="",int codigo=0){
		setNombre(nombre);
		setCodigo(codigo);

		assert(getNombre()==_nombre);
		assert(getCodigo()==_codigo);
		assert(hayMunicipios()==true);

	};



	/////////////////////////////////////////////////////////////////////

	//!	\name Observadores

	inline std::string getNombre(){return _nombre;};
	inline int getCodigo(){return _codigo;};
	inline bool hayMunicipios(){
		return _listaMunicipios.isEmpty();
	};

	inline int getNumeroMunicipios(){

		int nMun = 0;


		return nMun;
	};

	/////////////////////////////////////////////////////////////////////

	//!	\name Modificadores

	inline void setNombre(std::string nombre){_nombre = nombre;};
	inline void setCodigo(int codigo){_codigo = codigo;};



	/////////////////////////////////////////////////////////////////////

	//! \name Función de escritura de la clase Provincia



	/////////////////////////////////////////////////////////////////////

	//! Operaciones con ficheros


}; //Fin de la clase  Provincia


} // Fin del espacio de nombres ed

#endif // _PROVINCIA_HPP_
