/*!
  \file   funcionesAuxiliares.hpp
  \brief  Prototipos de las funciones auxiliares del programa principal de la asignatura
  \author Adrián López Ortiz
  \date 30-03-2017
  \version 2.0
*/

//Librerias
#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "asignatura.hpp"


namespace ed {

int menu();

/*! 
	\brief Comprueba que la asignatura este vacia
	\note Función codificada en el fichero cpp
	\param asignatura
	\return void
	\sa getNombre, estVacia
*/
	void comprobarAsignaturaVacia(ed::Asignatura const &asignatura);

/*! 
	\brief Carga la asignatura
	\note Función codificada en el fichero cpp
	\param asignatura
	\return void
	\sa cargarFichero
*/
	void cargarAsignatura(ed::Asignatura &asignatura);

/*! 
	\brief Graba la asignatura en un fichero
	\note Función codificada en el fichero cpp
	\param asignatura
	\return void
	\sa grabarFichero
*/
	void grabarAsignatura(ed::Asignatura  &asignatura);

/*! 
	\brief Consulta los datos de la asignatura: nombre,codigo,estudiantes,notas. 
	\note Función codificada en el fichero cpp
	\param asignatura
	\return void
	\sa getCodigo, getNombre, getNumeroEstudiantes
*/
	void consultarAsignatura(ed::Asignatura &asignatura);

/*! 
	\brief Modifica los datos principales de la asignatura: el codigo y el nombre. 
	\note Función codificada en el fichero cpp
	\param asignatura
	\return void
	\sa setNombre setCodigo
*/
	void modificarAsignatura(ed::Asignatura &asignatura);

/*! 
	\brief Borra una asignatura. 
	\note Función codificada en el fichero cpp
	\param asignatura
	\return void
	\sa estaVacia, getNombre, getApellidos, getEstudiante, borrarEstudiante
*/

	void borrarAsignatura(ed::Asignatura &asignatura);

/*! 
	\brief Consulta un estudiante de la asignatura. 
	\note Función codificada en el fichero cpp
	\param asignatura
	\return void
	\sa getEstudiante
*/

	void consultarEstudianteDeAsignatura(ed::Asignatura &asignatura);

/*! 
	\brief Inserta un nuevo estudiante en la asignatura. 
	\note Función codificada en el fichero cpp
	\param asignatura
	\return void
	\sa insertarEstudiante
*/
	void insertarEstudianteEnAsignatura(ed::Asignatura &asignatura);

/*! 
	\brief Modifica a un estudiante 
	\note Función codificada en el fichero cpp
	\param asignatura
	\return void
	\sa existeEstudiante, getEstudiante,escribirEstudiante, borrarEstudiante, insertarEstudiante, getNombre, getApellidos, getTeoria, getPractica, setApellidos, setNombre, setTeoria, setPractica, setEstudiante
*/
	void modificarEstudianteDeAsignatura(ed::Asignatura &asignatura);

/*! 
	\brief Borra a un estudiante de la asignatura. 
	\note Función codificada en el fichero cpp
	\param asignatura
	\return void
	\sa existeEstudiante, borrarEstudiante
*/
	void borrarEstudianteDeAsignatura(ed::Asignatura &asignatura);
}

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

