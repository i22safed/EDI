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

	inline std::string getNombre() const {return _nombre;};

	inline int getCodigo() const {return _codigo;};

	inline bool hayMunicipios() const {

		return _listaMunicipios.isEmpty();
	};

	inline int getNumeroMunicipios() const {

		return _listaMunicipios.nItems();

	};

	inline bool existeMunicipio(std::string const &nombre){

		ed::Municipio m;
		m.setNombre(nombre);

		if (_listaMunicipios.isEmpty() == true){
			return false;
		}else{
			return _listaMunicipios.find(m);
		}

	};

	inline ed::Municipio getMunicipios(std::string const &nombre){

		ed::Municipio m;

		assert(existeMunicipio(nombre)==true);

		_listaMunicipios.gotoHead();

		while(not _listaMunicipios.isLastItem()){

			m = _listaMunicipios.getCurrentItem();
			if(m.getNombre()==nombre){
				return m;
			}

			_listaMunicipios.gotoNext();

		}

	};

	inline int getTotalHombres(){

		ed::Municipio m;
		int valorDevuelto = 0;

		_listaMunicipios.gotoHead();

		while(not _listaMunicipios.isLastItem()){

			m = _listaMunicipios.getCurrentItem();
			valorDevuelto += m.getHombres();
			_listaMunicipios.gotoNext();

		}

		return valorDevuelto;

	};

	inline int getTotalMujeres(){

		ed::Municipio m;
		int valorDevuelto = 0;

		_listaMunicipios.gotoHead();

		while(not _listaMunicipios.isLastItem()){

			m = _listaMunicipios.getCurrentItem();
			valorDevuelto += m.getMujeres();
			_listaMunicipios.gotoNext();

		}

		return valorDevuelto;

	};

	inline int getTotalHabitantes(){

		int valorDevuelto = getTotalHombres()+getTotalMujeres();

		assert(valorDevuelto == getTotalHombres()+getTotalMujeres());

		return valorDevuelto;

	}


	/////////////////////////////////////////////////////////////////////

	//!	\name Modificadores

	inline void setNombre(std::string nombre){
		_nombre = nombre;
		assert(getNombre() == nombre);
	};

	inline void setCodigo(int codigo){
		_codigo = codigo;
		assert(getCodigo() == codigo);
	};

	inline void insertarMunicipio(ed::Municipio const & m){

		ed::Provincia old;

		assert(existeMunicipio(m.getNombre())==false);

		_listaMunicipios.insert(m);

		assert(existeMunicipio(m.getNombre())==true);
		assert(getNumeroMunicipios() == (old.getNumeroMunicipios() + 1));

	};


	inline void borrarMunicipio(std::string const & nombre){

		ed::Provincia old;
		ed::Municipio m;

		assert(existeMunicipio(getNombre())==true);

		_listaMunicipios.gotoHead();

		while(not _listaMunicipios.isLastItem()){

			m = _listaMunicipios.getCurrentItem();
			if(m.getNombre() == nombre){
				_listaMunicipios.remove();
			}

			_listaMunicipios.gotoNext();

		}

		assert(existeMunicipio(m.getNombre())==false);
		assert(getNumeroMunicipios() == (old.getNumeroMunicipios() + 1));

	};

	inline void borrarTodosLosMunicipios(){

		// Meter remove all 

	}



	/////////////////////////////////////////////////////////////////////

	//! \name Función de escritura de la clase Provincia

	void escribirMunicipios(){

		ed::Municipio m;

		std::cout << getCodigo() << " " << getNombre() << "\n";

		while(not _listaMunicipios.isLastItem()){



		}




	}





	/////////////////////////////////////////////////////////////////////

	//! Operaciones con ficheros


}; //Fin de la clase  Provincia


} // Fin del espacio de nombres ed

#endif // _PROVINCIA_HPP_
