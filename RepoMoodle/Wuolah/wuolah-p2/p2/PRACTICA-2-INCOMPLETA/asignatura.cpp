/*!	

	\file  asignatura.cpp
	\brief Definición de la clase Asignatura
	\author Adrián López Ortiz
	\date 30-03-17
	\version 2.0

*/

#include "asignatura.hpp"

ed::Estudiante const &ed::Asignatura::getEstudiante (std::string const &nombre, std::string const &apellidos){

	if(!existeEstudiante(nombre,apellidos)){
	std::cout<<"No existe estudiante\n";
	exit(-1);
	}
		
	else{return _lista.getCurrentItem();}
}


ed::Estudiante const &ed::Asignatura::getEstudiante (int indice){

	int i=0;
	
	//Precondiciones
	//Debe existir el estudiante
	if( indice >= _lista.nItems() ){exit(-1);}
	
	_lista.gotoHead();
	
	for(i=0;i<indice;i++){_lista.gotoNext();}
	
	//Una vez llegamos al item con el cursor lo devolvemos
	return _lista.getCurrentItem();
}

bool ed::Asignatura::insertarEstudiante(std::string const &nombre, std::string const &apellidos,float teoria, float practica){

	ed::Estudiante e;
	
	e.setNombre(nombre);
	e.setApellidos(apellidos);
	e.setTeoria(teoria);
	e.setPractica(practica);
	
	
	if (existeEstudiante(nombre,apellidos)){
	std::cout<<"devuelve falso\n";
	return false;
	}
	
	else{
	
		_lista.insert(e);
		return true;
	}
	

}

bool ed::Asignatura::borrarEstudiante (std::string const &nombre, std::string const &apellidos){

	
	if(!existeEstudiante(nombre,apellidos)){
	std::cout<< "\n:3\n";
	return false;}
	
	else{
		_lista.remove();
		// Se comprueba la postcondición de numero de Items en remove();
		

		return true;
	}
}


bool ed::Asignatura::cargarFichero(std::string const &nombreFichero){

	ed::Estudiante e;
	int codigo;
	std::string nombre;
	
	std::ifstream fichero( nombreFichero.c_str() );

	if(!fichero){
		std::cout<<"No existe tal fichero\n";
		std::cin.ignore();
		return false;
	}
	
	fichero>>nombre>>codigo;
	fichero.ignore();
	
	setNombre(nombre);
	setCodigo(codigo);
	
	std::cout<<getNombre()<<std::endl<<getCodigo()<<std::endl;
	
	while (fichero>>e)
	{	
		std::cout<< e <<std::endl;
		
		_lista.insert(e);
	}
	
	
	fichero.close();
	return true;
}
	
	
bool ed::Asignatura::grabarFichero(std::string const &nombreFichero){

	ed::Estudiante e;
	std::ofstream fichero( nombreFichero.c_str() );
	if( estaVacia() ){
	
		std::cout<<"No hay ninguna asignatura cargada\n";
		std::cin.ignore();
		return false;
	}
	
	_lista.gotoHead();
	
	fichero<<getNombre()<<std::endl<<getCodigo()<<std::endl;
	
	while(!_lista.isLastItem()){
		
		fichero<<_lista.getCurrentItem();
		_lista.gotoNext();
	}
		fichero<<_lista.getCurrentItem();
	fichero.close();
	return true;
	
}
