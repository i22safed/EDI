/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.hpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author Lourdes Jimenez Bravo
	\date 9/04/2018
	\version 1.0

*/

#ifndef __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__
#define __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__

// Para comprobar las pre y post-condiciones
#include <cassert>

#include "ListaOrdenadaMunicipiosInterfaz.hpp"

#include "NodoDoblementeEnlazadoMunicipio.hpp"

#include "Municipio.hpp"

// DEBES ESPECIFICAR LAS FUNCIONES DE LA CLASE ListaDoblementeEnlazadaOrdenadaMunicipios


/*!
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos

*/
namespace ed {

/*!
  \class ListaDoblementeEnlazadaOrdenadaMunicipios
  \brief Definición de la clase ListaDoblementeEnlazadaOrdenadaMunicipios
	  	\n Lista doblemente enlazada de nodos de municipios ordenados alfabéticamente de forma ascendente
*/
  class ListaDoblementeEnlazadaOrdenadaMunicipios: public ListaOrdenadaMunicipiosInterfaz
  {
	//! \name  Atributos y métodos privados

	private:
		NodoDoblementeEnlazadoMunicipio *_head;    //!< \brief puntero al primer nodo de la lista
		NodoDoblementeEnlazadoMunicipio *_current; //!< \brief puntero al nodo current de la lista

    // \name Observadores privados

    /*!
       		\brief  Devuelve la cabeza de la lista
		      \note   Función inline
       		\return Valor del atributo _head
      */

    inline NodoDoblementeEnlazadoMunicipio * getHead() const
	{
    #ifndef NDEBUG

    assert(isEmpty()==false);

    #endif

		return this->_head;
	}

  /*!
        \brief  Devuelve el nodo indicado por el cursor de la lista
  		  \note   Función inline
        \return Valor del atributo _current
  */
	inline NodoDoblementeEnlazadoMunicipio * getCurrent() const
	{
    #ifndef NDEBUG

    assert(isEmpty()==false);

    #endif

		return this->_current;
	}

    //! \name Modificadores privados

    /*!
        	\brief  Modifica la cabeza de la lista
		      \note   Función inline
		      \param	head, que se va a convertir en la nueva cabeza de la lista
		      \post   getHead() == head
        	\return void
    */

	inline void setHead(NodoDoblementeEnlazadoMunicipio *head)
	{
		this->_head = head;

		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert(this->_head == head);
		#endif //NDEBUG
	}

  /*!
        	\brief  Devuelve el nodo current de la lista
		      \note   Función inline
		      \param	current, que se va a convertir en el nuevo nodo current de la lista
		      \post   getCurrent() == current
        	\return void
  */

    inline void setCurrent(NodoDoblementeEnlazadoMunicipio *current)
	{
		this->_current = current;

		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert(this->_current == current);
		#endif //NDEBUG
	}


	//! \name  Métodos públicos

	public:

	//! \name Constructores

    /*!
		\brief Construye una lista vacía
		\note  Función inline
		\post  isEmpty() == true
	*/
	inline ListaDoblementeEnlazadaOrdenadaMunicipios()
    {
		  // DEBES CODIFICAR ESTA FUNCIÓN
      setHead(NULL);
      setCurrent(NULL);

      #ifndef NDEBUG

      assert(isEmpty()==true);

      #endif
	}


	//! \name Destructor

    /*!
		\brief Destruye una lista liberando la memoria de sus nodos
		\post isEmpty() == true
	*/
	~ListaDoblementeEnlazadaOrdenadaMunicipios ()
     {
		  // DEBES CODIFICAR ESTA FUNCIÓN
      setHead(NULL);
      setCurrent(NULL);

      #ifndef NDEBUG
      assert(isEmpty()==true);
      #endif
     }


	//! \name Observadores públicos

	/*!
		\brief  Comprueba si la lista está vacía
		\note   Función inline
		\note   Función de tipo "const": no puede modificar al objeto actual
    \return true, si la lista está vacía; false, en caso contrario
  */
inline bool isEmpty() const
{
  		// DEBES CODIFICAR ESTA FUNCIÓN
 		// SE DEVUELVE UN VALOR ARBITRARIO PARA QUE EL CÓDIGO SE PUEDA COMPILAR
    if(this->_head==NULL)
    {
			return true;//esta vacia
		}
		else
    {
			return false;  //esta llena
		}

}

/*!
      \brief  Devuelve el número de elementos o ítems de la lista
      \warning Función de tipo "const": no puede modificar al objeto actual
      \return  Número entero que representa el número de elementos o ítems de la lista
  		\sa     isEmpty
      */

int nItems() const
{
  int numeroItem=0;
  if(isEmpty()==false)
  {
    NodoDoblementeEnlazadoMunicipio *puntero;
	  puntero=getHead();

	while (puntero!=NULL)
  { //tiene que estar llena
			puntero=puntero->getNext();
			numeroItem++;
	}
}

	return numeroItem;

}
/*!
		\brief   Comprueba si el cursor es la cabeza
		\note    Función inline
		\pre     La lista no está vacía
		\return  Verdadero, si el cursor está situado en la cabeza; falso en caso contrario
    \sa      isLastItem
*/

bool isFirstItem() const
{
    #ifndef NDEBUG
   	assert(isEmpty()==false);
   	#endif

    if(getCurrent()==getHead())
    {
      return true;
    }
    else
    {
      return false;
    }

}
/*!
		\brief   Comprueba si el cursor está en el último municipio
		\note    Función inline
		\pre     La lista no está vacía
		\return  Verdadero, si el cursor está situado al final de la lista; falso en caso contrario
    \sa     isFirstItem
*/

bool isLastItem() const
{
    #ifndef NDEBUG
   	assert(isEmpty()==false);
   	#endif

    if(getCurrent()->getNext()==NULL)
    {
      return true;
	  }
    else
    {
		  return false;
    }
}

/*!
		\brief   Devuelve el municipio situado en el campo informativo indicado por el cursor
		\pre     La lista no está vacía
		\return  Una referencia constante al municipio indicado por el cursor
*/

ed::Municipio const & getCurrentItem() const
{
    #ifndef NDEBUG
   	assert( isEmpty()==false);
   	#endif

	  return getCurrent()->getItem();
}

/*!
		\brief   Devuelve el municipio situado en el campo informativo anterior
  	\pre     La lista no está vacía
    \pre     El cursor no está en la cabeza de la lista
		\return  Una referencia al municipio situado en el nodo previo al indicado por el cursor
      */
ed::Municipio const & getPreviousItem() const
{
    #ifndef NDEBUG
   	assert( isEmpty()==false);
   	assert( isFirstItem()==false);
   	#endif

	  return getCurrent()->getPrevious()->getItem();

}
/*!
		\brief   Devuelve el municipio situado en el campo informativo posterior
  	\pre     La lista no está vacía
    \pre     El cursor no está  al final de la lista
    \return  Una referencia al municipio situado en el nodo siguiente al indicado por el cursor
*/
ed::Municipio const & getNextItem() const
{
    #ifndef NDEBUG

    assert(isEmpty()==false);
    assert(isLastItem()==false);

    #endif

    NodoDoblementeEnlazadoMunicipio *aux;
    aux-> getNext();
    return aux->getItem();
}


    //! \name Modificadores públicos

	// COMPLETAR EL RESTO DE MODIFICADORES PÚBLICOS
  /*!
  		\brief  Coloca el cursor en la primera posición de la lista
  		\pre    La lista no está vacía
      \post   firstItem() == true
  		\return void
  */
void gotoHead()
{
   	#ifndef NDEBUG
   	assert(isEmpty()==false);
   	#endif

	  setCurrent(getHead());

   	#ifndef NDEBUG
   	assert( isFirstItem()==true);
   	#endif
}

/*!
		\brief  Coloca el cursor en la última posición de la lista
    \pre    La lista no está vacía
    \post   lastItem() == true
		\return void
*/

void gotoLast()
{

   	#ifndef NDEBUG
   	assert( isEmpty()==false);
   	#endif

	  while (isLastItem()==false)
    {
		gotoNext();
	  }

   	#ifndef NDEBUG
   	assert( isLastItem()==true);
   	#endif

}


/*!
		\brief  Coloca el cursor en la posición anterior de la lista
    \pre    La lista no está vacía
		\pre    El cursor no está en la primer posición
		\return void
*/

void gotoPrevious()
{
   	#ifndef NDEBUG
   	assert( isEmpty()==false);
   	#endif

		setCurrent (getCurrent()->getPrevious());
}

/*!
		\brief  Coloca el cursor en la posición siguiente de la lista
    \pre    La lista no está vacía
  	\pre    El cursor no está en la última posición
		\return void
*/

void gotoNext()
{
   	#ifndef NDEBUG
   	assert( isEmpty()==false);
   	assert( isLastItem()==false);
   	#endif

		setCurrent (getCurrent()->getNext());
}
/*!
		\brief  Coloca el cursor en el nodo que contiene al Municipio si existe;
		\param  item: Municipio buscado
		\return true, si el Municipio está en la lista; false, en caso contrario
*/
bool find(Municipio const & item)
{
	if(isEmpty()==true)
  {
		return false;
	}

	gotoHead(); //llevo el puntero a la cabeza

	while(isLastItem()==false)
  {
		if(item ==getCurrentItem())
    {
			return true;

      #ifndef NDEBUG
   		assert( getCurrentItem()==item);
   		#endif
		}
    else
    {
			gotoNext();
		}
	}
	if(item ==getCurrentItem())
  {
		return true;

    #ifndef NDEBUG
   	assert( getCurrentItem()==item);
   	#endif
	}
  else
  {
   	return false;
	}
}
/*!
		\brief Inserta un Municipio de forma ordenada
		\param item
*/

void insert(Municipio const &item)
{
	NodoDoblementeEnlazadoMunicipio *aux = new NodoDoblementeEnlazadoMunicipio (item, NULL, NULL);

    #ifndef NDEBUG
    assert(find(item)==false);
	int n = nItems();
    #endif

	//la lista esta vacia
	//Insertar como cabeza
	if(isEmpty()==true)
  {
		setHead(aux);//Es la cabeza
		setCurrent(getHead());
	}
	else
  {//no esta vacia
    gotoHead();
		  while(isLastItem()==false)
      {
			  if(item<getCurrentItem())
        {
				  break; //Me salgo del bucle
			  }

        gotoNext();
		  }

	    if(nItems()==1)
      {
	   		if(item < getCurrentItem())
        { //va a ser la cabeza
	   			aux->setPrevious(NULL);//va a ser la cabeza
	   			aux->setNext(getCurrent());
	   			getCurrent()->setPrevious(aux);
	   			gotoPrevious(); //apunta al nuevo nodo
	   			setHead(getCurrent());//es la cabeza

	   		}
        else
        {  //insertarlo despues de la cabeza
	   		  aux->setNext(NULL);
				  aux->setPrevious(getCurrent());
				  getCurrent()->setNext(aux);
				  gotoNext();//apunta al nuevo nodo
	   		}
	   		return;
	   	}
	   	if(isFirstItem()==true)
      { //si hay que insertar el primero
				aux->setPrevious(NULL);
			  aux->setNext(getCurrent());
			  getCurrent()->setPrevious(aux);
			  gotoPrevious();
			  setHead(getCurrent());
		  }
      else if(isLastItem()==true)
      {//insertar el ultimo
			  if(getCurrentItem()<item)
        {
				  aux->setNext(NULL);
				  aux->setPrevious(getCurrent());
				  getCurrent()->setNext(aux);
				  gotoNext();
				}
        else
        { //insertar penultimo
				  aux->setPrevious(getCurrent()->getPrevious());
				  aux->setNext(getCurrent());
				  getCurrent()->setPrevious(aux);
				  gotoPrevious();
				  getCurrent()->getPrevious()->setNext(getCurrent());
				}
				return;
			//entre medias
			}
      else
      {
				aux->setPrevious(getCurrent()->getPrevious());
				aux->setNext(getCurrent());
				getCurrent()->setPrevious(aux);
				gotoPrevious();
				getCurrent()->getPrevious()->setNext(getCurrent());
			}
	}

   	#ifndef NDEBUG
    assert(getCurrentItem()==item);
   	assert(nItems()== n +1);
   	#endif
}
/*!
		\brief Borra un municipio
		\pre   La lista no está vacía
		\post  El número de municipios se reduce en uno
		\sa
*/

void remove()
{
	//precondicion  La lista no está vacía
   	#ifndef NDEBUG
   	assert( isEmpty()==false);
    int n = nItems();
   	#endif
	if(nItems()==1)
  { //SOLO HAY 1 NODO
		setHead(NULL);
		setCurrent(NULL);
	}
  else	if(isFirstItem()==true)
  { //BORRAR EL PRIMERO
		setHead(getCurrent()->getNext()); //cabeza es la siguiente
		getHead()->setPrevious(NULL); //null antes de cabeza
		getCurrent()->setNext(NULL); //elimina totalmente el nodo
		setCurrent(getHead());//apunta a la nueva cabeza

	}
  else	if(isLastItem()==true)
  {//BORRAR EL ULTIMO
		gotoPrevious();
		getCurrent()->getNext()->setPrevious(NULL); //el nodo que se quiere eliminar ya no apunta a nada
		getCurrent()->setNext(NULL);//convierte el penultimo nodo en el ultimo
	}
  else
  { //BORRAR ENTRE MEDIAS
		NodoDoblementeEnlazadoMunicipio * puntero=getCurrent();
		puntero->getPrevious()->setNext(puntero->getNext());
		puntero->getNext()->setPrevious(puntero->getPrevious());
		setCurrent(puntero->getNext());
		puntero->setNext(NULL); //elimino puntero
		puntero->setPrevious(NULL);//elimino puntero
	}

	//postcondicion
   	#ifndef NDEBUG
   	assert(nItems()==n-1);
   	#endif

}

/*!
		\brief Borra todos los municipios
		\post  La lista está vacía
*/
  void removeAll()
  {
    NodoDoblementeEnlazadoMunicipio *aux;

    gotoHead();

    while(getCurrent()->getNext() != NULL)
    {
      gotoNext();
      aux=getCurrent();
      gotoPrevious();
      remove();
      setCurrent(aux);
    }
  			remove();

        #ifndef NDEBUG
        assert(isEmpty() == true);
        #endif
  }

}; // Fin de la clase ListaDoblementeEnlazadaOrdenadaMunicipios

} //namespace ed

#endif // __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__
