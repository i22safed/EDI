/*!
   \file Vector3D.hpp
   \brief Fichero de definición de la clase Vector3D: vector libre de tres dimensiones
   \author David Sánchez Fernández
   \date     2018-03-08

*/

#ifndef _VECTOR3D_HPP_
#define _VECTOR3D_HPP_


#include <iostream>      // cout,cin,etc.
#include <cmath>         // abs
#include <cassert>       // asserts → precondiciones/postcondiciones

using std::istream;      // Uso de <<
using std::ostream;      // Uso de >>

#define COTA_ERROR   1.0e-6  // !< Cota de error para la comparación números reales



namespace ed { // Inclusión de la clase Vector3D dentro del espacio de nombres de la asigantura: ed

//!  Definición de la clase Vector3D:  \f$ \vec{v} = (v_1, v_2, v_3) = v_1 \vec{i} + v_2 \vec{j} + v_3 \vec{k} \f$
class Vector3D{

  //! \name Atributos privados de la clase Vector3D
   private:

        double vector_[3]; //!< Vector de 3 dimensiones de la clase Vector3D

   //! \name Funciones o métodos públicos de la clase Vector3D
   public:





	//! \name Constructores de la clase Vector3D

          /*!
               \fn        Vector3D()
               \brief     Constructor que crea un Vector3D nulo
               \pre       N/A
               \post      assert((get1()==0) and
                              \n (get2()==0) and
                              \n (get3()==0));
               \sa        set1(0),set2(0),set3(0)
          */
          Vector3D();





          /*!
               \fn        Vector3D(double v1,double v2,double v3)
               \brief     Constructor que crea un Vector3D a partir de las componentes pasadas
               \param     v1: Valor de la componente x del objeto Vector3D
               \param     v2: Valor de la componente y del objeto Vector3D
               \param     v3: Valor de la componente z del objeto Vector3D
               \pre       N/A
               \post      assert((get1()==v1) and
                              \n (get2()==v2) and
                              \n (get3()==v3));
               \sa        set1(0),set2(0),set3(0)
          */
          Vector3D(double v1,double v2,double v3);






          /*!

               \fn        Vector3D(Vector3D const &v)
               \brief     Constructor que crea un Vector3D a partir de otro
               \param     &v: Referencia constante de tipo Vector3D
               \pre       N/A
               \post      assert((get1()==v1) and
                              \n (get2()==v2) and
                              \n (get3()==v3));
               \sa        set1(0),set2(0),set3(0)
          */
          Vector3D(Vector3D const &v);




     //! \name Observadores: funciones de consulta de Vector3D

          /*!

               \fn      inline double get1()const
               \brief   Función que devuelve el valor de "x" de un Vector3D
               \warning Se utiliza el modificador const en la definición de la función
               \note    Función inline
               \return  Componente "x" del Vector3D (tipo double)
               \pre     N/A
               \post    N/A


          */
          inline double get1()const{return vector_[0];};






          /*!

               \fn      inline double get2()const
               \brief   Función que devuelve el valor de "y" de un Vector3D
               \warning Se utiliza el modificador const en la definición de la función
               \note    Función inline
               \return  Componente "y" del Vector3D (tipo double)
               \pre     N/A
               \post    N/A


          */
          inline double get2()const{return vector_[1];};






          /*!

               \fn      inline double get3()const
               \brief   Función que devuelve el valor de "z" de un Vector3D
               \warning Se utiliza el modificador const en la definición de la función
               \note    Función inline
               \return  Componente "z" del Vector3D (tipo double)
               \pre     N/A
               \post    N/A


          */
          inline double get3()const{return vector_[2];};






          /*!

               \fn      double modulo()const
               \brief   Función que halla el modulo del Vector3D
               \warning Se utiliza el modificador const en la definición de la función
               \return  Modulo del Vector3D (tipo double)
               \pre     N/A
               \post    assert (modulo == sqrt(get1()*get1()+get2()*get2()+get3()*get3()));


          */
          double modulo()const;







          /*!

               \fn      double angulo(Vector3D v)const
               \brief   Función que halla el angulo del Vector3D
               \param   v: Objeto de tipo Vector3D; valor por defecto v(0,0,0)
               \warning Se utiliza el modificador const en la definición de la función
               \return  Modulo del Vector3D (tipo double)
               \pre     N/A
               \post    assert (modulo == sqrt(get1()*get1()+get2()*get2()+get3()*get3()));


          */
          double angulo(Vector3D v)const;







          /*!

               \fn      double alfa()const
               \brief   Función que halla el angulo entre el vector actual con el unitario de x (1,0,0)
               \warning Se utiliza el modificador const en la definición de la función
               \return  Angulo ente (v1,v2,v3) y (1,0,0) (tipo double)
               \pre     assert(modulo()*v.modulo() > 0);
               \post    assert(angulo==acos(dotProduct(v)/(modulo()*v.modulo())));


          */
          double alfa()const;






          /*!

               \fn      double beta()const
               \brief   Función que halla el angulo entre el vector actual con el unitario de y (0,1,0)
               \warning Se utiliza el modificador const en la definición de la función
               \return  Angulo ente (v1,v2,v3) y (0,1,0) (tipo double)
               \pre     assert(modulo()*v.modulo() > 0);
               \post    assert(angulo==acos(dotProduct(v)/(modulo()*v.modulo())));


          */
          double beta()const;






          /*!

               \fn      double gamma()const
               \brief   Función que halla el angulo entre el vector actual con el unitario de z (0,0,1)
               \warning Se utiliza el modificador const en la definición de la función
               \return  Angulo ente (v1,v2,v3) y (0,0,1) (tipo double)
               \pre     assert(modulo()*v.modulo() > 0);
               \post    assert(angulo==acos(dotProduct(v)/(modulo()*v.modulo())));


          */
          double gamma()const;






          /*!

               \fn      double dotProduct(Vector3D v)const
               \brief   Función que realiza el producto escalar entre el vector actual y v
               \param   v: Objeto de tipo Vector3D; valor por defecto v(0,0,0)
               \warning Se utiliza el modificador const en la definición de la función
               \return  Valor de producto escalar del vector actual y el pasado por parametro
               \pre     N/A
               \post    (get1()*v.get1()+get2()*v.get2()+get3()*v.get3());

          */
          double dotProduct(Vector3D v)const;







          /*!

               \fn      Vector3D crossProduct(Vector3D v)const
               \brief   Función que realiza el producto vectorial entre el vector actual y v
               \param   v: Objeto de tipo Vector3D; valor por defecto v(0,0,0)
               \warning Se utiliza el modificador const en la definición de la función
               \return  Devuelve un objeto de tipo Vector3D resultado del producto vectorial
               \pre     N/A
               \post    assert(dotProduct(w)==0);
               \post    assert(v.dotProduct(w)==0);
               \post    assert (w.modulo()==modulo()*v.modulo()*sin(angulo(v)));

          */
          Vector3D crossProduct(Vector3D v)const;






          /*!

               \fn      double productoMixto(Vector3D  v,Vector3D  w)const
               \brief   Función que realiza el producto mixto entre el vector v y el w
               \param   v: Objeto de tipo Vector3D; valor por defecto v(0,0,0)
               \param   w: Objeto de tipo Vector3D; valor por defecto w(0,0,0)
               \warning Se utiliza el modificador const en la definición de la función
               \return  Devuelve el valor del producto mixto entre los dos vectores (tipo double)
               \pre     N/A
               \post    assert(dotProduct(w)==0)
               \post    assert(v.dotProduct(w)==0)
               \post    assert (w.modulo()==modulo()*v.modulo()*sin(angulo(v)));

          */
          double productoMixto(Vector3D  v,Vector3D  w)const;




     //! \name Modificadores: funciones de modificación de Vector3D



          /*!
               \fn    set1(double v);
               \brief Función que asigna un valor "v" a la coordenada "x" de un Vector3D
     		\note  Función inline
     		\param v: nuevo valor de x del Vector3D (tipo double)
     		\pre   N/A
     		\post  assert(get1()==v);

     	*/
          void set1(double v);



          /*!
               \fn    set2(double v);
               \brief Función que asigna un valor "v" a la coordenada "y" de un Vector3D
     		\note  Función inline
     		\param v: nuevo valor de y del Vector3D (tipo double)
     		\pre   N/A
     		\post  assert(get2()==v);

     	*/
          void set2(double v);



          /*!
               \fn    set3(double v);
               \brief Función que asigna un valor "v" a la coordenada "z" de un Vector3D
               \note  Función inline
               \param v: nuevo valor de z del Vector3D (tipo double)
               \pre   N/A
               \post  assert(get3()==v);

          */
          void set3(double v);

     //! \name Operadores de la clase



          /*!
               \fn    void sumConst(double const &k);
               \brief Función que suma una constante al vector actual
               \param &k: referencia del valor a sumar al vector actual (tipo: double const)
               \pre   N/A
               \post  assert((get1()==old.get1()+k) and
                         \n (get1()==old.get1()+k) and
                         \n (get2()==old.get2()+k));

          */
          void sumConst(double const &k);




          /*!
               \fn    void sumVect(Vector3D const &v);
               \brief Función que suma un vector al vector actual
               \param &v: referencia del vector a sumar al vector actual (tipo: Vector3D const)
               \pre   N/A
               \post  assert((get1()==old.get1()+v.get1()) and
                         \n (get2()==old.get2()+v.get2()) and
                         \n (get3()==old.get3()+v.get3()));

          */
          void sumVect(Vector3D const &v);




          /*!
               \fn    void multConst(double const &k);
               \brief Función que multiplica una constante al vector actual
               \param &v: referencia del vector a multiplicar al vector actual (tipo: Vector3D const)
               \pre   N/A
               \post  assert((get1()==old.get1()*k) and
                         \n (get1()==old.get1()*k) and
                         \n (get2()==old.get2()*k));

          */
          void multConst(double const &k);




          /*!
               \fn    void multVect(Vector3D const &v);
               \brief Función que multiplica un vector al vector actual
               \param &v: referencia del vector a multiplicar al vector actual (tipo: Vector3D const)
               \pre   N/A
               \post  assert((get1()==old.get1()*v.get1()) and
                         \n (get2()==old.get2()*v.get2()) and
                         \n (get3()==old.get3()*v.get3()));

          */
          void multVect(Vector3D const &v);





          /*!
               \fn        Vector3D & operator = (ed::Vector3D const &v)
               \brief     Operador de asignación: operacor que "copia" un Vector3D en otro Vector3D
               \attention Se sobrecarga el operador de asignación "="
               \note      Función inline
               \warning   Se requiere que las funciones de acceso get1(), get2() y get3() tengan el modificador const
               \param     v: objeto de tipo Vector pasado como referencia constante
               \pre       N/A
               \post      assert((this->get1() == v.get1()) and
                              \n (this->get2() == v.get2()) and
                              \n (this->get3() == v.get3()));

          */
          inline Vector3D & operator = (ed::Vector3D const &v){

              if(this != &v){

                   set1(v.get1());
                   set2(v.get2());
                   set3(v.get3());

                   assert((this->get1() == v.get1()) and
                         (this->get2() == v.get2()) and
                         (this->get3() == v.get3()));
               }

               return *this;
         };





         /*!
              \fn        inline bool operator == (ed::Vector3D const &v) const
              \brief     Operador de igualdad: compara si un Vector3D es igual a otro Vector3D
              \return    Devuelve "true" en caso de que sean iguales, y "false" en caso contrario
              \attention Se sobrecarga el operador de igualdad "=="
              \note      Función inline
              \param     v: objeto de tipo Vector pasado como referencia constante
              \pre       N/A
              \post      assert((get1()==v.get1()) and
                         \n (get2()==v.get2()) and
                         \n (get3()==v.get3()));

         */
          inline bool operator == (ed::Vector3D const &v) const{

              if((std::abs(v.get1()-this->get1())<COTA_ERROR)and
              (std::abs(v.get2()-this->get2())<COTA_ERROR)and
              (std::abs(v.get3()-this->get3())<COTA_ERROR)){

                    assert((get1()==v.get1())and
                    (get2()==v.get2())and
                    (get3()==v.get3()));

                    return true;

              }else{

                    return false;

              }

          };





          /*!
              \fn        inline Vector3D operator + (ed::Vector3D const &v)const
              \brief     Operador de suma binario: suma al vector actual el pasado por referencia
              \return    valorDevuelto: vector resultante de la operación (tipo: Vector3D)
              \attention Se sobrecarga el operador de suma binario "+"
              \note      Función inline
              \param     v: objeto de tipo Vector3D pasado como referencia constante
              \pre       N/A
              \post      assert((std::abs(valorDevuelto.get1()-get1()-v.get1()) < COTA_ERROR)
                         \n and (std::abs(valorDevuelto.get2()-get2()-v.get2()) < COTA_ERROR)
                         \n and (std::abs(valorDevuelto.get3()-get3()-v.get3()) < COTA_ERROR));

         */
          inline Vector3D operator + (ed::Vector3D const &v)const{

               ed::Vector3D valorDevuelto(0,0,0);

               valorDevuelto.set1(get1()+v.get1());
               valorDevuelto.set2(get2()+v.get2());
               valorDevuelto.set3(get3()+v.get3());

               assert((std::abs(valorDevuelto.get1()-get1()-v.get1()) < COTA_ERROR) and
                    (std::abs(valorDevuelto.get2()-get2()-v.get2()) < COTA_ERROR) and
                    (std::abs(valorDevuelto.get3()-get3()-v.get3()) < COTA_ERROR));

               return valorDevuelto;

          };





          /*!
              \fn        inline Vector3D operator + ()const
              \brief     Operador de suma unario: suma al vector actual a uno nulo
              \return    valorDevuelto: vector resultante de la operación (tipo: Vector3D)
              \attention Se sobrecarga el operador de suma unario "+"
              \note      Función inline
              \pre       N/A
              \post      assert(((get1()-valorDevuelto.get1())<COTA_ERROR) and
                              \n ((get1()-valorDevuelto.get1())<COTA_ERROR)and
                              \n ((get1()-valorDevuelto.get1())<COTA_ERROR));

         */
          inline Vector3D operator + ()const{

               ed::Vector3D valorDevuelto(0,0,0);

               valorDevuelto.set1(get1());
               valorDevuelto.set2(get2());
               valorDevuelto.set3(get3());

               assert(((get1()-valorDevuelto.get1())<COTA_ERROR) and
                         ((get2()-valorDevuelto.get2())<COTA_ERROR)and
                         ((get3()-valorDevuelto.get3())<COTA_ERROR));

               return valorDevuelto;

          };





          /*!
              \fn        inline Vector3D operator - (ed::Vector3D const &v)const
              \brief     Operador de resta binario: resta al vector actual el pasado por referencia
              \return    valorDevuelto: vector resultante de la operación (tipo: Vector3D)
              \attention Se sobrecarga el operador de suma binario "-"
              \note      Función inline
              \param     v: objeto de tipo Vector3D pasado como referencia constante
              \pre       N/A
              \post      assert((std::abs(valorDevuelto.get1()-get1()+v.get1()) < COTA_ERROR) and
                              \n (std::abs(valorDevuelto.get2()-get2()+v.get2()) < COTA_ERROR) and
                              \n (std::abs(valorDevuelto.get3()-get3()+v.get3()) < COTA_ERROR));

         */
          inline Vector3D operator - (ed::Vector3D const &v)const{

               ed::Vector3D valorDevuelto(0,0,0);

               valorDevuelto.set1(get1()-v.get1());
               valorDevuelto.set2(get2()-v.get2());
               valorDevuelto.set3(get3()-v.get3());

               assert((std::abs(valorDevuelto.get1()-get1()+v.get1()) < COTA_ERROR) and
                    (std::abs(valorDevuelto.get2()-get2()+v.get2()) < COTA_ERROR) and
                    (std::abs(valorDevuelto.get3()-get3()+v.get3()) < COTA_ERROR));

               return valorDevuelto;
          };





          /*!
              \fn        inline Vector3D operator - ()const
              \brief     Operador de resta unario: suma al vector actual a uno nulo
              \return    valorDevuelto: vector resultante de la operación (tipo: Vector3D)
              \attention Se sobrecarga el operador de suma unario "-"
              \note      Función inline
              \pre       N/A
              \post      assert(((get1()-valorDevuelto.get1())<COTA_ERROR) and
                              \n ((get1()-valorDevuelto.get1())<COTA_ERROR)and
                              \n ((get1()-valorDevuelto.get1())<COTA_ERROR));

         */
          inline Vector3D operator - ()const{

               ed::Vector3D valorDevuelto(0,0,0);

               valorDevuelto.set1(-get1());
               valorDevuelto.set2(-get2());
               valorDevuelto.set3(-get3());

               assert(((get1()-valorDevuelto.get1())<COTA_ERROR) and
                         ((get2()-valorDevuelto.get2())<COTA_ERROR)and
                         ((get3()-valorDevuelto.get3())<COTA_ERROR));

               return valorDevuelto;

          };





          /*!
              \fn        inline Vector3D operator * (double k)const
              \brief     Operador de producto prefijo: multiplica el valor
                              \n pasado a cada una de las componentes del vector
              \param     k: constante necesaria para el producto (tipo double)
              \return    valorDevuelto: vector resultante de la operación (tipo: Vector3D)
              \attention Se sobrecarga el operador de suma unario "*"
              \note      Función inline
              \pre       N/A
              \post      assert(((valorDevuelto.get1()-(get1()*k)) < COTA_ERROR) and
                              \n ((valorDevuelto.get2()-(get2()*k)) < COTA_ERROR) and
                              \n ((valorDevuelto.get3()-(get3()*k)) < COTA_ERROR));

         */
          inline Vector3D operator * (double k)const{

               ed::Vector3D valorDevuelto(0,0,0);

               valorDevuelto.set1(k*get1());
               valorDevuelto.set2(k*get2());
               valorDevuelto.set3(k*get3());

               assert(((valorDevuelto.get1()-(get1()*k)) < COTA_ERROR) and
                    ((valorDevuelto.get2()-(get2()*k)) < COTA_ERROR) and
                    ((valorDevuelto.get3()-(get3()*k)) < COTA_ERROR));

               return valorDevuelto;

          };





          /*!
              \fn        inline double operator * (ed::Vector3D v)const
              \brief     Operador de producto escalar: realiza la operación de producto escalar
                              \n del vector actual con el vector "v" pasado por referencia
              \param     v: objeto de tipo Vector3D pasado como referencia constante
              \return    valorDevuelto: resultado del producto escalar (tipo: double)
              \attention Se sobrecarga el operador "*"
              \note      Función inline;
              \pre       N/A
              \post      assert((valorDevuelto-(get1()*v.get1()+get2()*v.get2()+get3()*v.get3())) < COTA_ERROR)

         */
          inline double operator * (ed::Vector3D v)const{

               double valorDevuelto = get1()*v.get1()+get2()*v.get2()+get3()*v.get3();
               assert((valorDevuelto-(get1()*v.get1()+get2()*v.get2()+get3()*v.get3())) < COTA_ERROR);
               return valorDevuelto;

          };





          /*!
              \fn        inline double operator ^ (ed::Vector3D v)const
              \brief     Operador de producto vectorial: realiza la operación de producto vectorial
                              \n del vector actual con el vector "v"
              \param     v: objeto de tipo Vector3D pasado como referencia constante
              \return    valorDevuelto: resultado del producto vectorial (tipo: Vector3D)
              \attention Se sobrecarga el operador "^"
              \note      Función inline;
              \pre       N/A
              \post      assert(dotProduct(valorDevuelto)==0)
              \post      assert(v.dotProduct(valorDevuelto)==0)
              \post      assert(valorDevuelto.modulo() == modulo()*v.modulo()*sin(angulo(v)))

         */
          inline Vector3D operator ^ (ed::Vector3D v)const{

               ed::Vector3D valorDevuelto(0,0,0);

               valorDevuelto.set1(get2()*v.get3()-get3()*v.get2());
               valorDevuelto.set1(-get1()*v.get3()+get3()*v.get1());
               valorDevuelto.set1(get1()*v.get2()-get2()*v.get1());

               assert(dotProduct(valorDevuelto)==0);
               assert(v.dotProduct(valorDevuelto)==0);
               assert(valorDevuelto.modulo() == modulo()*v.modulo()*sin(angulo(v)));

               //valorDevuelto = crossProduct(v);

               return valorDevuelto;

          };

	//! \name Funciones lectura y escritura de la clase Vector3D




           /*!
              \fn        void leerVector3D()
              \brief     Lee desde el teclado las componentes del vector
              \pre       N/A
              \post      N/A
          */
          void leerVector3D();





          /*!
             \fn        void leerVector3D()
             \brief     Escribe por pantalla las componentes del vector
             \warning Se utiliza el modificador const en la definición de la función
             \pre       N/A
             \post      N/A
          */
          void escribirVector3D()const;

};

//! \name Funciones que utilizan un objetos de la clase Vector3D, pero que no pertenecen a la clase Vector3D





     /*!
        \fn        Vector3D & operator* (double k, Vector3D const & v)
        \brief     Operador de producto escalar postfijo: realiza la operación
                    \n de producto escalar del vector actual con el vector "v"
                    \n pasado por referencia y k
        \param     k: variable necesaria para el producto escalar (tipo double)
        \param     v: objeto de tipo Vector3D pasado como referencia constante
        \return    * valorResultado: puntero al vector resultado
        \attention Se sobrecarga el operador "*"
        \note      No pertenece a la clase Vector3D pero trabaja con objetos de ésta
        \pre       N/A
        \post      	assert((vectorResultado->get1()==k*v.get1()) and
   				    \n (vectorResultado->get2()==k*v.get2()) and
   				    \n (vectorResultado->get3()==k*v.get3()));


     */
     Vector3D & operator* (double k, Vector3D const & v);




     /*!
  		\brief      Sobrecarga del operador de entrada o lectura ">>"
					\n Lee las coordenadas del vértice separadas por espacios
		\attention  Función amiga de la clase Vector3D
		\param      stream: flujo de entrada
		\param      v Vector3D al que se le van a asignar nuevos valores.
		\pre        Ninguna
		\post       Ninguna
		\sa         operator<<
    */
     istream &operator>>(istream &stream, Vector3D &v);



     /*!
           \brief     Sobrecarga del operador de salida o escritura "<<"
                        \n Escribe por pantalla las coordenadas de un Vertice2D de la forma (x,y)
           \attention Función amiga de la clase Vertice2D
           \param     stream: flujo de salida
           \param     v: Vertice2D del cual se van a escribir sus coordenadas por pantalla
           \pre       Ninguna
           \post      Ninguna
           \sa        operator>>
     */
     ostream &operator<<(ostream &stream, Vector3D const &v);

} // \brief Fin de namespace ed.

//  _VECTOR3D_HPP_

#endif
