# Estructuras de Datos e Información

### Práctica 1. Vectores libres de 3 dimensiones

#### Objetivo

Se desea codificar en C++ el tipo abstracto de datos Vector3D: vector libre de tres
dimensiones

- Importante: se codificarán, al menos, dos versiones de la clase Vector3D utilizando dos representaciones diferentes de los atributos.

Cada versión se codificará en un directorio diferente:

- version1
- version2

#### Especificación de la clase Vector3D

###### Atributos

Algunas de las posibles representaciones del vector son:
- Tres datos de tipo double.
- Array de datos de tres componentes de tipo double.
- Vector de la STL con tres componentes de datos de tipo double.

###### Constructores
- **Constructor sin argumentos**  
Vector3D() → Crea un Vector3D nulo.  
- Postcondición ```(get1()==0) and (get2()==0) and (get3()==0)```

- **Constructor parametrizado**  
Vector3D(v1, v2, v3:Real) → Crea un nuevo vector a partir de los valores
de las componentes.
- Postcondición ```(get1()==v1) and (get2()==v2) and (get3()==v3)```  

- **Constructor de copia**
Vector3D(v: Vector3D) → Crea un nuevo vector a partir de otro vector.
- Postcondición ```(get1()==v.get1())and (get2()==v.get2()) and
(get3()==v.get3())```

##### Observadores  
###### Operaciones de consulta de cada una de las componentes del vector

- **Real get1()**
Obtiene la primera componente del vector: v 1

- **Real get2()**
Obtiene la segunda componente del vector: v 2

- **Real get3()**
Obtiene la tercera componente del vector: v 3

     · Observación: en C++, estas funciones deben tener el calificador **const**

###### Módulo
Real modulo() → Calcula el módulo del vector.

· Postcondición: ```valorDevuelto == sqrt(get1()\*get1()+ get2()\*get2()+ get3()\*get3())```

###### Ángulos:

###### Ángulo
Real angulo(v: Vector3D)

###### Alfa
Real alfa()

###### Beta
Real beta()

###### Gamma
Real gamma()

##### Producto escalar
Real dotProduct(v: Vector3D)

#### Producto vectorial
Vector3D crossProduct(v: Vector3D)

#### Producto mixto
Real productoMixto(v, w:Vector3D)

####  Modificadores

##### Operaciones de modificación de cada una de las componentes del vector

###### set1(Real v)

###### set2(Real v)

###### set3(Real v)

##### sumConst(k: Real)

##### sumVect(v: Vector3D)

##### multConst(k: Real)

##### multVect(v: Vector3D)

####  Funciones de lectura y escritura

##### leerVector3D()

##### escribirVector3D()

##### Operador de igualdad Lógico operador == (v: Vector3D)

##### Operador de asignación Vector3D operador = (v: Vector3D)

##### Operador de suma “+”

##### Operador “+” unario Vector3D operador + ()

##### Operador de la resta “-” Vector3D operador - (v: Vector3D)

##### Operador “-” unario Vector3D operador - ()

##### Operador prefijo: k * vector

##### Operador postfijo: vector * k Vector3D operador * (k: Real)

##### Real operador * (v: Vector3D)

##### Producto vectorial “^” de dos vectores Vector3D operador ^ (v: Vector3D)

#### Funciones externas a la clase Vector3D

##### Operador prefijo de producto por un número real: k * vector Vector3D operator* (k: Real, v: Vector3D);

##### Vector3D & operator* (double k, Vector3D const & v);

##### Sobrecarga del operador de entrada istream &operator>>(istream &stream, Vector3D &v);

##### Sobrecarga del operador de salida ostream &operator<<(ostream &stream, Vector3D const &v);  


![](https://img.shields.io/badge/status-45%25-yellowgreen.svg)
![](https://img.shields.io/badge/compilable-yes-green.svg)
