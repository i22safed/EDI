//Ejemplo completo de ficheros binarios

#ifndef _FUNCIONES_HPP_
#define _FUNCIONES_HPP_

#include <string>


/* Definicion del tipo DatosPersonales */

struct DatosPersonales
{
  char nombre[10];
  char apellido[10];
  int dni;
};

/* prototipos de funciones */
int menu();

bool existeFichero(std::string fichero);

void altaRegistro(std::string fichero);
void verRegistros(std::string fichero);

void buscarDNI(std::string fichero);
void borrarRegistrosNombre(std::string fichero);

void numeroRegistros(std::string fichero);

void registroNumeroI(std::string fichero);

void actualizarRegistro(std::string fichero);
int calcularNumeroRegistros(std::string fichero);
void verFichero(std::string fichero);

DatosPersonales introducirDatosPersonales(int dni);
DatosPersonales introducirNuevosDatosPersonales();
void escribirDatosPersonales(DatosPersonales aux);


void insertarRegistro(std::string fichero, DatosPersonales aux);
void modificarRegistro(std::string fichero, DatosPersonales datos, int dni);

bool buscarporDni(std::string fichero, int dni, DatosPersonales &persona);
bool borrarporNombre(std::string fichero, char *auxNombre);

DatosPersonales verRegistroNumeroI(std::string fichero, int i);


#endif

