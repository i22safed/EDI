OBJETOS = principalPoligono2D.o funcionesAuxiliares.o poligono2D.o vertice2D.o 
CPPFLAGS = -c -g -Wall -ansi

objetivo: principalPoligono2D.exe

#Opciones para NO depurar
ndebug: CPPFLAGS += -DNDEBUG 
ndebug: objetivo

#Para general a documentacion
doc: Doxyfile 
		doxygen

principalPoligono2D.exe: $(OBJETOS)
					g++ -o principalPoligono2D.exe $(OBJETOS)

principalPoligono2D.o: principalPoligono2D.cpp funcionesAuxiliares.hpp poligono2D.hpp poligono2DInterfaz.hpp vertice2D.hpp vertice2DInterfaz.hpp 
					g++ $(CPPFLAGS) principalPoligono2D.cpp 

funcionesAuxiliares.o: funcionesAuxiliares.cpp funcionesAuxiliares.hpp poligono2D.hpp poligono2DInterfaz.hpp vertice2D.hpp vertice2DInterfaz.hpp funcionesAuxiliares.hpp
					g++ $(CPPFLAGS) funcionesAuxiliares.cpp 

poligono2D.o: poligono2D.cpp  poligono2D.hpp poligono2DInterfaz.hpp vertice2D.hpp vertice2DInterfaz.hpp
					g++ $(CPPFLAGS) poligono2D.cpp 

vertice2D.o: vertice2D.cpp vertice2D.hpp vertice2DInterfaz.hpp
					g++ $(CPPFLAGS) vertice2D.cpp   

  

.PHONY: clean  
clean:
	rm -f $(OBJETOS) *~ 
