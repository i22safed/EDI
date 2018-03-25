/*!
  \file   funcionesAuxiliares.hpp
  \brief  Código de las funciones auxiliares del programa principal de la asignatura
  \author Adrián López Ortiz
  \date   30-03-2017
*/

//Librerias
#include <iostream>
#include <string>

#include "funcionesAuxiliares.hpp"
#include "estudiante.hpp"

#include "macros.hpp"


int ed::menu(){

	int opcion, posicion;

	// Se muestran las opciones del menú
	posicion=8;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	LUGAR(5,10);
   	std::cout << BBLUE;

	std::cout << "Programa principial | Opciones del menú   ";
	std::cout << RESET;

	LUGAR(posicion++,10);
	std::cout <<RED<< "[1] Comprobar si la asignatura está vacía";

	LUGAR(posicion++,10);
	std::cout <<WHITE<< "[2] Cargar la asignatura de un fichero";

	LUGAR(posicion++,10);
	std::cout <<RED<< "[3] Grabar la asignatura en un fichero";

	LUGAR(posicion++,10);
	std::cout <<WHITE<< "[4] Consultar datos de la asignatura: código, nombre, lista de estudiantes";

	LUGAR(posicion++,10);
	std::cout <<RED<< "[5] Modificar datos de la asignatura: código o nombre";

	LUGAR(posicion++,10);
	std::cout <<WHITE<< "[6] Borrar una asignatura";

	LUGAR(posicion++,10);
	std::cout <<RED<< "[7] Consultar un estudiante";

	LUGAR(posicion++,10);
	std::cout <<BLUE<< "[8] Insertar un estudiante";

	LUGAR(posicion++,10);
	std::cout <<BLUE<< "[9] Modificar un estudiante";

	LUGAR(posicion++,10);
	std::cout <<BLUE<< "[10] Borrar un estudiante";

	LUGAR(posicion++,10);
	std::cout << GREEN << "[0] Salir";

	LUGAR(posicion++,20);
	std::cout << IYELLOW;

	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

	// Se elimina el salto de línea del flujo de entrada
	std::cin.ignore();

	return opcion;
}


void ed::comprobarAsignaturaVacia(ed::Asignatura const &asignatura){

	std::cout << "La asignatura de nombre < " << asignatura.getNombre() << " > ";

	if (asignatura.estaVacia() == true)
		std::cout << "está vacía";

	else
		std::cout << "no está vacía";

return;
}


void ed::cargarAsignatura(ed::Asignatura &asignatura){

	std::string nombreFichero;
 	
  	std::cout<<"Introduce el nombre del fichero que quieres cargar: ";
  	std::cin>>nombreFichero;
  	
	asignatura.cargarFichero(nombreFichero);
return;
}


void ed::grabarAsignatura(ed::Asignatura  &asignatura){
	
	std::string nombreFichero;
 
  	std::cout<<"Introduce el nombre del fichero que quieres grabar los datos actuales: ";
  	std::cin>>nombreFichero;

	asignatura.grabarFichero(nombreFichero);

return;
}


void ed::consultarAsignatura(ed::Asignatura  &asignatura){
	
	int i;
	std::cout<<asignatura.getNombre()<<std::endl<<asignatura.getCodigo()<<std::endl;
	
	std::cout<< "Número de estudiantes de la asignatura " << asignatura.getNumeroEstudiantes() << std::endl;
	
	for(i=0;i<asignatura.getNumeroEstudiantes();i++){
		std::cout<<"estudiante "<< i <<" -> "<< asignatura.getEstudiante(i)<<std::endl;
	}		

return;
}

void ed::modificarAsignatura(ed::Asignatura &asignatura){
	
	int opcion,codigo,posicion;
		
	// Se muestran las opciones del menú
	posicion=8;;
	
	std::string nombre;
	
	std::cout << CLEAR_SCREEN;

	LUGAR(5,10);
	std::cout << BBLUE;
	std::cout << "Programa principal | Opciones del menú   ";
	std::cout << RESET;

	LUGAR(posicion++,10);
	std::cout << "[1] Cambiar nombre:" << std::endl;;
	LUGAR(posicion++,10);
	std::cout << "[2] Cambiar codigo" << std::endl;

	LUGAR(posicion++,10);
	std::cout << GREEN << "[0] Salir";

	LUGAR(posicion++,20);
	std::cout << IYELLOW;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

	// Se elimina el salto de línea del flujo de entrada
	std::cin.ignore();
	

	// Se ejecuta la opción del menú elegida
	switch(opcion){
		case 0: //Caso Cambiar Nombre
			std::cout << INVERSE;
			std::cout << RESET;
		break;


		case 1: 
			std::cout << "[1] Cambiar nombre:" << std::endl;
			std::cout<<"Introduce un nuevo nombre: ";
			std::cin>>nombre;
			asignatura.setNombre(nombre);
		break;


		case 2://Caso Cambiar Codigo
			std::cout << "[2] Cambiar codigo" << std::endl;
			std::cout<<"Introduce un nuevo codigo: ";
			std::cin>>codigo;
			asignatura.setCodigo(codigo);
		break;

			
		default://Caso por defecto: opcion incorrecta
			LUGAR(25,25);
			std::cout << INVERSE;
			std::cout << "Opción incorrecta ";
			std::cout << RESET;
			std::cout << RED;
			std::cout << " --> " << opcion << std::endl;
			std::cout << RESET;
	}
	
return;
}


void ed::borrarAsignatura(ed::Asignatura &asignatura){

	asignatura.setCodigo(0);
	asignatura.setNombre("");

	while( !asignatura.estaVacia() ){//Va borrando uno a uno cada estudiante de la asignatura.
		asignatura.borrarEstudiante(asignatura.getEstudiante(0).getNombre(),asignatura.getEstudiante(0).getApellidos());
	}

	std::cout << std::endl << "Asignatura borrada\n";
return;
}


void ed::consultarEstudianteDeAsignatura(ed::Asignatura &asignatura){

	if( asignatura.estaVacia() ){
		std::cout<<"La asignatura esta vacia\n";
		return;
	}
	
	std::string nombre,apellidos;

	
	std::cout<<"Introduce el nombre: ";
	std::getline(std::cin,nombre);
	
	std::cout<<"Introduce el apellidos: ";
	std::getline(std::cin,apellidos);
	
	if(!asignatura.existeEstudiante(nombre,apellidos) ){
		std::cout<<"El estudiante no existe.\n";
		return;
	}
	
	std::cout<< asignatura.getEstudiante(nombre,apellidos);
	
return;
}



void ed::insertarEstudianteEnAsignatura(ed::Asignatura &asignatura){
	
	float teoria,practica;
	std::string nombre,apellidos;

	std::cout<<"Introduce el nombre: ";
	std::getline(std::cin,nombre);
	
	std::cout<<"Introduce el apellidos: ";
	std::getline(std::cin,apellidos);
	
	std::cout<<"Introduce la nota de teoria: ";
	std::cin>>teoria;
	std::cin.ignore();	
	
	std::cout<<"Introduce la nota practica: ";
	std::cin>>practica;
	std::cin.ignore();
  
	asignatura.insertarEstudiante(nombre,apellidos,teoria,practica);

return;
}
 

void ed::modificarEstudianteDeAsignatura(ed::Asignatura &asignatura){
	int opcion;
	bool control;

	std::string nombre, apellidos;
	float nota;

	ed::Estudiante estudiante;
  	ed::Estudiante nuevoEstudiante;

	std::cout << "Nombre: ";
	std::getline(std::cin,nombre);

  	std::cout << "Apellidos: ";
  	std::getline(std::cin,apellidos);

	control = asignatura.existeEstudiante(nombre,apellidos);

	if (control == true){
		estudiante = asignatura.getEstudiante(nombre,apellidos);

			 do{
				std::cout << "Datos actuales del estudiante: " << std::endl;
				estudiante.escribirEstudiante();
	
				std::cout << std::endl;
				std::cout << "Indique qué dato desea modificar: " << std::endl;
				std::cout << "(1) nombre" << std::endl;
				std::cout << "(2) apelllidos" << std::endl;
				std::cout << "(3) nota de teoría " << std::endl;
				std::cout << "(4) nota prácticas" << std::endl;

				std::cout << "(0) salir" << std::endl << std::endl;
				std::cin >> opcion;	
				// Se elimina el salto de línea del flujo de entrada
				  std::cin.ignore();
			
				switch(opcion){
					case 0: 
						// Fin de las modificaciones
						break;
					case 1:
						nuevoEstudiante = estudiante;

						std::cout << "Nuevo nombre: ";
						std::getline(std::cin,nombre);
						nuevoEstudiante.setNombre(nombre);

						// Se comprueba que no existe otro estudiante con la misma clave
						if (not asignatura.existeEstudiante(nuevoEstudiante.getNombre(),nuevoEstudiante.getApellidos())){
							// Como se ha modificado un campo de la clave, se borra el antiguo estudiante 
							// y se inserta el estudiante modficado de forma ordenada
							asignatura.borrarEstudiante(estudiante.getNombre(),estudiante.getApellidos());									
							asignatura.insertarEstudiante(nuevoEstudiante.getNombre(),nuevoEstudiante.getApellidos(),nuevoEstudiante.getTeoria(),nuevoEstudiante.getPractica());	

							estudiante = nuevoEstudiante;
						}
						// Se indica que ya existe un estudiante con la misma clave
						else{
							std::cout << std::endl << "No se puede modificar el nombre porque tendría la misma clave que otro estudiante" << std::endl;
						}
						break;

					case 2:
						nuevoEstudiante = estudiante;

						std::cout << "Nuevos apellidos: ";
						std::getline(std::cin,apellidos);
						nuevoEstudiante.setApellidos(apellidos);

						// Se comprueba que no existe otro estudiante con la misma clave
						if (not asignatura.existeEstudiante(nuevoEstudiante.getNombre(),nuevoEstudiante.getApellidos())){
							// Como se ha modificado un campo de la clave, se borra el antiguo estudiante 
							// y se inserta el estudiante modficado de forma ordenada
							asignatura.borrarEstudiante(estudiante.getNombre(),estudiante.getApellidos());									
							asignatura.insertarEstudiante(nuevoEstudiante.getNombre(),nuevoEstudiante.getApellidos(),nuevoEstudiante.getTeoria(),nuevoEstudiante.getPractica());	

							estudiante = nuevoEstudiante;
						}
						// Se indica que ya existe un estudiante con la misma clave
						else{
							std::cout << std::endl << "No se puede modificar el nombre porque tendría la misma clave que otro estudiante" << std::endl;
											}
							break;

					case 3:
						std::cout << "Nueva nota de teoría ";
						std::cin >> nota;
						estudiante.setTeoria(nota);

						// Se modifica su nota
						asignatura.setEstudiante(estudiante);
						break;

					case 4:
						std::cout << "Nueva nota de prácticas ";
						std::cin >> nota;
						estudiante.setPractica(nota);

						// Se modifica su nota
						asignatura.setEstudiante(estudiante);
						break;

					default:
						std::cout<< std::endl << "Opción incorrecta" << std::endl;
				}
			}while (opcion != 0);
	}	
	else{
		std::cout << std::endl << "El estudiante " << nombre << " " << apellidos << " ";
		std::cout << "no pertenece a la asignatura";
	}

	return;
}


void ed::borrarEstudianteDeAsignatura(ed::Asignatura &asignatura){



	bool control;
	std::string nombre, apellidos;
	ed::Estudiante estudiante;


	std::cout << "Nombre: ";
	std::getline(std::cin,nombre);

	std::cout << "Apellidos: ";
	std::getline(std::cin,apellidos);

	control = asignatura.existeEstudiante(nombre,apellidos);	

	if (control == true){
		asignatura.borrarEstudiante(nombre,apellidos);
		control = asignatura.existeEstudiante(nombre,apellidos);	

			if (control == true)
				std::cout << "El estudiante no ha podido ser borrado" << std::endl;
			else
				std::cout << "El estudiante ha sido borrado correctamente" << std::endl;
	}	
	else{
		std::cout << "El estudiante  "<< nombre << " " << apellidos << " ";
		std::cout << "no pertenece a la asignatura";
	}	

return;
}
