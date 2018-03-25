/*! 
  \file poligono2D.cpp
  \brief Fichero de código de la clase Poligono2D: polígono de vértices del plano euclídeo. Implementación basada en una lista de STL
*/

// Ficheros de cabecera

#include "poligono2D.hpp"

ed::Vertice2D const &ed::Poligono2D::getVertice2D (const unsigned int &indice)const{

	#ifndef NDEBUG
	assert ((indice >= 0) and (indice < (unsigned int)this->numeroVerticesPoligono()));
	#endif //NDEBUG
	
	std::list<ed::Vertice2D>::const_iterator it;
	unsigned int contador=0;
	for(it = v_.begin(); it != v_.end(); it++){
		
		if(contador==indice){break;}
		
		contador++;
	}
	return (*it);
}

ed::Vertice2D const &ed::Poligono2D::operator [] (const int indice){

	#ifndef NDEBUG
	assert ((indice >= 0) and (indice < this->numeroVerticesPoligono()));
	#endif //NDEBUG
	
	std::list<ed::Vertice2D>::const_iterator it;
	int contador=0;
	for(it=v_.begin(); it!=v_.end();it++){
		
		if(contador==indice){break;}
		
		contador++;
	}
	
	return (*it);
}	

void ed::Poligono2D::borrarVertice (int indice){
	int i=0;
	std::list <ed::Vertice2D>::iterator it;

	for (it=v_.begin(); it!=v_.end(); it++,i++){
		
		if(i==indice){
			v_.erase(it);
			return;
		}
	}

		
}

ed::Poligono2D const &ed::Poligono2D::operator = (const ed::Poligono2D &q){

	v_=q.v_;
	return *this;
}

bool const ed::Poligono2D::operator == (const ed::Poligono2D &q){

	if (v_==q.v_){return true;}
	else{return false;}	
	
}

void ed::Poligono2D::leePoligono (){
	
	int num,i;
	double x,y;
	ed::Vertice2D vertice;
	std::cout<<"Introduce el numero de vertices:"<<std::endl;
	std::cin>>num;
	
	for(i=0;i<num;i++){
		std::cout<<"Vertice "<<i<<":"<<std::endl<<"Introduce la coordenada X:"<<std::endl;
		std::cin>>x;
		std::cout<<"Introduce la coordenada Y:"<<std::endl;
		std::cin>>y;
		vertice.setX(x);
		vertice.setY(y);
		v_.push_back(vertice);
	}
}

void ed::Poligono2D::escribePoligono(ed::Poligono2D &poligono){
	
	int i=0;
	std::list<ed::Vertice2D>::iterator it;
	
	for(it=poligono.v_.begin();it!=poligono.v_.end();it++){
	
		std::cout<<"Vertice "<<i<<":"<<std::endl;
		std::cout<<"X: "<<it->getX()<<std::endl;
		std::cout<<"Y: "<<it->getY()<<std::endl;
		i++;
	}
}

void ed::Poligono2D::cargarPoligono(std::string nomfich){
	double x,y;
	ed::Vertice2D vertice;
	std::ifstream f(nomfich.c_str());
	while (f>>x>>y){ 
		
		vertice.setX(x);
		vertice.setY(y);
		v_.push_back(vertice);
	}
	f.close();
}

void ed::Poligono2D::grabarPoligono(std::string nomfich){

	ed::Vertice2D vertice;
	std::ofstream f(nomfich.c_str());
	
	std::list<ed::Vertice2D>::iterator it;

	for(it=v_.begin();it!=v_.end();it++){ f<<it->getX()<<" "<<it->getY()<<std::endl;}
	
	f.close();
}

ed::Vertice2D ed::Poligono2D::centroidePoligono(){

	double sumaX=0,sumaY=0;
	double numVertices=0;
	ed::Vertice2D vertice;
	std::list<Vertice2D>::iterator it;
	for(it=v_.begin();it!=v_.end();it++){
		sumaX += it->getX();
		sumaY += it->getY();
		numVertices++;
	}
	vertice.setX(sumaX/numVertices);
	vertice.setY(sumaY/numVertices);
	return vertice;	
}

double ed::Poligono2D::perimetroPoligono(){

	int i;
	double perimetro=0;
	int tam=v_.size();
	for(i=0;i<tam;i++){
	
		perimetro += sqrt( pow( getVertice2D((i+1)%tam).getX() - getVertice2D(i).getX(),2) + pow( getVertice2D((i+1)%tam).getY() - getVertice2D(i).getY(),2)   );
	}
	
	return perimetro;
}

double ed::Poligono2D::areaPoligono(){

	 int i;
	int tam=v_.size();
	double suma_auxiliar=0.0;
	double area;
	
	for(i=0;i<tam;i++){
	    if(i+1 == tam)
	    {
	    	suma_auxiliar += getVertice2D(i).getX() * 
		                 ( getVertice2D(0).getY() - getVertice2D((i-1)%tam).getY() );
		                 
		
            }
          else if(i-1 < 0) 
            {
		suma_auxiliar += getVertice2D(i).getX() * 
		                ( getVertice2D((i+1)%tam).getY() - getVertice2D(tam-1).getY() );
		                
             
            }		                
          else
            {
          	suma_auxiliar +=getVertice2D(i).getX() * 
		                (getVertice2D((i+1)%tam).getY() - getVertice2D((i-1)%tam).getY() );
            }

	}
	
	area= fabs(suma_auxiliar/2.0);
	
	
	return area;
}
