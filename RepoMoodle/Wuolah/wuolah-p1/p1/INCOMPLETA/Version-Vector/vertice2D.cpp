/*! 
   \file vertice2D.cpp
   \brief Fichero que contiene el código de las funciones de la clase Vertice2D
   \author Adrián López Ortiz
   \date 2 de Marzo de 2017
*/


// Ficheros de cabecera
#include <iostream>

#include "vertice2D.hpp"

/*
 Definiciones de las funciones lectura y escritura de la clase Vertice2D
*/
 
void ed::Vertice2D::leerVertice2D()
{

  double x, y;

  std::cout << "\n Lectura de las coordenadas de un vertice: P(x,y) " << std::endl;

  std::cout << " Abscisa: x --> ";
  std::cin >> x;

  std::cout << " Ordenada: y --> ";
  std::cin >> y;

  // Se asignan los valores leídos a los atributos del vertice   
  this->setX(x);
  this->setY(y);
}


void ed::Vertice2D::escribirVertice2D()
{
  std::cout << "(" << this->getX() << ", " << this->getY() << ")" << std::endl; 
}

////////////////////////////////////////////////////////////////////////////////

/*
 Definiciones de la función auxiliar de la clase Vertice2D
*/
double ed::calcularDistanciaEuclidea2D(ed::Vertice2D const&v1, ed::Vertice2D const&v2)
{
  return sqrt ( 
                  (v2.getX() - v1.getX()) * (v2.getX() - v1.getX())
                + (v2.getY() - v1.getY()) * (v2.getY() - v1.getY())
	             );
}


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{

//! \name Funciones amigas para poder acceder a la parte privada de Vertice2D.

// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, ed::Vertice2D const &v)
{
  stream << v._x;
  stream << " ";
  stream << v._y;

  return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Vertice2D &v)
{
  stream >> v._x;

  stream >> v._y;

  return stream;
} 

} // Fin del espacio de nombres ed
