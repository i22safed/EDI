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
			if(getCurrentItem() == m){

				#ifndef NDEBUG
     				// Se comprueba la postcondición
     				assert ( getCurrentItem() == m );
				#endif //NDEBUG

				return true;
		}

			gotoNext();

		}

	}//Fin Else

	if(getCurrentItem() == m){
          return true;
     }

	return false;
}


bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::isFirstItem() const{

	#ifndef NDEBUG
	// Se comprueba la precondición
	assert( !this->isEmpty() );
	#endif //NDEBUG

	if ( getCurrent() == getHead() ) {
		return true;
	}

	else{ return false; }

}

bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::isLastItem() const{

	#ifndef NDEBUG
	// Se comprueba la precondición
	assert( !this->isEmpty() );
	#endif //NDEBUG

	if( getCurrent()->getNext() == NULL ){
		return true;
	}

	else{ return false; }

}

ed::Municipio const & ed::ListaDoblementeEnlazadaOrdenadaMunicipios:: getCurrentItem() const{

	#ifndef NDEBUG
	// Se comprueba la precondición
	assert(!this->isEmpty());
	#endif //NDEBUG

	return getCurrent()->getItem();

}

ed::Municipio const & ed::ListaDoblementeEnlazadaOrdenadaMunicipios:: getPreviousItem() const{

	#ifndef NDEBUG
	// Se comprueba la precondición
	assert( !this->isEmpty() );
	#endif //NDEBUG

	#ifndef NDEBUG
	// Se comprueba la precondición
	assert( !isFirstItem() );
	#endif //NDEBUG

	return getCurrent()->getPrevious()->getItem();

}


ed::Municipio const & ed::ListaDoblementeEnlazadaOrdenadaMunicipios:: getNextItem() const{

	#ifndef NDEBUG
	// Se comprueba la precondición
	assert( !this->isEmpty() );
	#endif //NDEBUG

	#ifndef NDEBUG
	// Se comprueba la precondición
	assert( !isLastItem() );
	#endif //NDEBUG

	return getCurrent()->getNext()->getItem();

}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoHead(){

	#ifndef NDEBUG
	// Se comprueba la precondición
	assert( !this->isEmpty() );
	#endif //NDEBUG

	setCurrent(getHead());

	#ifndef NDEBUG
	// Se comprueba la postcondición
	assert( isFirstItem() );
	#endif //NDEBUG

}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoLast(){

	#ifndef NDEBUG
	// Se comprueba la precondición
	assert( !this->isEmpty() );
	#endif //NDEBUG

	while( !isLastItem() ){

		setCurrent(getCurrent()->getNext());

	}

	#ifndef NDEBUG
	// Se comprueba la postgcondición
	assert( isLastItem() );
	#endif //NDEBUG

}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoPrevious(){

	#ifndef NDEBUG
	// Se comprueba la precondición
	assert( !this->isEmpty() );
	#endif //NDEBUG

	#ifndef NDEBUG
	// Se comprueba la precondición
	assert(!isFirstItem());
	#endif //NDEBUG

	setCurrent(getCurrent()->getPrevious());

}


void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoNext(){

	#ifndef NDEBUG
	// Se comprueba la precondición
	assert( !this->isEmpty() );
	#endif //NDEBUG


	setCurrent(getCurrent()->getNext());

}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::insert(ed::Municipio const &m){

	ed::NodoDoblementeEnlazadoMunicipio * n;
	n=new NodoDoblementeEnlazadoMunicipio(m,NULL,NULL);

	if(isEmpty()){//Si esta vacia se introduce el elemento como cabeza.
		n->setPrevious(NULL);
		n->setNext(NULL);
		setHead(n);
		setCurrent(getHead());
		return;
	}

	else{
		gotoHead();

		while(!isLastItem()){//Recorre la lista desde la cabeza hasta encontrar la posicion en la que iria encajado el nuevo elemento

			if(m < getCurrentItem()){
				break;

			}

			gotoNext();
		}

		if(isFirstItem() && isLastItem()){//Si solo hay un elemento y el item a introducir ba antes se introduce este como cabeza.
			if( m < getCurrentItem() ){
				n->setPrevious(NULL);
				n->setNext(getCurrent());
				getCurrent()->setPrevious(n);
				gotoPrevious();
				setHead(getCurrent());
			}
			else{//Si no se introduce como ultimo elemento de la lista, justo detras de la cabeza
				n->setNext(NULL);
				n->setPrevious(getCurrent());
				getCurrent()->setNext(n);
				gotoNext();
			}

		}


		else if(isFirstItem()){//si va insertado al principio se pone como cabeza
			n->setPrevious(NULL);
			n->setNext(getCurrent());
			getCurrent()->setPrevious(n);
			setHead(n);
			gotoHead();
		}

		else if(isLastItem()){//En este caso se colocara el o el penultimo
			if(getCurrentItem()<m){//Si es menor que el ultimo se colocora el penultimo
				n->setNext(NULL);
				n->setPrevious(getCurrent());
				getCurrent()->setNext(n);
				gotoNext();
			}

			else{//En caso contrario se colocara el ultimo
				n->setPrevious(getCurrent()->getPrevious());
				n->setNext(getCurrent());
				getCurrent()->setPrevious(n);
				gotoPrevious();
				getCurrent()->getPrevious()->setNext(getCurrent());
			}
		}

		else{//Este es el ultimo caso, que el nuevo elemento va introducido entre dos elementos
			n->setPrevious(getCurrent()->getPrevious());
			n->setNext(getCurrent());
			getCurrent()->setPrevious(n);
			gotoPrevious();
			getCurrent()->getPrevious()->setNext(getCurrent());
		}
	}

	#ifndef NDEBUG
	//Se comprueba la postcondiciones
	assert(!isEmpty() and getCurrentItem()==m);
	#endif

}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::remove(){


	#ifndef NDEBUG
	// Se comprueba la precondición
	assert(!this->isEmpty());
	#endif //NDEBUG



	if( isFirstItem() ){//Si queremos borrar el primer elemento

		if( isLastItem() ){//Si la lista solo tiene un Item la lista se queda vacia.
			delete getCurrent();
			setHead(NULL);
			setCurrent(NULL);
		}

		else{//Si no el segundo elemento pasa a ser la cabeza

			setHead(getCurrent()->getNext());
			delete getCurrent();
			setCurrent(getHead());
			getCurrent()->setPrevious(NULL);
		}
	}
	else if ( isLastItem() ){//Si queremos borra el ultimo elemento el penultimo pasa a ser el ultimo y apunta el siguiente a NULL.

		gotoPrevious();
		delete getCurrent()->getNext();
		getCurrent()->setNext(NULL);
	}

	else{//Si queremos borrar un elemento de en medio se enlazan el anterior y el posterior a este entre si y luego se borra el elemento a borrar.


		getCurrent()->getPrevious()->setNext( getCurrent()->getNext() );//anterior->siguiente

		getCurrent()->getNext()->setPrevious( getCurrent()->getPrevious() );//anterior<-siguiente

		delete getCurrent();
		gotoHead();
	}


}
