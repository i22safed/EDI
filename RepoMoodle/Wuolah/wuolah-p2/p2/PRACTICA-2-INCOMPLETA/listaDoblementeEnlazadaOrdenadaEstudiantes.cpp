/*!
	\file listaDoblementeEnlazadaOrdenadaEstudiantes.cpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Estudiantes
	\author Adrián López Ortiz
	\date  30-03-2017
	\version 2.0
*/

#include "listaDoblementeEnlazadaOrdenadaEstudiantes.hpp"

//Calcula el numero de items de la lista de estudiantes
int ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::nItems() const {

	ed::NodoDoblementeEnlazadoEstudiante * n;
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


//Devuelve el estudiante actual de la lista de estudiantes
ed::Estudiante const & ed::ListaDoblementeEnlazadaOrdenadaEstudiantes:: getCurrentItem() const{
	
	#ifndef NDEBUG
	// Se comprueba la precondición
	assert(!this->isEmpty());
	#endif //NDEBUG
	
	return getCurrent()->getItem();

}

//Devuelve el estudiante anterior al actual de la lista de estudiantes
ed::Estudiante const & ed::ListaDoblementeEnlazadaOrdenadaEstudiantes:: getPreviousItem() const{

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


//Devuelve el estudiante anterior al actual de la lista de estudiantes
ed::Estudiante const & ed::ListaDoblementeEnlazadaOrdenadaEstudiantes:: getNextItem() const{

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


//Devuelve un booleano respondiendo a la pregunta de si el elemento actual es el primer elemento de la lista. Devolvera verdadero si es el primer Item y falso en caso contrario
bool ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::isFirstItem() const{
	
	#ifndef NDEBUG
	// Se comprueba la precondición
	assert( !this->isEmpty() );
	#endif //NDEBUG
	
	if ( getCurrent() == getHead() ) {
		return true;
	}
	
	else{ return false; }
	
}


//Devuelve un booleano respondiendo a la pregunta de si el elemento actual es el ultimo elemento de la lista. Devolvera verdadero si es el ultimo Item y falso en caso contrario
bool ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::isLastItem() const{
	
	#ifndef NDEBUG
	// Se comprueba la precondición
	assert( !this->isEmpty() );
	#endif //NDEBUG
		
	if( getCurrent()->getNext() == NULL ){
		return true;
	}
	
	else{ return false; }

}

//Funcion void que lleva el puntero actual al primer estudiante de la lista.
void ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::gotoHead(){
	
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


//Funcion void que lleva el puntero actual al ultimo estudiante de la lista.
void ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::gotoLast(){
	
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


//Funcion void que lleva el puntero actual al anterior estudiante de la lista.
void ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::gotoPrevious(){

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


//Funcion void que lleva el puntero actual al siguiente estudiante de la lista.
void ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::gotoNext(){

	#ifndef NDEBUG
	// Se comprueba la precondición
	assert( !this->isEmpty() );
	#endif //NDEBUG
	
	
	setCurrent(getCurrent()->getNext());
	
}


//Coloca el cursor en el nodo que contiene al estudiante en su campo informativo, si existe, si existe devuelve true y en caso contrario false.
bool ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::find(ed::Estudiante  const & item){

	// Si la lista está vacía, no lo encuentra
	if (isEmpty())
		return false;

	// Si la lista no está vacía, lo busca
	else{
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

	if(getCurrentItem() == item){ return true;}
	
	return false;
}


//Modifica un Estudiante pero sin modificar su clave: apellidos y nombre.
void ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::setCurrentItem(ed::Estudiante const & item){
	
	#ifndef NDEBUG
	// Se comprueba la precondición
	assert( !this->isEmpty() );
	#endif //NDEBUG
	
	if( ( getCurrent()->getItem().getNombre()== item.getNombre() ) and ( getCurrent()->getItem().getApellidos() == item.getApellidos() ) ){
	
		getCurrent()->setItem(item);
	}
	
	#ifndef NDEBUG
	// Se comprueba la postcondición
	assert( getCurrentItem() == item );
	#endif //NDEBUG
		
}


//Inserta un Estudiante de forma ordenada por apellidos y nombre
void ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::insert(ed::Estudiante const &item){
	
	ed::NodoDoblementeEnlazadoEstudiante * n;
	n=new NodoDoblementeEnlazadoEstudiante(item,NULL,NULL);

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
			
			if(item < getCurrentItem()){
				break;
			
			}

			gotoNext();
		}

		if(isFirstItem() && isLastItem()){//Si solo hay un elemento y el item a introducir ba antes se introduce este como cabeza.		
			if( item < getCurrentItem() ){
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
			if(getCurrentItem()<item){//Si es menor que el ultimo se colocora el penultimo
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
	assert(!isEmpty() and getCurrentItem()==item);
	#endif
	
}	


//Operador de asignacion entre objetos tipo ListaDoblementeEnlazadaOrdenadaEstudiantes  
ed::ListaDoblementeEnlazadaOrdenadaEstudiantes &ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::operator=(const ed::ListaDoblementeEnlazadaOrdenadaEstudiantes &l){
	
	// Se comprueba que no sean el mismo objeto
	if (this != &l){
		this->setCurrent(l.getCurrent());
		this->setHead(l.getHead());
	}
return *this;
}


//Borra el estudiante indicado por el cursor
void ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::remove(){

	
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
