/*!

	\file  Provincia.cpp
	\brief Definición de la clase Provincia
	\author David Sanchez Fernandez
	\date 09/04/2018
	\version 1.0

*/
//Para los flujos de entrada/salida en ficheros.
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>


// Para comprobar las pre y post condiciones
#include <cassert>

#include "Provincia.hpp"


// DEBES CODIFICAR LAS FUNCIONES DE LA CLASE Provincia

///////////////////////////////////////////////////////////////////////////////

// OSBSERVADORES

bool ed::Provincia::existeMunicipio(std::string const &nombre){

     this->_listaMunicipios.gotoHead();

     while(not this->_listaMunicipios.isLastItem()){

          if(this->_listaMunicipios.getCurrentItem().getNombre()==nombre){

               return true;
          }

          this->_listaMunicipios.gotoNext();

     }

     return false;

}

ed::Municipio const & ed::Provincia::getMunicipio(std::string const &nombre){

          assert(existeMunicipio(nombre)==true);
          this->existeMunicipio(nombre);
          return this->_listaMunicipios.getCurrentItem();
}

int ed::Provincia::getTotalHombres(){

     int valorDevuelto = 0;

     this->_listaMunicipios.gotoHead();

     while(not _listaMunicipios.isLastItem()){

          valorDevuelto+=(this->_listaMunicipios.getCurrentItem().getHombres());
		this->_listaMunicipios.gotoNext();

     }

     return valorDevuelto;

}

int ed::Provincia::getTotalMujeres(){

     int valorDevuelto = 0;

     this->_listaMunicipios.gotoHead();

     while(not _listaMunicipios.isLastItem()){

          valorDevuelto+=(this->_listaMunicipios.getCurrentItem().getMujeres());
		this->_listaMunicipios.gotoNext();

     }

     return valorDevuelto;

}

int ed::Provincia::getTotalHabitantes(){

     int valorDevuelto = getTotalHombres() + getTotalMujeres();

     assert(valorDevuelto == getTotalHombres()+getTotalMujeres());

     return valorDevuelto;

}



/////////////////////////////////////////////////////////////////////////////////////////

// MODIFICADORES

void ed::Provincia::setNombre(std::string nombre){
     _nombre = nombre;
     assert(getNombre() == nombre);
};

void ed::Provincia::setCodigo(int codigo){
     _codigo = codigo;
     assert(getCodigo() == codigo);
};

void ed::Provincia::insertarMunicipio(ed::Municipio const & m){

     assert(existeMunicipio(m.getNombre())==false);

     int old=this->_listaMunicipios.nItems();
     this->_listaMunicipios.insert(m);

     assert(existeMunicipio(m.getNombre())==false);
     assert(getNumeroMunicipios() == (old + 1));

};


void ed::Provincia::borrarMunicipio(std::string const & nombre){

     assert(existeMunicipio(nombre)==true);

     int old = this->_listaMunicipios.nItems();

     _listaMunicipios.remove();

     assert(existeMunicipio(nombre)==false);
     assert(getNumeroMunicipios() == (old-1));

}

void ed::Provincia::borrarTodosLosMunicipios(){

     this->_listaMunicipios.removeAll();

     assert(hayMunicipios()==false);

}




///////////////////////////////////////////////////////////////////////////////////

// FUNCIÓN DE ESCRITURA

void ed::Provincia::escribirMunicipios(std::string const & nombre){

     std::cout << this->getNombre() << "\t\t" << std::endl << this->getCodigo() << "\t" << std::endl;

     this->_listaMunicipios.gotoHead();

     while(this->_listaMunicipios.isLastItem() != true)
     {
          this->_listaMunicipios.getCurrentItem().escribirMunicipio();
          this->_listaMunicipios.gotoNext();
     }

}

/////////////////////////////////////////////////////////////////////////////////////////

// OPERACIONES CON FICHEROS

bool ed::Provincia::cargarFichero(std::string const & nombre){

     Municipio m;
     std::string linea;
     std::ifstream file;
     file.open(nombre.c_str());
     if(file.is_open()){

          std::cout << "Error al abrir el fichero " << nombre << std::endl;
          return false;

     }else{

          getline(file, linea, ' ');
          this->setCodigo(atoi(linea.c_str()));
          getline(file, linea, '\n');
          this->setNombre(linea);

          while(getline(file, linea, ' ')){

               m.setCodigoPostal(atoi(linea.c_str()));
               getline(file, linea, ';');
               m.setNombre(linea);
               getline(file, linea, ';');
               m.setHombres(atoi(linea.c_str()));
               getline(file, linea, ';');
               m.setMujeres(atoi(linea.c_str()));

               this->_listaMunicipios.insert(m);
          }

          file.close();
          return true;
     }


}


bool ed::Provincia::grabarFichero(std::string const & nombre){

     std::ofstream file;
     std::string linea;

     file.open(nombre.c_str());

     if(file.is_open()){

          std::cout << "Error al abrir el fichero "<< nombre << std::endl;
          return false;

     }else{

          linea=getNombre();
          file << linea;
          return true;
     }
}
