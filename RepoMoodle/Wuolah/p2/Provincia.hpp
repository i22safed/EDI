/*!
	\file  Provincia.hpp
	\brief Definición de la clase Provincia
	\author Lourdes Jimenez Bravo
	\date 9/04/2018
	\version 1.0

*/

#ifndef _PROVINCIA_HPP_
#define _PROVINCIA_HPP_

// Para comprobar las pre y post condiciones
#include <cassert>

#include <string>
#include <cstdlib>
#include <iostream>

#include <fstream>


#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"
#include "macros.hpp"
using namespace std;


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
		std::string						_nombre;     //!<  \brief Nombre de la Provincia
		int 							_codigo;	  //!<  \brief Código de la Provincia
		ed::ListaDoblementeEnlazadaOrdenadaMunicipios _listaMunicipios;      //!<  \brief Lista de municipios de la Provincia


	/////////////////////////////////////////////////////////////////////

	//!	\name  Métodos públicos de la clase Provincia

  public:

	//!	\name Constructor
		Provincia (string nombre = "", int codigo = 0)
		{

			std::cout << "Constructor de Provincia:" << std::endl << std::endl << std::endl;

			_nombre=nombre;
			_codigo=codigo;

			#ifndef NDEBUG
			    assert(getNombre()==nombre);
			    assert(getCodigo()==codigo);

				if (hayMunicipios() == true)
				{
					std::cout << "Constructor de Provincia: hayMunicipios() == true" << std::endl << std::endl << std::endl;
				}

			   assert(hayMunicipios()==false);
		    #endif
		}
	/////////////////////////////////////////////////////////////////////

	//!	\name Observadores

	/*!
		\brief  Devuelve el nombre de la Provincia
		\note   Función de tipo inline
		\return nombre de la Provincia
*/

	inline string getNombre()
	{
		return _nombre;
	}

	/*!
		\brief  Devuelve el codigo de la Provincia
		\note   Función de tipo inline
		\return codigo de la Provincia
*/

	inline int getCodigo()
	{
		return _codigo;
	}

	/*!
			\brief  Indica si la Provincia tiene o no municipios
			\note   Función de tipo inline
			\return Verdadero si tiene uno o más municipios; falso, en caso contrario
	*/
	inline bool hayMunicipios()
	{
		return not _listaMunicipios.isEmpty();
	}

	/*!
			\brief  Devuelve el número de municipios
			\note   Función de tipo inline
			\return numero de municipios de la Provincia
	*/
	inline int getNumeroMunicipios()
	{
		return _listaMunicipios.nItems();
	}

	/*!
			\brief   Comprueba si existe un municipio
			\note    Función de tipo inline
			\param   nombre del municipio buscado
			\return  Verdadero si existe el municipio; falso, en caso contrario
	*/
	inline bool existeMunicipio(string nombre)
	{
		if(_listaMunicipios.isEmpty()==false)
		{
		this->_listaMunicipios.gotoHead();
		while((this->_listaMunicipios.getCurrentItem().getNombre() != nombre) and (this->_listaMunicipios.isLastItem() == false))
		{
			this->_listaMunicipios.gotoNext();
		}
		if((this->_listaMunicipios.isLastItem() == true) and (this->_listaMunicipios.getCurrentItem().getNombre() != nombre))
		{
			return false;
		}
		if(this->_listaMunicipios.getCurrentItem().getNombre() == nombre)
		{
			return true;
		}
	}
		return false;
	}

	/*!
		\brief  Devuelve el municipio
		\param  nombre del municipio buscado
		\pre    Debe existir el municipio
		\return municipio
 	*/

	inline Municipio getMunicipio(string nombre)
	{
		#ifndef NDEBUG
		assert(existeMunicipio(nombre)==true);
		#endif

		this->existeMunicipio(nombre);
		return this->_listaMunicipios.getCurrentItem();
	}

	/*!
		\brief  Devuelve el total de hombres
		\return numero de hombres
	*/

	inline int getTotalHombres()
	{
		int c=0;
		this->_listaMunicipios.gotoHead();
		while(this->_listaMunicipios.isLastItem() != true)
		{
			c= c+(this->_listaMunicipios.getCurrentItem().getHombres());
			this->_listaMunicipios.gotoNext();
		}
		return c;
	}

	/*!
		\brief  Devuelve el total de mujeres
		\return numero de mujeres
	*/
	inline int getTotalMujeres()
	{
		int c=0;
		this->_listaMunicipios.gotoHead();
		while(this->_listaMunicipios.isLastItem() != true)
		{
			c= c+(this->_listaMunicipios.getCurrentItem().getMujeres());
			this->_listaMunicipios.gotoNext();
		}
		return c;
		}

		/*!
			\brief  Devuelve el total de habitantes
			\return numero total de habitantes
		*/

	inline int getTotalHabitantes()
	{
		int valorDevuelto = (getTotalHombres() + getTotalMujeres());

		#ifndef NDEBUG
		assert(valorDevuelto = getTotalHombres() + getTotalMujeres());
		#endif
		return valorDevuelto;
	}

	/////////////////////////////////////////////////////////////////////

	//!	\name Modificadores


	/*!
			\brief  Modifica el nombre de la provincia
			\note   Función inline
			\param  nombre
			\post   El nombre de la provincia deberá tener el nombre asignado
			\return No se devuelve ningún resultado
	*/
	inline void setNombre(string nombre)
	{
		_nombre=nombre;

		#ifndef NDEBUG
		assert(getNombre() == nombre);
		#endif
	}

	/*!
		\brief  Modifica el código de la provincia
		\note   Función inline
		\param  codigo
		\post   El código de la provincia deberá tener el código asignado
		\return No se devuelve ningún resultado

*/

	inline void setCodigo(int codigo)
	{
		_codigo=codigo;

		#ifndef NDEBUG
		assert(getCodigo() == codigo);
		#endif
	}

	/*!
		\brief  inserta un Municipio de forma ordenada
		\param  municipio
		\pre    No debe existir otro municipio con el mismo nombre
		\post   El municipio está insertado en la provincia.
		\post   El número de municipios debe haberse aumentado en uno
*/

	inline void insertarMunicipio(Municipio municipio)
	{
		#ifndef NDEBUG
		assert(existeMunicipio(municipio.getNombre()) == false);
		#endif

		int old=this->_listaMunicipios.nItems();

		this->_listaMunicipios.insert(municipio);

		#ifndef NDEBUG
		assert(existeMunicipio(municipio.getNombre()) == true);
		assert(getNumeroMunicipios() == (old+1));
		#endif
	}

	/*!
		\brief   Borra el municipio
		\param  nombre del municipio buscado
		\pre 	Debe existir el municipio
		\post   No debe existir un municipio con el nombre indicado
		\post   El número de municipios debe haberse reducido en uno
*/

	inline void borrarMunicipio(string nombre)
	{
		#ifndef NDEBUG
		assert(existeMunicipio(nombre) == true);
		#endif

		int old=this->_listaMunicipios.nItems();
		this->_listaMunicipios.remove();

		#ifndef NDEBUG
		assert(existeMunicipio(nombre) == false);
		assert(getNumeroMunicipios() == (old-1));
		#endif
	}
	/*!
		\brief   Borra todos los municipios
		\post   No deben existir un municipios
*/

	inline void borrarTodosLosMunicipios()
	{
		this->_listaMunicipios.removeAll();

		#ifndef NDEBUG
		assert(hayMunicipios() == false);
		#endif
	}



	/////////////////////////////////////////////////////////////////////

	//! \name Función de escritura de la clase Provincia

	inline void escribirMunicipios()
	{
		std::cout << this->getNombre() << "\t\t" << this->getCodigo() << "\t" << std::endl;

		if(_listaMunicipios.isEmpty()==false)
		{
		this->_listaMunicipios.gotoHead();

		while(this->_listaMunicipios.isLastItem() != true)
		{
			this->_listaMunicipios.getCurrentItem().escribirMunicipio();
			this->_listaMunicipios.gotoNext();
		}
	}
	}

	/////////////////////////////////////////////////////////////////////

	//! Operaciones con ficheros

	/*!
			\brief  Carga una provincia desde un fichero
			\param  nombre del fichero de la provincia
			\return Verdadero, si se ha cargado correctamente; falso, en caso contrario
	*/
	bool cargarFichero(string nombre)
	{
		Municipio aux;
		string linea;
		ifstream fich;
		fich.open(nombre.c_str());
		if(fich.fail())
		{
			std::cout << "Imposible abrir fichero de entrada" << std::endl;
			return false;
		}
		else
		{
			getline(fich, linea, ' ');
			this->setCodigo(atoi(linea.c_str()));
			getline(fich, linea, '\n');
			this->setNombre(linea);

			while(getline(fich, linea, ' '))
			{
				aux.setCodigoPostal(atoi(linea.c_str()));
				getline(fich, linea, ';');
				aux.setNombre(linea);
				getline(fich, linea, ';');
				aux.setHombres(atoi(linea.c_str()));
				getline(fich, linea, ';');
				aux.setMujeres(atoi(linea.c_str()));

				this->_listaMunicipios.insert(aux);
			}
			fich.close();
			return true;
		}
	}

	/*!
			\brief  Graba una provincia en un fichero
			\param  nombre del fichero de la provincia
			\return Verdadero, si se ha grabado correctamente; falso, en caso contrario
	*/
	bool grabarFichero(string nombre)
	{
		Municipio m;
		ofstream fichero (nombre.c_str());
		if(fichero.is_open())
		{
			fichero << getCodigo() << " " << getNombre() << endl;

			_listaMunicipios.gotoHead();
				while(_listaMunicipios.isLastItem()!=true)
				{
					fichero << _listaMunicipios.getCurrentItem() << endl;
					cout << BIYELLOW << "Municipio grabado" << RESET << _listaMunicipios.getCurrentItem() << endl;
					_listaMunicipios.gotoNext();
				}
			cout << BIYELLOW << "Municipio grabado" << RESET << _listaMunicipios.getCurrentItem() << endl;
			fichero << _listaMunicipios.getCurrentItem() << endl;
		}
		else{
			cout << "Error al abrir fichero" << endl;
			return false;
		}
		fichero.close();
		return true;
	}
}; //Fin de la clase  Provincia


} // Fin del espacio de nombres ed

#endif // _PROVINCIA_HPP_
