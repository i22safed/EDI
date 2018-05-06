/*!
   \file  Medicion.cpp
   \brief Fichero que contiene el código de las funciones de la clase Medicion
*/


// Ficheros de cabecera
#include <iostream>

// atoi, atof
#include <stdlib.h>

#include "Medicion.hpp"


// COMPLETAR


////////////////////////////////////////////////////////////////////////////////


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{

void ed::Medicion::escribirMedicion()const{

     ed::Fecha fecha;

     std::cout << fecha.getDia() << "-"
          << fecha.getMes() << "-"
          << fecha.getAgno() << " "
          << getPrecipitacion() << std::endl;

}

void ed::Medicion::leerMedicion(){

     ed::Fecha fecha;
     float precipitacion=0.0;

     fecha.leerFecha();
     this->setFecha(fecha);

     std::cout << " Precipitacion --> ";
     std::cin >> precipitacion;
     this->setPrecipitacion(precipitacion);

}



// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, ed::Medicion const &medicion){

     stream << medicion.getFecha();
     stream << " ";
     stream << medicion.getPrecipitacion();
     stream << "\n";

     return stream;

}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Medicion &m){

     std::string cadena;
     Fecha f;

     std::getline(stream,cadena,'-');
     f.setDia(atoi(cadena.c_str()));
     std::getline(stream,cadena,'-');
     f.setMes(atoi(cadena.c_str()));
     std::getline(stream,cadena,'-');
     f.setAgno(atoi(cadena.c_str()));

     m.setFecha(f);

     std::getline(stream,cadena,'\n');

     m.setPrecipitacion(atof(cadena.c_str())); // Cast a dato tipo real

     return stream;

}

} // Fin del espacio de nombres ed
