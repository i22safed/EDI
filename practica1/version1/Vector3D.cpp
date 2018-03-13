/*!

   \file Vector3D.cpp
   \brief Fichero que contiene el código de las funciones de la clase Vector3D
   \date     2018-03-08
   \author   David Sánchez Fernandez

*/

#include <iostream>		// cout,cin,etc.
#include <cmath>		// Uso sqrt, acos
#include <cassert>		// asserts → precondiciones/postcondiciones

#include "Vector3D.hpp"	// Inclusión de las cabeceras

// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{

	ed::Vector3D::Vector3D(){

		set1(0.0);
		set2(0.0);
		set3(0.0);
		assert((get1()==0) and (get2()==0) and (get3()==0));

	}

	ed::Vector3D::Vector3D(double v1,double v2,double v3){

		set1(v1);
		set2(v2);
		set3(v3);
		assert((get1()==v1) and (get2()==v2) and (get3()==v3));

	}

	ed::Vector3D::Vector3D(ed::Vector3D const &v){

		vector_[0]=v.vector_[0];
		vector_[1]=v.vector_[1];
		vector_[2]=v.vector_[2];
		assert((get1()==v.get1()) and (get2()==v.get2()) and (get3()==v.get3()));

	}

	double ed::Vector3D::modulo()const{

		double modulo = sqrt(get1()*get1()+get2()*get2()+get3()*get3());
		assert (modulo == sqrt(get1()*get1()+get2()*get2()+get3()*get3()));
		return modulo;

	}

	double ed::Vector3D::angulo(ed::Vector3D v)const{

		assert(modulo()*v.modulo() > 0);

		double angulo = acos(dotProduct(v)/(modulo()*v.modulo()));

		if(angulo > 1){
			angulo = 1;
		}
		if(angulo < -1){
			angulo = -1;
		}
		if(angulo > -1 and angulo < 1){

			assert((angulo == acos(dotProduct(v)/(modulo()*v.modulo()))) );

		}

		return angulo;

	}

	double ed::Vector3D::alfa()const{

		assert(modulo() > 0);
		double anguloAlfa=(angulo(Vector3D(1,0,0)));
		assert(std::abs(anguloAlfa-angulo(Vector3D(1,0,0)))<COTA_ERROR);
		return anguloAlfa;

	}

	double ed::Vector3D::beta()const{

		assert(modulo()>0);
		double anguloBeta=(angulo(Vector3D(0,1,0)));
		assert(std::abs(anguloBeta-angulo(Vector3D(0,1,0)))<COTA_ERROR);
		return anguloBeta;

	}

	double ed::Vector3D::gamma()const{

		assert(modulo() > 0);
		double anguloGamma=(angulo(Vector3D(0,0,1)));
		assert(std::abs(anguloGamma-angulo(Vector3D(0,0,1)))<COTA_ERROR);
		return anguloGamma;

	}

	double ed::Vector3D::dotProduct(ed::Vector3D v)const{

		double pdtoEscalar = (get1()*v.get1()+get2()*v.get2()+get3()*v.get3());
		assert(std::abs(pdtoEscalar-(get1()*v.get1()+get2()*v.get2()+get3()*v.get3()))<COTA_ERROR);
		return pdtoEscalar;

	}

	Vector3D ed::Vector3D::crossProduct(ed::Vector3D v)const{

		ed::Vector3D w(0.0,0.0,0.0);

		w.vector_[0] = vector_[2]*v.vector_[3] - vector_[3]*v.vector_[2];
		w.vector_[1] = -vector_[1]*v.vector_[3] + vector_[3]*v.vector_[1];
		w.vector_[2] = vector_[1]*v.vector_[2] - vector_[2]*v.vector_[1];

		std::cout << "El valor de dotProduct<" << dotProduct(w) << ">";
		assert(std::abs(dotProduct(w))< COTA_ERROR);
		assert(std::abs(v.dotProduct(w)) < COTA_ERROR);
		assert (std::abs(w.modulo()-(modulo()*v.modulo()*sin(angulo(v))))<COTA_ERROR);

		return w;

	}

	double ed::Vector3D::productoMixto(ed::Vector3D  v,ed::Vector3D  w)const{

		double pdtoMixto = dotProduct(v.crossProduct(w));
		assert(pdtoMixto == dotProduct(v.crossProduct(w)));
		return pdtoMixto;

	}


	void ed::Vector3D::set1(double v){

		vector_[0] = v;
		assert(get1()==v);

	}

	void ed::Vector3D::set2(double v){

		vector_[1] = v;
		assert(get2()==v);

	}

	void ed::Vector3D::set3(double v){

		vector_[2] = v;
		assert(get3()==v);

	}

	void ed::Vector3D::sumConst(double const &k){

		ed::Vector3D old(vector_[0],vector_[1],vector_[2]);

		vector_[0]+=k;
		vector_[1]+=k;
		vector_[2]+=k;

		assert((get1()==old.get1()+k) and
				(get1()==old.get1()+k) and
				(get2()==old.get2()+k));

	}

	void ed::Vector3D::sumVect(ed::Vector3D const &v){

		ed::Vector3D old(vector_[0],vector_[1],vector_[2]);

		vector_[0]+=v.vector_[0];
		vector_[1]+=v.vector_[1];
		vector_[2]+=v.vector_[2];

		assert((get1()==old.get1()+v.get1()) and
				(get2()==old.get2()+v.get2()) and
				(get3()==old.get3()+v.get3()));

	}

	void ed::Vector3D::multConst(double const &k){

		ed::Vector3D old(vector_[0],vector_[1],vector_[2]);

		vector_[0]*=k;
		vector_[1]*=k;
		vector_[2]*=k;

		assert((get1()==old.get1()*k) and
				(get1()==old.get1()*k) and
				(get2()==old.get2()*k));

	}

	void ed::Vector3D::multVect(ed::Vector3D const &v){

		ed::Vector3D old(vector_[0],vector_[1],vector_[2]);

		vector_[0]*=v.vector_[0];
		vector_[1]*=v.vector_[1];
		vector_[2]*=v.vector_[2];

		assert((get1()==old.get1()*v.get1()) and
				(get2()==old.get2()*v.get2()) and
				(get3()==old.get3()*v.get3()));

	}

	ed::Vector3D & operator* (double k, ed::Vector3D const & v){

		ed::Vector3D * vectorResultado = new ed::Vector3D();

		vectorResultado->set1(k*v.get1());
		vectorResultado->set2(k*v.get2());
		vectorResultado->set3(k*v.get3());

		assert((vectorResultado->get1()==k*v.get1()) and
				(vectorResultado->get2()==k*v.get2()) and
				(vectorResultado->get3()==k*v.get3()));

		return *vectorResultado;
	}

	void ed::Vector3D::leerVector3D(){

		double x, y, z;

		std::cout << "Valor de x → ";
		std::cin >> x;
		std::cout << "Valor de y → ";
		std::cin >> y;
		std::cout << "Valor de z → ";
		std::cin >> z;

		this->set1(x);
		this->set2(y);
		this->set3(z);


	}

	void ed::Vector3D::escribirVector3D()const{

		std::cout << "(" << this->get1() << ", " << this->get2() << ", " << this->get3() << ")" << std::endl;

	}

	ostream &operator<<(ostream &o, ed::Vector3D const &v){

		o << "(" << v.get1() << "," << v.get2() << "," << v.get3() << ")";

		return o;

	}

	istream &operator>>(istream &i, ed::Vector3D &v){

		double v1,v2,v3;

		std::cout << "Introduce valores para (a, b, c): ";
	   	i >> v1 >> v2 >> v3;
		i.ignore();

		v.set1(v1);
		v.set2(v2);
		v.set3(v3);

	   	return i;

	}

} // Fin del espacio de nombres ed
