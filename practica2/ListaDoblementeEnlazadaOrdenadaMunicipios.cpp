/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.cpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author
	\date
	\version 1.0
*/

// Para comprobar las pre y post-condiciones
#include <cassert>

#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"
#include "NodoMunicipioInterfaz.hpp"
#include "Municipio.hpp"

// DEBES CODIFICAR LAS FUNCIONES DE LA CLASE ListaDoblementeEnlazadaOrdenadaMunicipios


int ed::ListaDoblementeEnlazadaOrdenadaMunicipios::nItems() const {

	ed::NodoDoblementeEnlazadoMunicipio * n;
	int N=0;

	if( isEmpty() ) {//El numero de items es cero ya que la lista esta vacia.
		return 0;
	}

	else{
		n=getHead();

		while(n->getNext() !=NULL){

			N++;
			n=n->getNext();

		}//Fin while

		N++;
		return N;
	}//Fin else
}


bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::find(ed::Municipio  const & m){

	// Si la lista está vacía, no lo encuentra
	if (isEmpty()){
		return false;

     }else{

     	gotoHead();

		while(not isLastItem()){
			if(getCurrentItem() == item){

				#ifndef NDEBUG
     				// Se comprueba la postcondición
     				assert ( getCurrentItem() == item );
				#endif //NDEBUG

				return true;
		}

			gotoNext();

		}

	}//Fin Else

	if(getCurrentItem() == item){
          return true;
     }

	return false;
}
