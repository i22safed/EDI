/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 2
  \author Lourdes Jimenez Bravo
  \date 9/04/2018
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Provincia.hpp"


// SE DEBEN INCLUIR LOS COMENTARIOS DE DOXYGEN DE CADA FUNCIÓN

namespace ed
{
  /*!
		\brief   Muestra el menú del programa principal
		\return  Devuelve el número de opción elegido
	*/

  int menu();

	///////////////////////////////////////////////////////////////////

  /*!
		\brief  Comprueba si la provincia esta vacia
		\return void
*/

	void comprobarProvinciaVacia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

  /*!
  		\brief   Carga los municipios de una provincia de un fichero en una lista
  		\param   Provincia en la que se va a insertar los municipios
  		\return  void
      \sa      grabarProvincia
  */

	void cargarProvincia(ed::Provincia & provincia);

  /*!
  		\brief   Graba los municipios de una provincia en un fichero
  		\param   Provincia
  		\return  void
  	  \sa      cargarProvincia
  	*/
	void grabarProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

  /*!
  		\brief   Muestra los datos de una provincia
  		\param   Provincia
  		\return  void
  	*/

	void consultarDatosDeProvincia(ed::Provincia & provincia);

  /*!
  		\brief   Muestra los municipios de una provincia
  		\param   Provincia
  		\return  void
  	*/

	void mostrarMunicipiosDeProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

  /*!
		\brief   Modifica los datos de la provincia (nombre y codigo)
		\param   Provincia
		\return  void
	*/
	void modificarDatosDeProvincia(ed::Provincia & provincia);

  /*!
    \brief  Borra todos los municipios de la provincia
    \param   Provincia
    \return  void
  */

	void borrarTodosLosMunicipiosDeProvincia(ed::Provincia & provincia);


	///////////////////////////////////////////////////////////////////

  /*!
    \brief   Muestra un municipio de la Provincia
    \param   Provincia
    \return  void
  */

	void consultarMunicipioDeProvincia(ed::Provincia & provincia);

  /*!
    \brief   Inserta un municipio en la Provincia
    \param   Provincia
    \return  void
  */

	void insertarMunicipioEnProvincia(ed::Provincia & provincia);

  /*!
    \brief   Borra un municipio de la Provincia
    \param   Provincia
    \return  void
  */

	void borrarMunicipioDeProvincia(ed::Provincia & provincia);


} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif
