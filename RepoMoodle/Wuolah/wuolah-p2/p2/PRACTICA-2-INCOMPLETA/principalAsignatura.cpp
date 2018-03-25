/*!

	\file principalAsignatura.cpp
	\brief Programa principal de la practica 2 de ED, Asignatura de estudiantes
	\author Adrián López Ortiz
	\date 30-12-2017
	\version 2.0
*/

/*!
	\mainpage Implementación de una asignatura utilizando una lista doblemente enlazada y ordenada de estudiantes
	\author   Nicolás Luis Fernández García
	\date     2016-3-4
	\version  1.0
*/

//Librerias
#include <iostream>
#include <stdio.h>
#include <string>

#include "asignatura.hpp"
#include "estudiante.hpp"

#include "funcionesAuxiliares.hpp"
#include "macros.hpp"


int main(){

	ed::Asignatura asignatura;

	int opcion;

	do{

		// Se elige la opción del menún
		opcion = ed::menu();		

		std::cout << CLEAR_SCREEN;
		LUGAR(5,1);

		// Se ejecuta la opción del menú elegida
		switch(opcion)
		{
			case 0://Fin del programa 
				std::cout << INVERSE;
				std::cout << "Fin del programa" << std::endl;
				std::cout << RESET;
			break;


			case 1: //ComprobarAsignaturaVacia
				std::cout <<YELLOW<<"[1] "<<CYAN<< "Comprobar si la asignatura está vacía"<<RESET<< std::endl;
				ed::comprobarAsignaturaVacia(asignatura);
			break;


			case 2: //CargarAsignatura
				std::cout <<YELLOW<<"[2] "<<CYAN<<"Cargar la asignatura de un fichero"<<RESET<< std::endl;
				ed::cargarAsignatura(asignatura);
			break;


			case 3: //GrabarAsignatura
				std::cout <<YELLOW<< "[3] "<<CYAN<< "Grabar la asignatura en un fichero"<<RESET << std::endl;
				ed::grabarAsignatura(asignatura);
			break;


			case 4://ConsultarAsignatura
			  	std::cout <<YELLOW<<"[4] "<<CYAN<< "Consultar datos de la asignatura: " <<RESET<< std::endl; 
				ed::consultarAsignatura(asignatura);
			break;


			case 5://ModificarAsignatura
				std::cout <<YELLOW<<"[5] "<<CYAN << "Modificar datos de la asignatura: código o nombre"<<RESET << std::endl;
				ed::modificarAsignatura(asignatura);
			break;


			case 6: //BorrarAsignatura
				std::cout <<YELLOW<< "[6] "<<CYAN<< "Borrar una asignatura" <<RESET<< std::endl;
				ed::borrarAsignatura(asignatura);
			break;


			case 7://ConsultarEstudianteAsignatura
				std::cout <<YELLOW<< "[7] "<<CYAN<< "Consultar un estudiante" <<RESET<< std::endl;
				consultarEstudianteDeAsignatura(asignatura);
			break;


			case 8://InsertarEstudiante
				std::cout <<YELLOW<< "[8] "<<CYAN<< "Insertar un estudiante" <<RESET<< std::endl;
				insertarEstudianteEnAsignatura(asignatura);
			break;


			case 9://ModificarEstudianteAsignatura
				std::cout <<YELLOW<<"[9] "<<CYAN<<"Modificar un estudiante"<<RESET << std::endl;
				modificarEstudianteDeAsignatura(asignatura);
			break;


			case 10: //BorrarEstudianteAsignatura
				std::cout << YELLOW<<"[10] " <<CYAN<< "Borrar un estudiante" <<RESET<< std::endl;
				borrarEstudianteDeAsignatura(asignatura);
			break;


			default://Opcion incorrecta
				LUGAR(25,25);
				std::cout << INVERSE;
				std::cout << "Opción incorrecta ";
				std::cout << RESET;
			  	std::cout << RED;
				std::cout << " --> " << opcion << std::endl;
				std::cout << RESET;
		}
  
		if (opcion !=0){//Pulsar ENTER para continuar

			LUGAR(30,25);
			std::cout << "pulse ";

			std::cout << UNDERLINE;
			std::cout << IPURPLE;
			std::cout << "ENTER";

			std::cout << RESET;
			std::cout << " para ";

			std::cout << INVERSE;
			std::cout << "continuar"; 

			std::cout << RESET;

			getchar();
			std::cout << CLEAR_SCREEN;
		}
	
	}while(opcion!=0);

	return 0;
}//FIN MAIN

