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
               \brief     Constructor que crea un Vector3D nulo
               \param     N/A
               \pre       N/A
               \post      assert((get1()==0) and (get2()==0) and (get3()==0));
               \sa        set1(0),set2(0),set3(0)
          */
          Vector3D();


          /*!
               \brief     Constructor que crea un Vector3D a partir de las componentes pasadas
               \param     double v1, v2, v3 (Componentes del Vector3D)
               \pre       N/A
               \post      assert((get1()==v1) and (get2()==v2) and (get3()==v3));
               \sa        set1(0),set2(0),set3(0)
          */
          Vector3D(double v1,double v2,double v3);

          /*!
               \brief     Constructor que crea un Vector3D a partir de otro
               \param     Vector3D const &v (Objeto de la clase Vector3D)
               \pre       N/A
               \post      assert((get1()==v1) and (get2()==v2) and (get3()==v3));
               \sa        set1(0),set2(0),set3(0)
          */
          Vector3D(Vector3D const &v);

     //! \name Observadores: funciones de consulta de Vector3D

          /*!

               \brief   Función que devuelve el valor de "x" de un Vector3D
               \warning Se utiliza el modificador const en la definición de la función
               \note    Función inline
               \return  Componente "x" del Vector3D (tipo double)
               \pre     N/A
               \post    N/A
               \sa      get1(),get2(),get3()

          */
          inline double get1()const{return vector_[0];};

          /*!

               \brief   Función que devuelve el valor de "y" de un Vector3D
               \warning Se utiliza el modificador const en la definición de la función
               \note    Función inline
               \return  Componente "y" del Vector3D (tipo double)
               \pre     N/A
               \post    N/A
               \sa      get1(),get2(),get3()

          */
          inline double get2()const{return vector_[1];};

          /*!

               \brief   Función que devuelve el valor de "z" de un Vector3D
               \warning Se utiliza el modificador const en la definición de la función
               \note    Función inline
               \return  Componente "z" del Vector3D (tipo double)
               \pre     N/A
               \post    N/A
               \sa      get1(),get2(),get3()

          */
          inline double get3()const{return vector_[2];};


          /*!

               \brief   Función que devuelve el modulo del Vector3D
               \warning Se utiliza el modificador const en la definición de la función
               \return  Modulo del Vector3D (tipo double)
               \pre     N/A
               \post    assert (modulo == sqrt(get1()*get1()+get2()*get2()+get3()*get3()));
               \sa      get1(),get2(),get3()

          */
          double modulo()const;


          /*!

               \brief   Función que devuelve el angulo del Vector3D
               \warning Se utiliza el modificador const en la definición de la función
               \return  Modulo del Vector3D (tipo double)
               \pre     N/A
               \post    assert (modulo == sqrt(get1()*get1()+get2()*get2()+get3()*get3()));
               \sa      get1(),get2(),get3()

          */
          double angulo(Vector3D v)const;


          /*!

               \brief   Función que devuelve el angulo entre el vector actual con el unitario de x (1,0,0)
               \warning Se utiliza el modificador const en la definición de la función
               \return  Angulo ente (v1,v2,v3) y (1,0,0) (tipo double)
               \pre     assert(modulo()*v.modulo() > 0);
               \post    assert(angulo==acos(dotProduct(v)/(modulo()*v.modulo())));
               \sa      get1(),get2(),get3()

          */
          double alfa()const;
          double beta()const;
          double gamma()const;

          double dotProduct(Vector3D v)const;
          Vector3D crossProduct(Vector3D v)const;
          double productoMixto(Vector3D  v,Vector3D  w)const;

     //! \name Modificadores: funciones de modificación de Vector3D
          void set1(double v);
          void set2(double v);
          void set3(double v);

     //! \name Operadores de la clase
          void sumConst(double const &k);
          void sumVect(Vector3D const &v);
          void multConst(double const &k);
          void multVect(Vector3D const &v);

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
          inline Vector3D operator + ()const{

               ed::Vector3D valorDevuelto(0,0,0);

               valorDevuelto.set1(get1());
               valorDevuelto.set2(get2());
               valorDevuelto.set3(get3());

               assert(((get1()-valorDevuelto.get1())<COTA_ERROR) and
                         ((get1()-valorDevuelto.get1())<COTA_ERROR)and
                         ((get1()-valorDevuelto.get1())<COTA_ERROR));

               return valorDevuelto;

          };
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
          inline double operator * (ed::Vector3D v)const{

               double valorDevuelto = get1()*v.get1()+get2()*v.get2()+get3()*v.get3();
               assert((valorDevuelto-(get1()*v.get1()+get2()*v.get2()+get3()*v.get3())) < COTA_ERROR);
               return valorDevuelto;

          };
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

          void leerVector3D();
          void escribirVector3D()const;

};

//! \name Funciones que utilizan un objetos de la clase Vector3D, pero que no pertenecen a la clase Vector3D

     Vector3D & operator* (double k, Vector3D const & v);
     istream &operator>>(istream &stream, Vector3D &v);
     ostream &operator<<(ostream &stream, Vector3D const &v);

} // \brief Fin de namespace ed.

//  _VECTOR3D_HPP_

#endif
