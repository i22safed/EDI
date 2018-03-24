/*!
   \file Vector3D.hpp
   \brief Fichero de definición de la clase Vector3D: vector libre de tres dimensiones
*/

#ifndef _VECTOR3D_HPP_
#define _VECTOR3D_HPP_

#include <iostream>
#include <cmath>
#include <cassert>

using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación números reales



namespace ed {

//!  Definición de la clase Vector3D:  \f$ \vec{v} = (v_1, v_2, v_3) = v_1 \vec{i} + v_2 \vec{j} + v_3 \vec{k} \f$
class Vector3D
{
  //! \name Atributos privados de la clase Vector3D
   private:

	double x_, y_, z_;


   //! \name Funciones o métodos públicos de la clase Vector3D
   public:

	//! \name Constructores de la clase Vector3D

     	Vector3D();
          Vector3D(double v1,double v2,double v3);
          Vector3D(Vector3D const &v);

          inline double get1()const{return x_;};
          inline double get2()const{return y_;};
          inline double get3()const{return z_;};


          double modulo()const;

          double angulo(Vector3D v)const;

          double alfa()const;

          double beta()const;

          double gamma()const;

          double dotProduct(Vector3D v)const;

          Vector3D crossProduct(Vector3D v)const;

          double productoMixto(Vector3D  v,Vector3D  w)const;

          void set1(double v);

          void set2(double v);

          void set3(double v);

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

             ed::Vector3D valorDevuelto(0.0,0.0,0.0);

             valorDevuelto.set1(get1()+v.get1());
             valorDevuelto.set2(get2()+v.get2());
             valorDevuelto.set3(get3()+v.get3());

             assert((std::abs(valorDevuelto.get1()-get1()-v.get1()) < COTA_ERROR) and
                 (std::abs(valorDevuelto.get2()-get2()-v.get2()) < COTA_ERROR) and
                 (std::abs(valorDevuelto.get3()-get3()-v.get3()) < COTA_ERROR));

             return valorDevuelto;

        };

        inline Vector3D operator + ()const{

            ed::Vector3D valorDevuelto(0.0,0.0,0.0);

            valorDevuelto.set1(get1());
            valorDevuelto.set2(get2());
            valorDevuelto.set3(get3());

            assert(((get1()-valorDevuelto.get1())<COTA_ERROR) and
                       ((get2()-valorDevuelto.get2())<COTA_ERROR)and
                       ((get3()-valorDevuelto.get3())<COTA_ERROR));

            return valorDevuelto;

        };

        inline Vector3D operator - (ed::Vector3D const &v)const{

            ed::Vector3D valorDevuelto(0.0,0.0,0.0);

            valorDevuelto.set1(get1()-v.get1());
            valorDevuelto.set2(get2()-v.get2());
            valorDevuelto.set3(get3()-v.get3());

            assert((std::abs(valorDevuelto.get1()-get1()+v.get1()) < COTA_ERROR) and
                  (std::abs(valorDevuelto.get2()-get2()+v.get2()) < COTA_ERROR) and
                  (std::abs(valorDevuelto.get3()-get3()+v.get3()) < COTA_ERROR));

            return valorDevuelto;
        };

        inline Vector3D operator - ()const{

            ed::Vector3D valorDevuelto(0.0,0.0,0.0);

            valorDevuelto.set1(-get1());
            valorDevuelto.set2(-get2());
            valorDevuelto.set3(-get3());

            assert(((get1()+valorDevuelto.get1())<COTA_ERROR) and
                       ((get2()+valorDevuelto.get2())<COTA_ERROR)and
                       ((get3()+valorDevuelto.get3())<COTA_ERROR));

            return valorDevuelto;

        };

        inline Vector3D operator * (double k)const{

            ed::Vector3D valorDevuelto(0.0,0.0,0.0);

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

            ed::Vector3D valorDevuelto(0.0,0.0,0.0);

            valorDevuelto.set1(get2()*v.get3()-get3()*v.get2());
            valorDevuelto.set1(-get1()*v.get3()+get3()*v.get1());
            valorDevuelto.set1(get1()*v.get2()-get2()*v.get1());

            assert(dotProduct(valorDevuelto)==0);
            assert(v.dotProduct(valorDevuelto)==0);
            assert(valorDevuelto.modulo() == modulo()*v.modulo()*sin(angulo(v)));

            //valorDevuelto = crossProduct(v);

            return valorDevuelto;

        };

        void leerVector3D();

        void escribirVector3D()const;



}; // Fin de la definición de la clase Vector3D


         Vector3D & operator* (double k, Vector3D const & v);

         istream &operator>>(istream &stream, Vector3D &v);

         ostream &operator<<(ostream &stream, Vector3D const &v);


} // \brief Fin de namespace ed.

//  _VECTOR3D_HPP_
#endif
